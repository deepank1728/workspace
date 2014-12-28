#include<iostream>
#include<cstdlib>

using namespace std;

void shift_down(int a[],int size,int i)
{
	int max,left,right,temp;
	
	left=2*i+1;
	right=2*i+2;
	
	if(a[left]>a[i] && left<size)
		max=left;
	else
		max=i;
	if(a[right]>a[max] && right<size)
		max=right;
		
	if(max!=i)
	{
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		shift_down(a,size,max);
	}
}


void make_heap(int a[],int size)
{
	for(int i=(size-1)/2;i>=0;i--)
		shift_down(a,size,i);
}

void heap_sort(int a[],int size)
{
	int temp;
	make_heap(a,size);
	for(int i=0;i<size;i++)
	{
		temp=a[0];
		a[0]=a[size-i-1];
		a[size-i-1]=temp;
		shift_down(a,size-i-1,0);
	}
}

void display(int a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[]={2,0,1,4,23,69,11,17,3,18},size=10;
	
	//shift_down(a,size);
	display(a,size);
	make_heap(a,size);
	heap_sort(a,size);
	cout<<"After sorting\n";
	display(a,size);
	
}
