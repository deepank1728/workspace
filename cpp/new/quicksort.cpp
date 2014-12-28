#include<iostream>
using namespace std;

void print(int a[],int low,int up)
{
	for(int i=low;i<=up;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
}

void quick_sort(int a[],int low,int up)
{
	int pivot=low,i=low,j=up,temp;
	
	if(low>=up)
		return;
	
	while(i<j)
	{
		while(i<=up && a[pivot]>=a[i])
			i++;
			
		while(j>=0&& a[pivot]<a[j])
			j--;
			
		if(i<j)
		{
			/*temp=a[i];
			a[i]=a[j];
			a[j]=temp;*/
			a[i]=a[i]^a[j]; a[j]=a[i]^a[j]; a[i]=a[i]^a[j];
		}
	}
	
	temp=a[j];
	a[j]=a[pivot];
	a[pivot]=temp;
	//a[j]=a[j]^a[pivot];a[pivot]=a[j]^a[pivot]; a[j]=a[j] ^ a[pivot];
	
	print(a,low,up);
	quick_sort(a,low,i-1);
	quick_sort(a,i+1,up);
}


int main()
{
	int a[]={1,0,2,9,3,8,4,7,5,6},size=10;
	print(a,0,size-1);
	quick_sort(a,0,size-1);
	print(a,0,size-1);
}
