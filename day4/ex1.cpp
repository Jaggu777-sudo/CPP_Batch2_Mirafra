#include<iostream>
#include<vector>
using namespace std;
class SPI{

	int pin;
	public:
	SPI(int p){
		pin=p;
		cout<<"Constructor Is Called"<<endl;
	}
	SPI(const SPI& other){
		cout<<"Copy constructor Called"<<endl;
		pin=other.pin;

	}
	SPI(SPI&& other)noexcept{
		cout<<"Move Constructor Called"<<endl;
		pin=other.pin;

	}
	~SPI(){
		cout<<"Destructor Is Called"<<endl;
	}

	void display(){
		cout<<"PIN:"<<pin<<endl;

	}


};
int main()
{

	vector<SPI>v;
	v.push_back(SPI(1));
	v.push_back(SPI(2));
	v[1].display();
}
