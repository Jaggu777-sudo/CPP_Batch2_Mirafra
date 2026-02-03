#include<iostream>
using namespace std;
class Sensor
{
	int value;
	mutable int read_count;//mutable allows as to change the data in const member functions
	public:
	Sensor(int v):value(v),read_count{0}{}
	void read_data()const{
		read_count++;
	}
	int Get_data()const{
		return read_count;
	}
	void Write_data(int data){
	value=data;
	}

};
int main(){
	Sensor s(10);
	const Sensor s1(100);
	s.read_data();
	s.Write_data(20);
	cout<<s.Get_data()<<endl;
	s1.read_data();
	//s1.Write_data(200); we cannot call normal member function through const object;
}
