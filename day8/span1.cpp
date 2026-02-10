#include<iostream>
#include<span>
#include<vector>
using namespace std;
template<typename T>
void print(std::span<T> s){
	for(const auto& x : s){
		cout << x << " ";
	}
	cout << endl;
}
template<>
void print(std::span<int>s){

for(auto& x:s)
x=x*10;
}
int main()
{
	vector<char> v = {'A', 'B', 'C'};
	print<char>(v);
	int *a=new int[5];
	for(int i=0;i<5;i++)
	a[i]=i*10;
	string s="Jagadeesh";
	print<char>(s);
	print<int>(span<int>(a,5));
	int arr[] = {10,20,30,40,50};
	print<int>(arr);
	cout<<"after span modification"<<endl;
	for(auto i:arr){
	cout<<i<<" ";
	}
	cout<<endl;
	delete []a;
	
}

