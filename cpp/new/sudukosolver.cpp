#include<iostream>
#include<cmath>
#define size 10

using namespace std;

int power(int a,int b)
{
	int d=pow(a,b);
	return d;
}


void fill_suduko(int a[size][size])
{
	int hashvalue=0;
	int column_hash[10]={0,0,0,0,0,0,0,0,0,0};
	int filled=0;
	int zero=0;
	
	for(int i=0;i<size;i++)
	{
	
		
	
		hashvalue=0;
		for(int j=0;j<size;j++)
		{
			if(a[i][j])
			{
				hashvalue+=pow(2,a[i][j]);
				filled+=pow(2,j);
				column_hash[i]+=power(2,a[i][j]);
			}
		}
		
		int k=0;
		for(int j=0;j<size;j++)
		{
			if(j==0 && zero==1)
				continue;
				
			while((power(2,k)&hashvalue)==pow(2,k) || (power(2,k)&column_hash[i])==pow(2,k) )
			{
				k++;
			}
			
			if((power(2,j)&filled)==pow(2,j))
				continue;
			a[i][j]=k++;
			
			
		}
	}

}
void display(int a[size][size])
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int a[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			a[i][j]=0;
	}
	
	fill_suduko(a);
	
	display(a);

}
