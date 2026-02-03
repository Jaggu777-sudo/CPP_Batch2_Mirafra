#include<iostream>
using namespace std;
class A
{
	public:
	int val;
	A(int v=10):val(v){}
	A operator +(A &temp){
		return  res(val+temp.val);
	}
	
};
int main()
{
	A obj(20);
	A obj1;
	A obj2=obj1+obj;
	cout<<"Value of obj2:"<<obj2.val<<endl;

}

