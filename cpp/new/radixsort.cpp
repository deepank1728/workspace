#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void printhash(int a[10][13],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void radix_sort(int a[],int size)
{
	int max=a[0],length=0;
	int arr[10][13];
	for(int i=0;i<size;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<size;j++)
			arr[i][j]=0;
	}
	while(max)
	{
		max=max/10;
		length++;
	}
	int d=0,base,div;
	while(d!=length)
	{
		d++;
		base=pow(10,d-1);
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(!arr[(a[i]/(base))%10][j])
				{
					
					arr[(a[i]/(base))%10][j]=a[i];
					break;
				}
			}
		}
		
		int k=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(arr[i][j])
					a[k++]=arr[i][j];
				arr[i][j]=0;
			}
		}
		print(a,size);
	}
}

int main()
{
	int a[]={1,32,3,2,4,3,2,3,232,312,99,83,11},size=13;
	print(a,size);
	radix_sort(a,size);
	print(a,size);
}
