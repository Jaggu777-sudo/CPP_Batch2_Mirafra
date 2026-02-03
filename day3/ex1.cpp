#include<iostream>
#include<memory>
using namespace std;
class GPIO{
	public:
	bool pin;
	GPIO(bool s=false){
		pin=s;
		cout<<"GPIO Constructor is called"<<endl;
	}



};
class GPIO_Del
{
	public:
		void operator()(GPIO *r){
				if(!r->pin)
				cout<<"Resource IS Released"<<endl;
				else
				cout<<"Resource IS Not Released"<<endl;
		}


};
int main()
{

	//unique_ptr<GPIO,GPIO_Del>p(new GPIO(),GPIO_Del());
	unique_ptr<GPIO,GPIO_Del>p1=make_unique<GPIO,GPIO_Del>(true,GPIO_Del());

}
