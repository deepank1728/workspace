#include<iostream>

using namespace std;

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void seperate_even_odd(int a[],int size)
{
	int i=0,j=size-1,temp;
	
	while(i<j)
	{
		while(a[i]%2==0 && i<size)
			i++;
		
		while(a[j]%2!=0 && j>=0)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;	
		}	
	}
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,0},size=sizeof(a)/sizeof(int);
	
	print(a,size);
	seperate_even_odd(a,size);
	print(a,size);
}
