#include<iostream>
using namespace std;


int max_area(int a[],int low,int high)
{
	if(low==high)
		return a[low];
	int min=a[low];
	int max;
	int i=0,index=0;
	for(i=low;i<=high;i++)
	{
		if(a[i]>min)
		{
			min=a[i];
			index=i;
		}
	}
	
	int left=0,right=0;
	if(index-1>-1)
		left=max_area(a,low,index-1);
	
	if(index+1<=high)
		right=max_area(a,index+1,high);
	
	if(left>right)
		max=left;
	else
		max=right;
	if((min*(high-low+1))>max)
		max=(min*(high-low+1));
	return max;
}

int main()
{
	int a[]={6, 2, 5, 4, 5, 1, 6},size=7;
	
	int r=max_area(a,0,size-1);
	cout<<r<<endl;
}
