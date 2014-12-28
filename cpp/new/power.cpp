#include<iostream>
using namespace std;
int count=0;
int pow(int a,int b)
{
	count++;
	if(b==1)
		return a;
	
	if(b%2==0)
	{
		int x=pow(a,b/2);
		return x*x;
	}
	else
	{
		int x=pow(a,b/2);
			return a*x*x;
	}
}


int main()
{
	int a=2,b=31;
	int r=pow(a,b);
	cout<<r<<endl<<count<<endl;
}
