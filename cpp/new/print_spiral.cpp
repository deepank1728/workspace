#include<iostream>
#include<cstdlib>
using namespace std;

void print(int **a,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}


void printchar(char **a,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}


void print_spiral(int **a,int n,int m)
{
	int temp_n=n,temp_m=m;
	int arr[n][m];
	
	
	char **arr2=new char*[n];
	for(int i=0;i<n;i++)
		arr2[i]=new char[m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			arr[i][j]=0;
	}
	int d=0,count_even=0,count_odd=0,last_indexi=-1,last_indexj;
	while(1)
	{
		int previous;
		if(last_indexi==-1)
		{
			for(int i=0;i<m;i++)
			{
				cout<<a[0][i]<<"  ";
				arr2[0][i]='x';
				arr[0][i]=1;
			}
			last_indexj=m-1;
			
			for(int i=0;i<n;i++)
			{
				if(!arr[i][last_indexj])
				{
					cout<<a[i][last_indexj]<<"  ";
					arr2[i][last_indexj]='x';
					arr[i][last_indexj]=1;
					last_indexi=i;
				}
		
			}
		}
		else
		{
			if(d%2==0)
			{
				previous=last_indexj;
				for(int i=0;i<m;i++)
				{
					if(!arr[last_indexi][i])
					{
						cout<<a[last_indexi][i]<<"  ";
						arr2[last_indexi][i]='0';
						arr[last_indexi][i]=1;
						last_indexj=i;
					}
					
				}
				if(previous==last_indexj)
						break;
				
				previous=last_indexi;
				for(int i=0;i<n;i++)
				{
					if(!arr[i][last_indexj])
					{
						cout<<a[i][last_indexj]<<"  ";
						arr2[i][last_indexj]='0';
						arr[i][last_indexj]=1;
						last_indexi=i;
					}
			
				}
				if(previous==last_indexi)
						break;
			}
			else
			{
				previous=last_indexj;
				for(int i=m-1;i>=0;i--)
				{
					if(!arr[last_indexi][i])
					{
						cout<<a[last_indexi][i]<<"  ";
						arr2[last_indexi][i]='x';
						arr[last_indexi][i]=1;
						last_indexj=i;
					}
				}
				
				if(previous==last_indexj)
						break;
				
				previous=last_indexi;
				for(int i=n-1;i>=0;i--)
				{
					if(!arr[i][last_indexj])
					{
						cout<<a[i][last_indexj]<<"  ";
						arr2[i][last_indexj]='x';
						arr[i][last_indexj]=1;
						last_indexi=i;
					}
			
				}
				if(previous==last_indexi)
						break;
			}
		}
		
		
		
		d++;
		
	}
	
	cout<<endl<<endl;
	
	printchar(arr2,n,m);
	
}


int main()
{
	int n=4,m=5,k=0;
	int **a=new int*[n];
	
	for(int i=0;i<n;i++)
		a[i]=new int[m];
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			a[i][j]=k++;
	}
	
	print(a,n,m);
	cout<<endl<<endl;
	print_spiral(a,n,m);
}
