#include<iostream>
using namespace std;
class Led{
	public:
		bool led_status,sw_status;
		Led(bool s=false,bool j=false):led_status(s),sw_status(j){}
		void led_on(){
			cout<<"led turned on"<<endl;
		}
		void led_off(){
			cout<<"led_off"<<endl;
		}
		void sw_high(){
			cout<<"Sw is in High state"<<endl;
		}
		void sw_low(){
			cout<<"Sw is in Low state"<<endl;
		}
		void operator()(bool l,bool s){
			if(l&&s){
				led_on();
				sw_high();
			}
			else {
				led_off();
				sw_low();
			}
		}

};
int main()
{
	Led l;
	l(true,false);
	l(true,true);
}

