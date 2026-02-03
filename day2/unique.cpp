#include<iostream>
using namespace std;
template<typename T>
class unique_ptr{
	T *ptr;
	public:
	unique_ptr(T *res=nullptr):ptr(res){
		cout<<"Unique ptr constructor called"<<endl;}
	~unique_ptr(){
		delete ptr;
		cout<<"Unique_ptr destructor called"<<endl;
	}
	unique_ptr(unique_ptr&other)=delete;
	unique_ptr & operator =(const unique_ptr&other)=delete;
	T & operator *(){
		return *ptr;
	}
	T* operator ->(){
		return ptr;
	}
	T * release(){
		T *temp=ptr;
		delete ptr;
		return temp;

	}
	void reset (T *res=nullptr){
		delete ptr;
		ptr=res;

	}


};
class B
{
	public:
		B(){
			cout<<"B obj created"<<endl;
		}
		~B(){
			cout<<"B obj destroyed"<<endl;
		}
		void greet()
		{
			cout<<"Welcome To Training Day2"<<endl;
		}
};
int main()
{
	unique_ptr<B>p1(new B());
	p1->greet();
	B* p2=p1.release();
	p2->greet();
}


