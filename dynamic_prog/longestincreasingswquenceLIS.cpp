#include<iostream>
#include<cstdlib>

using namespace std;


void print_array(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void lis(int a[],int b[],int size)
{
	int max,temp=0;
	for(int i=1;i<size;i++)
	{
		max=0;
		for(int j=0;j<i;j++)
		{
			if(a[i]>=a[j])
			{
				temp=b[j];
				if(temp>max)
					max=temp;
			}
		}
		b[i]=max+1;
	}
}

void print(int a[],int b[],int max_index,int max)
{
	if(max_index==-1)
		return;
	
	if(b[max_index]==max-1)
	{
		print(a,b,max_index-1,max-1);
		cout<<a[max_index]<<"  ";
	}
	else
		print(a,b,max_index-1,max);
}

int main()
{
	int a[]={1,2,4,3,5,32,6,9,21,3},size=10;
	
	int b[size];
	
	int max=-999999;
	int max_index=0;
	
	for(int i=0;i<size;i++)
		b[i]=0;
	b[0]=1;
	lis(a,b,size);
	
	for(int i=0;i<size;i++)
	{
		if(b[i]>max)
		{
			max=b[i];
			max_index=i;
		}
	}
	print_array(a,size);
	print_array(b,size);
	print(a,b,max_index-1,max);
	cout<<a[max_index]<<endl;
}
