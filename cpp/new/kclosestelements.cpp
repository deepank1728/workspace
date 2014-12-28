/*

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 

*/

#include<iostream>

using namespace std;

int binary_search(int a[],int lower,int upper,int x)
{
	int index=0;
	if(a[lower]==x)
		return lower;
	if(a[upper]==x)
		return upper;
	int mid=(upper+lower)/2;
	
	if(a[mid]==x)
		return mid;
		
	if(lower<upper)
	{
		if(a[mid]>x)
			binary_search(a,lower,mid,x);
		else
			binary_search(a,mid,upper,x);
	}
	
}


void find_k_closest(int a[],int size,int k,int x)
{
	int index=binary_search(a,0,size-1,x);
	
	int i=index-1,j=index+1;
	
	int count=0;
	while(count<k)
	{
		if((x-a[i]) < (a[j]-x) && i>=0 )
		{
			if(a[i]!=x)
			{
				cout<<a[i]<<" ";
				count++;
			}
			i--;
			
		}
		else if((x-a[i]) >= (a[j]-x) && i<size)
		{
		
			if(a[j]!=x)
			{
				cout<<a[j]<<" ";
				count++;
			}
			j++;
		}
		
	}
}
int main()
{
	int a[]={12, 16, 22, 30, 35,35, 39, 42,45, 48, 50, 53, 55, 56},size=14;
	int x=35,k=4;
	
	find_k_closest(a,size,k,x);
}
