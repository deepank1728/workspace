#include<iostream>
#include<cstdlib>
using namespace std;

void print_matrix(int **a,int n,int m)
{
	cout<<"hello\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
		
	}
}

int edit_distance(string a,string b,int i,int j)
{
	if(i==a.length() && j=b.length())
		return 0;
		
	if(i!=a.length() && j==b.length())
		return a.length()-i-1;
		
	else if(i==a.length() && j!=b.length())
		return b.length()-j-1;
		
	else
	{
		if(a[i]==b[j])
			
	}
	return 0;
}

int main()
{
	string a="zeil",b="trials";
	int x=a.length();
	int y=b.length();
	
	int **arr=new int*[x];
	for(int i=0;i<x;i++)
	{
		arr[i]=new int [y];
		for(int j=0;j<m;j++)
			arr[i][j]=0;
	}
	
	
	int r=edit_distance(a,b,0,0);
	cout<<r<<endl;
}
