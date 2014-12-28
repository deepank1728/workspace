#include<iostream>
#include<cstdlib>
using namespace std;

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void print_subset_sum(int a[],int b[],int size,int a_count,int count,int sum,int temp)
{
	if(temp==sum)
	{
		print(b,count);
		return;
	}
	else if(temp>sum)
		return;
	
	else if(a_count==size)
		return;
		
	else
	{
		print_subset_sum(a,b,size,a_count+1,count,sum,temp);
		b[count]=a[a_count];
		print_subset_sum(a,b,size,a_count+1,count+1,sum,temp+a[a_count]);
	}
}



int main()
{
	int a[]={5,7,10,12,15,18,20},size=7;
	
	int b[size];
	int sum=35;
	print_subset_sum(a,b,size,0,0,sum,0);
}
