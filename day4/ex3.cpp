#include<iostream>
#include<memory>
using namespace std;
void change(int *p){
	if(p){
		*p=100;
		cout<<"Address of p inside function"<< p<<endl;
	}
}
void api(unique_ptr<int>&& p1){
	cout<<"In API Function"<<endl;
	cout<<"Address of p1 in function "<<&p1<<endl;
}
void api1(unique_ptr<int>p2){

cout<<"Address of p2 in api2 function"<<&p2<<endl;

}
int main()
{

	unique_ptr<int>p=make_unique<int>(10);
	unique_ptr<int>p1=make_unique<int>(42);
	cout<<"Address of unique_pointer "<<p.get()<<endl;
	cout<<"Address of Unique_pointer(p) in main "<<&p<<endl;
	cout<<"Address of p1 in main"<<&p1<<endl;
	change(p.get());
	if(p){
		cout<<"unique_ptr is still holding resouce"<<endl;
	}
	else{
		cout<<"Not Holding Resouce"<<endl;
	}
	p.reset(new int(200));
	api(move(p));
	api1(move(p1));
//	cout<<*p<<endl;

}
