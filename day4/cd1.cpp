#include<iostream>
#include<memory>
using namespace std;
class SPI{
	public:
		bool clock;
		int MOSI,MISO;
		SPI(int MO=0,int MI=0,bool c=false):MOSI(MO),MISO(MI),clock(c){
		}
		void enable(){
			clock=true;
		}
		void write_data(int val){
			if(clock){
				MOSI=val;
			}
		}
		int read_data(){
			MISO=123;
			return MISO;
		}
		void disable(){
			clock=false;
		}
		void display(){
			cout<<"MOSI: "<<MOSI<<" "<<"MISO: "<<MISO<<endl;
		}
};
class SPI_Deleter{
	int c;
	public:
	//SPI_Deleter(int val):c(val){}
	void operator()(SPI *s){
		if(c==0){
			s->disable();
			cout<<"if condition executed"<<endl;
			delete s;
		}
	}
};
int main()
{
	SPI_Deleter s{};
	unique_ptr<SPI,SPI_Deleter>p(new SPI(),s);
	p->enable();
	p->write_data(25);
	int r=p->read_data();
	cout<<"Recevied Value"<<r<<endl;
	p->display();
}



