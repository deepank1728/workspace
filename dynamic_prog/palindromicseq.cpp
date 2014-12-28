#include<iostream>
#include<cstdlib>

using namespace std;

int longest_palindromic(string a,int start,int end)
{

	int b[end+1][end+1];
	for(int i=0;i<=end;i++)
	{
		for(int j=0;j<=end;j++)
			b[i][j]=0;
	}
	
	if(start==end)
		return 1;
	if(end==start+1)
	{
		if(a[start]==a[end])
		return 2;
		return 1;
	}
	
	int x,y;
	if(a[start]==a[end])
	{
		x=2+longest_palindromic(a,start+1,end-1);
		return x;
	}
	
	x=longest_palindromic(a,start+1,end);
	y=longest_palindromic(a,start,end-1);
	return x>y?x:y;
}


int main()
{
	string a="adxcabacabaz";
	int c[12][12];
	int r=longest_palindromic(a,0,a.length()-1);
	cout<<r<<endl;
}
