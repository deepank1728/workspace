#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int max_prod(int *a,int n)
{
	int y;
	int m=0,max_pd=0;
	if(n==2)
		return 1;
	else
	{
		for(int i=1;i<n;i++)
		{
			if(a[n-i])
				y=a[n-i];
			else
				y=a[n-i]=max_prod(a,n-i);
			max_pd=max((n-i)*i,y*i);
			if(max_pd>m)
				m=max_pd;
		}
		return m;
	}
}


int main()
{
	cout<<"enter number\n";
	int n;
	cin>>n;
	
	int *a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		a[i]=0;
	a[0]=a[1]=0;
	a[2]=1;
	
	int r=max_prod(a,n);
	cout<<r<<endl;
}
