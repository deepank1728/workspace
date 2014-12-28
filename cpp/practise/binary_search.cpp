#include<iostream>
using namespace std;

int binary_search(int a[],int low,int up,int num)
{
	if(a[low]==num)
		return low;
	if(a[up]==num)
		return up;
	int mid=(low +up)/2;
	
	if(a[mid]==num)
		return mid;
	
	if(low<up)
	{
		if(a[mid]>num)
			return binary_search(a,low,mid,num);
		if(a[mid]<num)
			return binary_search(a,mid,up,num);
	}
}

int binary_search_iterative(int a[],int size,int num)
{
	int low=0,up=size-1;
	int mid=(low +up)/2;
	
	while(low<up)
	{
		if(a[low]==num)
			return low;
		if(a[up]==num)
			return up;
		
		mid=(low +up)/2;
		if(a[mid]==num)
			return mid;
		
		if(a[mid]>num)
			up=mid;
		else
			low=mid;
	}
	return -1;
}

int main()
{
	int a[]={1,2,6,9,11,13,15,26,47},size=sizeof(a)/sizeof(int);
	int num=26;
	//int r=binary_search(a,0,size-1,num);
	int r=binary_search_iterative(a,size,num);
	if(r==-1)
		cout<<" not found\n";
	else
		cout<<"found at index "<<r<<endl;
}
