#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

void print(int **a,int size,int m)
{
	for(int i=0;i<=size;i++)
	{
		for(int j=0;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

void knap_sack(int **arr,int w[],int b[],int m,int size)
{
	int i=1,j=1;
	while(i<=size)
	{
		j=1;
		while(j<=m)
		{
			if(w[i-1]>j)
				arr[i][j]=arr[i-1][j];
			else
				arr[i][j]=max(arr[i-1][j],(arr[i-1][j-w[i-1]]+b[i-1]));
			j++;
		}
		i++;
	}

}

void print_elements(int **arr,int size,int m,int w[])
{
	int i=size,j=m;
	
	while(i>0)
	{
		if(arr[i][j]!=arr[i-1][j])
		{
			cout<<i<<" element"<<"\t";
			j=j-w[i-1];
		}
		i--;
	}
	cout<<endl;
}
int main()
{
	int w[]={2,3,4,5},size=sizeof(w)/sizeof(int);
	int b[]={3,4,5,6};
	int m=5;
	
	int **arr=(int **)malloc(sizeof(int*)*size+1);
	for(int i=0;i<=size;i++)
		arr[i]=(int *)calloc(m+1,sizeof(int));

	knap_sack(arr,w,b,m,size);
	cout<<arr[size][m]<<endl;
	print_elements(arr,size,m,w);
}
