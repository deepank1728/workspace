#include<iostream>
using namespace std;

int count_sum(int a[],int size,int a_count,int count,int k,int l,int temp_sum)
{
	if(count==k && temp_sum==l)
		return 1;
	else if(a_count==size)
		return 0;
	
	else
	{
		int x=count_sum(a,size,a_count+1,count,k,l,temp_sum);
		int y=count_sum(a,size,a_count+1,count+1,k,l,temp_sum+a[a_count]);
		return x+y;
	}
}

int main()
{
	int a[]={5,7,10,12,15,18,20},size=7;
	int k=3,l=35;
	int r=count_sum(a,size,0,0,k,l,0);
	cout<<r<<endl;
}
