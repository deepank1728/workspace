#include<iostream>

using namespace std;


int findlcs(string a,string b,int i,int j)
{
	if(a.length()==i || b.length()==j)
		return 0;
	
	if(a[i]==b[j])
	{
		cout<<a[i]<<" ";
		return 1+findlcs(a,b,i+1,j+1);
	}
	
	if(a[i]!=b[j])
		return findlcs(a,b,i+1,j)>findlcs(a,b,i,j+1)?findlcs(a,b,i+1,j):findlcs(a,b,i,j+1);

}


int main()
{
	string a="deepank";
	string b="epaden";
	
	int r=findlcs(a,b,0,0);
	cout<<r<<endl;
}
