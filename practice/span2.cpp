#include<iostream>
#include<vector>
#include<span>
using namespace std;
struct Emp{
string name;
float salary;
int id;
Emp(string s,float f,int i):name(s),salary(f),id(i){}
};
void print(span<Emp>s){

for(const auto& e:s){
cout<<e.name<<" "<<e.salary<<" "<<e.id<<endl;

}

}

int main(){
vector<Emp>v1;
v1.push_back(Emp("Jagadeesh",23000,6658));
v1.emplace_back(Emp("Sunil",25000,6657));
print(v1);
	return 0;
}

