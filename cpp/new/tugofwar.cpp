#include<iostream>
#include<cstdlib>

using namespace std;

int max_sum(int a[],int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
		sum+=a[i];
	return sum;
}

int main()
{
	int a[]={5,1,2,1},size=4;
	int sum=max_sum(a,size);
	int **arr=new int*[size+1];
	for(int i=0;i<=size;i++)
	{
		arr[i]=new int[sum+1];
	}
	for(int i=0;i<=size;i++)
		a[i][0]=1;
	for(int i=0;i<=sum;i++)
		a[0][i]=0;
		
	
}
