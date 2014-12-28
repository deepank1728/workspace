#include<iostream>

using namespace std;

void merge_sort(int a[],int low,int mid,int up)
{
	int c[up-low+1];
	int i=low,j=mid+1,k=0;
	while(i<=mid && j<=up)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];			
	}
	
	while(i<=mid)
		c[k++]=a[i++];
	while(j<=up)
		c[k++]=a[j++];
	k=0;
	for(int p=low;p<=up;p++)
		a[p]=c[k++];
}

void partition(int a[],int low,int up)
{
	if(low==up)
		return;
	int mid=(low+up)/2;
	partition(a,low,mid);
	partition(a,mid+1,up);
	merge_sort(a,low,mid,up);
}

void print(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int main()
{
	int a[]={1,0,2,9,3,8,4,7,5,6},size=10;
	print(a,size);
	partition(a,0,size-1);
	print(a,size);
}
