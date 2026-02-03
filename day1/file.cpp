#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
using namespace std;
class File{
	public:
		int fd;
		File(const char *path)
		{

			fd=open(path,O_WRONLY|O_CREAT|O_TRUNC,0664);
			cout<<"fd value:"<<fd<<endl;
		}
		void writedata(const char *d)
		{
			if(fd<0)
				perror("open");
			write(fd,d,strlen(d));
		}

		~File()
		{
			if(fd>0){
				cout<<"File is closed"<<endl;
				close(fd);
			}

		}
};
int main()
{
	File f("cpp6.txt");
	f.writedata("Jagadeesh\n");
	f.writedata("Mirafra Technologies");
	File f1("abc.txt");
	f1.writedata("Welcome To Mirafra Technologies\n");
}
