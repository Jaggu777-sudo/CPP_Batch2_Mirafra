#include<iostream>
using namespace std;
class SPI
{

	public:
		bool clock,cs;
		int MOSI,MISO;
		SPI(bool c=false,bool CS=false,int MI=0,int MO=0):clock(c),cs(CS),MOSI(MI),MISO(MO){

		}
		void enable(){
			clock=true;
			cs=true;
			cout<<"SPI Enabled"<<endl;
		}
		void WRITE(int data){
			if(clock && cs){
				MOSI=data;
			}
			else{
				cout<<"clock and cs are not enabled"<<endl;
			}
		}
		int READ()
		{
			if(clock&&cs){
				MISO=123;
				return MISO;

			}
			else
			{

				return -1;
			}


		}



};
int main()
{

	SPI sp1;
	sp1.enable();
	sp1.WRITE(400);
	int data=sp1.READ();
	cout<<"Read data from SPI"<<data<<endl;
}
