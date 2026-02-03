#include<iostream>
using namespace std;
class A{
	public:
	int a;
	A(int v=0):a(v){}

};
int main()
{
	//A s;//garbage data
	A s1{};//By Default it will call Default Constructor
	cout<<s1.a<<endl;
	A s2{100};//Parameterised Constructor
	cout<<s2.a<<endl;
	//A s2();//function declaration
}


