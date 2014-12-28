#include<iostream>

using namespace std;

void print(int *a,int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}

int answer(int k,int n,int position,int result,int *drop_count,int *a)
{
	if(a[k]==1)
		return *drop_count;
	if(position>k )
	{
		position=position-n;
		n=k-position;
		answer(k,n,position+n,result,drop_count,a);
		
	}
	
	else if(position>=result && a[position-1]==1)
	{
		a[position]=-1;
		print(a,k+1);
		(*drop_count)++;
		return *drop_count;
	}
	else if(position<result)
	{
		a[position]=1;
		print(a,k+1);
		(*drop_count)++;
		answer(k,n,position+(k-position)/n,result,drop_count,a);
	}
	else if(position>=result)
	{
		(*drop_count)++;
		if(a[position]==-1)
			(*drop_count)--;
		a[position]=-1;
		print(a,k+1);
		position=position-n;
		n=n/2;
		answer(k,n,position-(k-position)/n,result,drop_count,a);
	}
	

}



int main()
{
	int n=2,k=36;
	
	int a[k+1];
	for(int i=0;i<=k;i++)
		a[i]=0;
	int drop_count=0;
	int r=answer(k,n,k/n,35,&drop_count,a);
	cout<<r<<endl;
}
