#include<iostream>
#include<utility>
using namespace std;
class A
{
	int value;
	int *ptr;
	public:
	A(int data=0,int * res=nullptr):value(data),ptr(res){}
	A(const A& other)
	{
		cout<<"Copy Constructor Called"<<endl;
		value=other.value;
		ptr=new int(*other.ptr);
	}
	A&operator=(const A &other){
		cout<<"Copy Assignment Opeartor Called"<<endl;
		if(this!=&other)
		{
			value=other.value;
			delete ptr;
			ptr=new int(*other.ptr);
		}
		return *this;

	}
	A(A&& other) {
	cout<<"Move Constructor Is Called"<<endl;
	value=other.value;
	ptr=new int (*other.ptr);
	other.ptr=nullptr;

	}
	A operator=(const A&& other){
		cout<<"Move Copy Assigment is Called"<<endl;
		if(this!=&other){
			value=other.value;
			delete ptr;
			ptr=new int(*other.ptr);
		}
		return *this;
	}
	~A(){
		cout<<"Destructor Is Called"<<endl;
		delete ptr;
	}
	void display()
	{
		cout<<"Value"<<endl;

	}

};
int main()
{

	A a1(10,new int[5]);
	A a2(20,new int[10]);
	A a3=a2;//copy constructor is called
	a2=a1;//copy assigment opeartor is called
	A a4=move(a2);
	a2.display();

}
