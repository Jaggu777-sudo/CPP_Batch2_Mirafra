#include<iostream>
#include<memory>
using namespace std;
class Temp{
	public:
	int data;
	Temp(int val):data(val){}
	void show(){
	cout<<"Display The Temp: "<<data<<endl;
	}
};
void change(shared_ptr<Temp>&p){
p->data=100;
}
int main(){
	shared_ptr<Temp>s=make_shared<Temp>(42);
	s->show();
	cout<<s.use_count()<<endl;;
	shared_ptr<Temp>s1=s;
	change(s1);
	s->show();
	s1->show();
	
}
