#include<iostream>
#include<memory>
using namespace std;
void change(unique_ptr<int>* ptr){
	*ptr=make_unique<int>(300);
	cout<<"Address of double ptr"<<ptr<<endl;//stack
	cout<<"Address of content of double ptr"<<(*ptr).get()<<endl;
}
int main()
{
	unique_ptr<int>p=make_unique<int>(42);
	cout<<"&unique_ptr"<<" "<<&p<<endl;//stack segment
	cout<<"Content in Unique_ptr"<<" "<<p.get()<<endl;//Heap segment
	change(&p);
}
