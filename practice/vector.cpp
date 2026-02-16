#include<iostream>
#include<initializer_list>
using namespace std;
template<class T>
class myvector{
T* ptr;
int s;
int cap;
void realloc(){
int new_cap=(cap==0)?1:cap*2;
T *new_ptr=new T[new_cap];
for(int i=0;i<s;i++){
new_ptr[i]=ptr[i];
}
delete ptr;
ptr=new_ptr;
cap=new_cap;
}
public:
myvector(int s=0,int n=0):s(s),cap(s){
ptr=(cap==0)?nullptr:new T[cap];
for(int i=0;i<s;i++)
ptr[i]=n;
}
myvector(std::initializer_list<T>l){
s=l.size();
cap=l.size();
ptr=(cap==0)?nullptr:new T[cap];
int i=0;
for(const auto&x:l){
ptr[i++]=x;
}
}
myvector(const myvector& other){
cap=other.cap;
s=other.s;
ptr=new T[other.s];
for(int i=0;i<s;i++){
ptr[i]=other.ptr[i];
}
}
myvector(myvector&& other)noexcept{
s=other.s;
cap=other.cap;
ptr=other.ptr;
other.ptr=nullptr;
other.cap=0;
other.s=0;
}
myvector& operator=(const myvector& other){
if(this!=&other){
cap=other.cap;
s=other.s;
delete ptr;
ptr=(other.cap==0)?nullptr:new T[other.cap];
for(int i=0;i<s;i++)
ptr[i]=other.ptr[i];
}
return *this;
}
myvector& operator=(myvector&& other){
if(this!=&other){
s=other.s;
cap=other.cap;
ptr=other.ptr;
other.s=0;
other.cap=0;
other.ptr=nullptr;
}
return *this;
}
void push_back(const T&val){
if(s==cap){
realloc();
}
ptr[s++]=val;
}
void pop_back(){
s--;
}
T& operator[](int indx){
return ptr[indx];
}
int size()const{
return s;
}
T& at(int indx){
if(indx<s){
return ptr[indx];
}
else{
throw std::out_of_range("Exceed");
}
}
T& front(){
return *ptr;
}
T& back(){
return ptr[s-1];
}
T* begin(){
return ptr;
}
T* end(){
return ptr+s;
}
void shrink_to_fit(){
if(cap<=s)
return ;
if(s==0){
delete []ptr;
cap=0;
return ;
}
T* new_ptr=new T[s];
for(int i=0;i<s;i++)
new_ptr[i]=ptr[i];
delete []ptr;
ptr=new_ptr;
cap=s;
}
void reserve(int new_cap){
if(new_cap<=cap)
return ;
T* new_ptr=new T[new_cap];
for(int i=0;i<size;i++){
new_ptr[i]=ptr[i];
}
delete []ptr;
ptr=new_ptr;
cap=new_cap;
}
bool empty()const{
return s==0;
}
void clear(){
s=0;
}
T* insert(T* pos,int c,const T&val){
int index=pos-ptr;
if(s==cap){
realloc();
}
int i,j=s-1;
for(int i=s;i<=cap&&i>index+c;i--){
ptr[i]=move(ptr[j--]);
}


}
T* insert(T* pos,const T&val){
int index=pos-ptr;
if(cap==s){
realloc();
}
int i;
for(i=s;i>index;i--){
ptr[i]=move(ptr[i-1]);
}
ptr[index]=val;
s++;
return ptr+index;
}
~myvector(){
delete []ptr;
}
};
int main(){
myvector<int>v1;
myvector<int>v2(5,10);
myvector<int>v3(5,0);
myvector<int>v4={1,2,3,4,5};
myvector<int>v5(v2);
v5=std::move(v2);
//myvector<int>v6=std::move(v4);
v1.push_back(10);
v1.push_back(20);
/*for(int i=0;i<v1.size();i++)
cout<<v1[i]<<" ";
cout<<endl;*/
v4.insert(v4.begin()+2,100);
for(const auto& x:v4){
cout<<x<<endl;
}
//cout<<v4.front()<<" "<<v4.back()<<endl;
	return 0;
}

