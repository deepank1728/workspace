#include<iostream>
#include<cstdlib>

using namespace std;

int count_path(int **a,int m,int n,int indexm,int indexn)
{
	int x,y;
	if(indexm==m-1 && indexn==n-2)
		return 1;
	if(indexm==m-2 && indexn==n-1)
		return 1;
	
		if(a[indexm+1][indexn])
			x=a[indexm+1][indexn];
		else
			x=a[indexm+1][indexn]=count_path(a,m,n,indexm+1,indexn);
		if(a[indexm][indexn+1])
			y=a[indexm][indexn+1];
		else
			y=a[indexm][indexn+1]=count_path(a,m,n,indexm,indexn+1);
	
	return x+y;
}


int main()
{
	int m,n;
	cout<<"enter m and n\n";
	cin>>m;
	cin >>n;
	
	int **a=(int **)malloc(sizeof(int *)*m);
	
	for(int i=0;i<m;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
		{
			if(j==n-1)
				a[i][j]=1;
			else if(i==m-1)
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	
	int r=count_path(a,m,n,0,0);
	cout<<r<<endl;
}
