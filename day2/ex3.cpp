#include<iostream>
#include<memory>
class FileDeleter{
	public:
		void operator()(FILE *file){
			if(file){
				fclose(file);

			}

		}
};
int main()
{

	std::unique_ptr<FILE,FileDeleter>fileptr(fopen("def.txt","w"));
	if(fileptr)
	{
	   std::cout<<"File is opend SuccessFully"<<std::endl;
	}

}
