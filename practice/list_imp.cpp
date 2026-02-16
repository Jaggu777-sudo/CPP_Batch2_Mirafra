#include<iostream>
using namespace std;
template<typename T>
class mylist{
	public:
		struct Node{
			Node *prev;
			int data;
			Node *next;
			Node(){}
			Node(int val):data(val),prev(nullptr),next(nullptr){}
		};
		Node *head,*tail;
		mylist(){
			head=nullptr;
			tail=nullptr;
		}
		~mylist(){
			while(head){
				pop_front();
			}
		}
		mylist(std::initializer_list<T>l):head(nullptr),tail(nullptr){
			for(const auto&x:l){
				push_back(x);
			}
		}
		mylist(const mylist& other):head(nullptr),tail(nullptr){
			Node* temp=other.head;
			while(temp){
				push_back(temp->data);
				temp=temp->next;
			}
		}
		mylist(mylist&&other)noexcept{
			head=other.head;
			tail=other.tail;
			other.head=other.tail=nullptr;
		}
		mylist& operator=(const mylist&other){
			if(this==&other)
				return *this;
			while(head)
				pop_front();
			Node *temp=other.head;
			while(temp){
				push_back(temp->data);
				temp=temp->data;
			}
			return *this;
		}
		mylist& operator=(mylist&&other)noexcept{
			if(this==&other)
				return *this;
			while(head)
				pop_front();
			head=other.head;
			tail=other.tail;
			other.head=other.tail=nullptr;
			return *this;
		}
		void push_front(int val){
			Node *new_node=new Node(val);
			if(!head){
				head=tail=new_node;
			}
			else{
				new_node->next=head;
				head->prev=new_node;
				head=new_node;
			}
		}
		void push_back(int val){
			if(!head){
				push_front(val);
				return;
			}
			Node *new_node=new Node(val);
			tail->next=new_node;
			new_node->prev=tail;
			tail=new_node;
		}
		void pop_front(){
			if(!head)
				return;
			Node* temp=head;
			if(head->next){
				head=head->next;
				head->prev=nullptr;
			}
			else{
				head=tail=nullptr;
			}
			delete temp;
		}
		void pop_back(){
			if(!head)
				return ;
			Node* temp=tail;
			if(head==tail){
				head=tail=nullptr;
			}
			else{
				tail=tail->prev;
				tail->next=nullptr;
			}
			delete temp;
		}
		T& front(){
			return head->data;
		}
		class iterator{
			Node* ptr;
			public:
			iterator(Node* p):ptr(p){
			}
			T& operator*(){ 
			return ptr->data; }
			iterator& operator++(){ 
			ptr=ptr->next; return *this; }
			bool operator!=(const iterator& other)const{
				return ptr!=other.ptr;
			}
		};

		iterator begin(){ return iterator(head); }
		iterator end(){ return iterator(nullptr); }

		bool empty()const{
			return head==nullptr;
		}
};
int main(){

	mylist<int>l1;
	mylist<int>l2={1,2,3,4,5,6};
	mylist<int>l3(l2);
	l1.push_front(30);
	l1.push_front(20);
	l1.push_front(10);
	l1.push_back(40);
	l1.push_back(50);
	mylist<int>l4=move(l1);
	for(const auto& x:l4){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}

