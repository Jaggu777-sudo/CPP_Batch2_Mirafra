#include<iostream>
using namespace std;
int main()
{
int *p=new int(10);
cout<<"Heap segment:"<<*p<<endl;
cout<<"Stack Segment:"<<&p<<endl;

}
