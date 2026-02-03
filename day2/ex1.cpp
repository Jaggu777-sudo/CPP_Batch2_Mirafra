#include<iostream>
#include<memory>
using namespace std;
class Temp
{
	public:
		int data;
		Temp(int value=0){
			data=value;
			cout<<"Temp objected is created"<<endl;
		}
		~Temp(){
			cout<<"Temp Objected Is Destroyed"<<endl;
		}

		void display()const{
			cout<<"Display Temperature Details"<<endl;
			cout<<"Temp Data:"<<data<<endl;

		}
};

void API(Temp *ptr){
cout<<"API is Called"<<endl;
ptr->data=ptr->data+1000;
//delete ptr;
}
int main()
{
	unique_ptr<Temp>p1=make_unique<Temp>(100);
	p1->display();
	unique_ptr<Temp>p2=move(p1);
	if(!p1){
		cout<<"p1 is deleted"<<endl;
	}
	p2.reset(new Temp(200));//reset the pointer with newly allocated
	Temp* raw_ptr=p2.release();//release the ownership means(does not destroy the resource)
	if(!p2){
	cout<<"p2 become nullptr"<<endl;
	}
	raw_ptr->display();
	unique_ptr<Temp>p3=make_unique<Temp>(300);
	Temp *raw_ptr1=p3.get();//get the raw pointer without releasing the ownership
	API(raw_ptr1);
	if(p3){
	cout<<"P3 has ownership"<<endl;
	}
	raw_ptr1->display();
	p3->display();
}
