#include<iostream>
using namespace std;
class SPI
{
	int MISO;
	public:
	SPI(int M):MISO(M){
		cout<<"Constructor"<<endl;
	}
	~SPI(){
		cout<<"Destructor"<<endl;
	}
	SPI(const SPI&other){
		MISO=other.MISO;
		cout<<"Copy Constructor"<<endl;
	}
	SPI(SPI&&other){
		cout<<"Move Constructor"<<endl;
		MISO=other.MISO;
	}

};
SPI create(){

	SPI s1(25);
	return s1;

}
int main(){
	SPI s=create();

}
