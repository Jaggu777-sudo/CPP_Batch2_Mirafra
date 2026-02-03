#include<iostream>
using namespace std;
int add(int x,int y){
return x+y;
}
int& Tranform(int &x){
x*=x;
return x;
}
void print(int &x){
cout<<"L-Value Reference"<<endl;
}
void print(const int& x){
cout<<"Const L-Value or R-Value"<<endl;
}
void print(int&& x){
cout<<"R_Value"<<endl;
}
int&& print(){
return 10;
}
int main()
{
int x=10;
int& ref=x;
const int& ref2=100;
int& ref3=Tranform(x);
print(x);
print(100);
int &&r=add(10,20);
int&& r1=print();
cout<<sizeof(r)<<endl;
cout<<sizeof(ref2)<<" "<<sizeof(ref3)<<endl;
}
