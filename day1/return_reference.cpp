#include<iostream>
using namespace std;
int & fun(int &);
int main()
{

int num=5;
int l_ref=fun(num);
cout<<"num:"<<num<<endl;
cout<<"l_ref"<<l_ref<<endl;


}
int& fun(int &n)
{

n=n*2;
static int l=100;
int &ref=l;
return ref;

}
