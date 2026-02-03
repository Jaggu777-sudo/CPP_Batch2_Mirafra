#include<iostream>
using namespace std;
class Uart{

int baurd_rate;
public:
Uart(int br){
baurd_rate=br;
}
void transmit(){
if(baurd_rate>=9600){
cout<<"Data Transmission"<<endl;

}

}


}
