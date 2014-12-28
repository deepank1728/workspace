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

int add(int a,int b)
{
	int temp=0,x=1;
	
	/*if(a<0)
	{
		a=~a;
	}
	*/
	if(b<0)
	{
		b=~b;
		//b=add_one(b);
	}
	a=~a;
	a=add_one(a);
	while(temp!=b)
	{
		a=add_one(a);
		temp=add_one(temp);
	}
	return ~a;
}

int main()
{
	int a=5;
	int r=add(a,-7);
	cout<<r<<endl;
}
