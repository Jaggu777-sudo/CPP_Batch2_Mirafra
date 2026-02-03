#include<iostream>
using namespace std;
int main()
{
int a=10,b=100;
const int *const p=&a;
*p=100;
p=&b;


}
