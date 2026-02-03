#include<iostream>
using namespace std;
int main()
{
	int a=100;
	int b=200;
	int *p=&a;
	int &ref=a;
	int &ref1=a;
	ref1=b;
	int const c=100;
	const int &ref2=c;
	int * &refp=p;
	cout<<&refp<<endl;
	cout<<&p<<endl;
	int arr[3];
	int &refarr[3]=arr;

}
