#include<iostream>

using namespace std;

void change(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(a[a[i]-1]<=size)
			a[a[i]-1]=size+a[i];
		else
			a[a[i]-1]+=a[i];
	}
}

void elements_and_count(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		if(a[i]>size)
			cout<<"element  is "<<i+1<<" and count is "<<(a[i]-size)%(i+1)<<endl;
	}
}

int main()
{
	int a[]={1,3,3,5,5,7,8,3,5,3},size=10;
	change(a,size);
	elements_and_count(a,size);
	
}
