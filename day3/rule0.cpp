#include<iostream>
#include<vector>
using namespace std;
class Car{
	vector<int>vN;
	public:
	explicit Car(int val):vN(val,0){}
	void set_data(int index,int number){
		if(index<vN.size()){
			vN[index-1]=number;
		}
	}
	void get_data()
	{
		cout<<"Total Cars"<<vN.size()<<endl;
		for(int i=0;i<vN.size();i++){
			cout<<"Car:"<<(i+1)<<"Number"<<vN[i]<<endl;
		}
	}


};
int main()
{

	Car garage(2);
	garage.set_data(1,111);
	garage.set_data(2,222);
	Car garage1(3);
	garage1.set_data(1,333);
	garage1.set_data(2,444);
	garage1.set_data(3,555);

	garage.get_data();
	garage1.get_data();
	cout<<"copy assignment"<<endl;
	garage=garage1;//copy assigment is called
	cout<<"copy constructor"<<endl;
	Car garage3=garage1;

}
