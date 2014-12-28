#include<iostream>

using namespace std;


int digit_sum(int n)
{
	int a=0;
	int sum=0;
	while(n>0)
	{
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

int main()
{
	int rocknumber;
	cout<<"enter rock number\n";
	cin>>rocknumber;
	int one=1;
	int three=3;
	int nine=9;
	
	while(1)
	{
		if(one ==rocknumber)
		{
			cout<<"river one :"<<one<<endl;
			break;
		}
		
		if(three ==rocknumber)
		{
			cout<<"river three :"<<three<<endl;
			break;
		}
		
		if(nine ==rocknumber)
		{
			cout<<"river nine :"<<nine<<endl;
			break;
		}
	
		while(one <rocknumber)
		{
			one+=digit_sum(one);
		}
	
		while(three <rocknumber)
		{
			three+=digit_sum(three);
		}
	
		while(nine<rocknumber)
		{
			nine+=digit_sum(nine);
		}
	
		if(rocknumber<one && rocknumber<three && rocknumber<nine)
		{
			rocknumber+=digit_sum(rocknumber);
	}
	
	}
}
