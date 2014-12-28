#include<iostream>
#include<cstdlib>

using namespace std;

int is_placed(int *a,int k,int l)
{
	for(int i=0;i<k;i++)
	{
		if(a[i]==l || (a[i]-l)==(i-k) || (a[i]-l)==(k-i))
			return 0;
	}
	return 1;

}

void print(int *a,int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void nqueen(int *a,int k,int n,int &r)
{
	for(int i=0;i<n;i++)
	{
		if(is_placed(a,k,i))
		{
			a[k]=i;
			if(k==n-1)
			{
				r++;
				print(a,n);
			}
			else
			nqueen(a,k+1,n,r);
		}
		
	}
}



int main()
{
	int n=12;
	int a[n];
	int r=0;
	nqueen(a,0,n,r);
	cout<<r<<endl;
}
