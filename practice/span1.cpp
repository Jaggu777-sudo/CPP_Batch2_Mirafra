#include<iostream>
#include<vector>
#include<span>
using namespace std;
void print(std::span<int>s){
	for(const auto& j:s){
		cout<<j<<" ";
	}
	cout<<endl;
}
int main(){
	vector<int>v1={1,2,3,4,5};
	print(v1);
	int arr[]={1,2,3,4,5,6};
	print(arr);
	int *a=new int[3];
	for(int i=0;i<3;i++)
	a[i]=i*10;
	print(span<int>(a,3));
	return 0;
}

