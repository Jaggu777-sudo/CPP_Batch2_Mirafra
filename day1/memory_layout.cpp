#include<iostream>
using namespace std;
static int x;
int main()
{
int y;
int *p=new int[1];
static int z=10;
cout<<"Uninitialized Data Segment"<<&x<<endl;
cout<<"stack section:"<<&y<<endl;
cout<<"Heap Section:"<<&p<<endl;
cout<<"Intializaed Data Segment"<<&z<<endl;
}
