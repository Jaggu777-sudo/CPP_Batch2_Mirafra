#include<iostream>
using namespace std;
template<typename T>
class unique_ptr{

	private:
		T *ptr;
	public:
		unique_ptr(T *res=nullptr):ptr(res){
			cout<<"constructor called"<<endl;
		}
		unique_ptr(const unique_ptr& other)=delete;
		unique_ptr& operator=(const unique_ptr&other)=delete;
		unique_ptr(unique_ptr&&other){
			cout<<"Move Constructor Called"<<endl;
			ptr=other.ptr;
			other.ptr=nullptr;
		}
		unique_ptr& operator=(unique_ptr&&other){

			if(this!=&other){
				delete ptr;
				ptr=other.ptr;
				other.ptr=nullptr;
			}
			return *this;
		}
		T * operator ->(){
			return ptr;

		}
		T& operator *(){
			return *ptr;

		}
		T* get()
		{

			return ptr;
		}
		void reset(T* res=nullptr){
		if(!ptr)
		ptr=res;
		}
		
};
class Test{
	public:
		void get_data()
		{
			cout<<"Test"<<endl;

		}
};
int main()
{

	unique_ptr<Test>p(new Test());
	p->get_data();
	Test *ptr=p.get();
	p.reset(new Test());
}
