#include<iostream>
#include<vector>
using namespace std;
void calibration(int &n);
void display(const int &);
int main()
{

	int num=1;
	calibration(num);
	cout<<num<<"in calibration"<<endl;
	display(num);
	cout<<"num"<<"in display"<<endl;
	vector<string>v{"Jagadeesh","Lokesh","Rukmini"};
	for(const auto &x:v)
	cout<<x<<endl;
}
void calibration(int &n)
{
	n=n*100;
}
void display(const int &n)
{
	//n=n*10;//error because we cant change the const ref
}
