#include<iostream>
using namespace std;


int add_one(int a)
{
	int x=1;
	
	while((a&x))
	{
		a=~x&a;
		x=x<<1;
	}
	a=a|x;
	return a;
}

int main()
{
	int a=237;
	
	int r=add_one(a);
	cout<<r;
}
