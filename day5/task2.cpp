#include<iostream>
#include<memory>
using namespace std;
class custom_deleter{

	public:
		void operator()(float *ptr){
			delete []ptr;

		}

};
void change(shared_ptr<float[]>p){
float avg=0;
for(int i=0;i<5;i++){
avg+=p[i];
}
avg/=5;
cout<<"Avg Temperature "<<avg<<endl;
cout<<"Inside Func Ref Count: "<<p.use_count()<<endl;
}
int main()
{
	shared_ptr<float[]>p(new float[5],custom_deleter{});
	for(int i=0;i<5;i++){
	cin>>p[i];
	}
	change(p);
	cout<<"Ref Count in main: "<<p.use_count()<<endl;
}
