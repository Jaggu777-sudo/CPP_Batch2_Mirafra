#include<iostream>
#include<vector>
#include<span>
using namespace std;
int main(){
	vector<int>v1={1,2,3,4,5};
	span<int>s(v1);
	cout<<"first ele:"<<*(s.begin())<<endl;
	cout<<"last ele:"<<*(s.end()-1)<<endl;
	cout<<"front ele:"<<s.front()<<endl;
	cout<<"last ele:"<<s.back()<<endl;
	cout<<s[3]<<endl;
	auto first=s.first(2);
	auto last=s.last(2);
	auto sub=s.subspan(1,5);
	for(const auto& f:first)
	cout<<f<<" ";
	cout<<endl;
	for(const auto& l:last)
	cout<<l<<" ";
	cout<<endl;
	for(const auto& s:sub)
	cout<<s<<" ";
	cout<<endl;
	return 0;
}

