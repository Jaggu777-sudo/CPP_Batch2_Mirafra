#include<iostream>
using namespace std;
int main()
{
int a=10,b=100;
//int * const p;//error it must be initailized
int *const p=&a;
*p=100;
cout<<*p<<endl;
p=&b;//error


}
