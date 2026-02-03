#include<iostream>
#include<cstring>
using namespace std;
class Gpio
{
	int pin;
	char *ptr;
	public:
	Gpio(int p=0,const char *res=" "){
		pin=p;
		ptr=new char[strlen(res)+1];
		strcpy(ptr,res);
		cout<<"Gpio Pin:"<<pin<<"Is initialed with "<<ptr<<endl;
	}
	Gpio(const Gpio& other)
	{
		cout<<"Copy Constructor Is Called"<<endl;
		pin=other.pin;
		ptr=new char[strlen(other.ptr)+1];
		strcpy(ptr,other.ptr);
	}
	Gpio& operator =(const Gpio&other){
		if(this!=&other){
			delete ptr;
			pin=other.pin;
			ptr=new char[strlen(other.ptr)+1];
			strcpy(ptr,other.ptr);
		}
		return *this;
	}
	Gpio(Gpio&&other){
	cout<<"Move Constructor Is Called"<<endl;
	pin=other.pin;
	ptr=other.ptr;
	other.ptr=nullptr;
	}
	Gpio& operator =(Gpio&&other){

		if(this!=&other){
		delete ptr;
		pin=other.pin;
		ptr=other.ptr;
		other.ptr=nullptr;
		}
		return *this;
	}

};
int main()
{
Gpio G1(17,"Switch");
Gpio G2(14,"Led");
Gpio G3=G1;
G2=G1;

}
