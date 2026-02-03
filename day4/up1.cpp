#include<iostream>
#include<memory>
using namespace std;
class B;
class A{
	public:
	unique_ptr<B>p;
	//public:
	A():p(make_unique<B>()){}
	void display(){
		cout<<&p<<endl;
	}

};
class B{
public:
B(){

cout<<"Constructor Is called"<<endl;
}
void show(){

cout<<"in B class"<<endl;
}

};
int main()
{
	A a;
	a.display();
	A a1=std::move(a);
	a.display();
	a.p->show();
}
