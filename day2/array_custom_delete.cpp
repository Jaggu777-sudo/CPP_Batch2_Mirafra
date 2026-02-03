#include<iostream>
#include<memory>
using namespace std;
/*struct ArrayDeleter{
template<typename T>
void operator()(T *p)const{

delete p;
}

};*/
int main()
{
unique_ptr<int[]>ap(new int[10]);

}
