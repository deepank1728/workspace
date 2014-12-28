#include<iostream>
#include<cstdlib>

using namespace std;


int catylan(int num)
{
	int sum=0;
	if(num<=1)
		return 1;
	else
	{
		for(int i=0;i<num;i++)
		{
			sum+=catylan(i)*catylan(num-1-i);
		}
	}
	
	return sum;
}


int catalan(int *a,int num)
{
	
	int x,y,sum=0;
	if(num<=1)
		return 1;
	else
	{
		for(int i=0;i<num;i++)
		{
			if(a[i])
				x=a[i];
			else
			{
				x=a[i]=catalan(a,i);
			}
			if(a[num-i-1])
				y=a[num-i-1];
			else
				y=a[num-i-1]=catalan(a,num-i-1);
			sum+=x*y;
		}
	}
	return sum;
}

int main()
{
	int n;
	cout<<"enter number of which catylan number is required\n";
	cin>>n;
	int *a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		a[i]=0;
		
	a[0]=a[1]=1;
	
	
	int r=catalan(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<r<<endl;
	
	cout<<catylan(n)<<endl;
	
	
}
