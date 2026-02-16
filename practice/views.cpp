#include<iostream>
#include<vector>
#include<ranges>
using namespace std;
int main(){
vector<int>v1={1,3,5,6,7,8,9};
auto greater_2=v1|std::views::filter([](int x){
return x>2;
});
for(const auto& g:greater_2){
cout<<g<<" ";
}
cout<<endl;
	return 0;
}

