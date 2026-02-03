#include<iostream>
using namespace std;
class Led
{
public:
bool status=true;
void led_on()
{
cout<<"led on"<<endl;
}
void led_off()
{
cout<<"led_off"<<endl;

}


};
void ledapi(Led &);
int main()
{

Led l1;
ledapi(l1);

}
void ledapi(Led &l1)
{
if(l1.status)
l1.led_on();
else
l1.led_off();
}


