#include<iostream>
#include<memory>
using namespace std;
class GPIO
{
	int pin;
	public:
	GPIO(int p=0):pin(p){}

	void Gpio_read()
	{
		cout<<"Read the data from GPIO Pin"<<endl;
	}
	void Gpio_write(){

		cout<<"write data in Gpio Pin"<<endl;
	}



};
struct GPIO_DEL{

	void operator()(GPIO *p){
		if(p){
			cout<<"GPIO pin is released"<<endl;
		}
	}

};
int main()
{
	unique_ptr<GPIO,GPIO_DEL>p(new GPIO(17),GPIO_DEL());
	p->Gpio_read();
	p->Gpio_write();
}
