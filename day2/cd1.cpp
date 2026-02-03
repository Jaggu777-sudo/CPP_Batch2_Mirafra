#include<iostream>
#include<memory>
#include<cstring>
void custom_delete(float *f){

delete f;

}
int main()
{

std::unique_ptr<float,void(*)(float *)>p({(float *)malloc(5)});



}
