#include<iostream>

using namespace std;

class singelton
{
	public:
		
		static singelton *getinstance()
		{
			if(!instance)
				instance =new singelton();
			return instance;
		}
	private:
		singelton(){
			cout<<"constructor called only one time\n";
		}
		singelton(singelton &s){}
		
		static singelton *instance;
		
};
singelton *singelton::instance=NULL;

int main()
{
	//singelton *s1=new singelton();
	singelton *s2=singelton::getinstance();
	singelton *s3=singelton::getinstance();
}
