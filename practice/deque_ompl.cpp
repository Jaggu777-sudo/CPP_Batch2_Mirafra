#include<iostream>
using namespace std;
template<typename T>
class mydeque{
	static const int block_size;
	static int table_size;
	T** block_table;
	int start_block;
	int end_block;
	int start_offset;
	int end_offset;
	int current_size;
	public:
	mydeque(){
		block_table=new T*[table_size];
		for(int i=0;i<table_size;i++){
			block_table[i]=nullptr;
		}
		start_block=end_block=(table_size)/2;
		start_offset=end_offset=current_size=0;
	}
	void push_front(int val){
		if(start_offset>0)
			start_offset--;
		else{
			if(start_block==0){
				realloc();
			}
			start_block--;
			block_table[start_block]=new T[block_size];
			start_offset=block_size-1;
		}
		block_table[start_block][start_offset]=val;
		current_size++;
	}
	void push_back(int val){
		if(end_offset==block_size)
		{
			end_block++;
			if(end_block==table_size){
				realloc();
			}
			block_table[end_block][end_offset++]=val;
			current_size++;
		}
	}
	void pop_front(){
		if(current_size==0)
			return ;
		start_offset++;
		if(start_offset==block_size)
		{
			start_block++;
			start_offset=0;
		}
		current_size--;
	}
	void pop_back(){
		if(current_size==0)
			return;
		if(end_offset>0)
			end_offset--;
		else{
			end_block--;
			end_offset=block_size-1;
		}
		current_size--;
	}
	int size()const{
		return current_size;
	}
	int& operator[](int index){
		int total_offset=start_offset+index;
		int block=start_block+(total_offset/block_size);
		int offset=total_offset%block_size;
		return block_table[block][offset];
	}
	void realloc(){
		T** new_block_table=new T*[table_size*2];
		int new_start_block=(table_size/2)-(end_block-start_block)/2;
		int new_end_block=new_start_block+(end_block-start_block);
		for(int i=0;i<table_size*2;i++){
			new_block_table[i]=nullptr;
		}
		int j=new_start_block;
		for(int i=start_block;i<=end_block;i++){
			new_block_table[j++]=block_table[i];
		}
		delete []block_table;
		block_table=new_block_table;
		start_block=new_start_block;
		end_block=new_end_block;
		table_size=table_size*2;
	}
	mydeque(std::initializer_list<T> l) {
		block_table = new T*[table_size];

		for(int i = 0; i < table_size; i++)
			block_table[i] = nullptr;

		start_block = end_block = table_size / 2;
		start_offset = end_offset = 0;
		current_size = 0;

		block_table[start_block] = new T[block_size];

		for(const auto& x : l) {
			block_table[end_block][end_offset++] = x;
			current_size++;

			if(end_offset == block_size) {
				end_block++;

				if(end_block == table_size) {
					realloc();
				}

				block_table[end_block] = new T[block_size];
				end_offset = 0;
			}
		}
	}
	T* end() {
    int total_offset = start_offset + current_size;
    int block = start_block + (total_offset / block_size);
    int offset = total_offset % block_size;
    return &block_table[block][offset];
}
	T* begin(){
		return &block_table[start_block][start_offset];
		}

};
template<typename T>
const int mydeque<T>::block_size=4;
template<typename T>
int mydeque<T>::table_size=4;
int main(){
	mydeque<int>dq={1,2,3,4,5,6,7,8,9,10};
	for(const auto&x:dq){
	cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}

