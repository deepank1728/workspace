/*

Count number of binary strings without consecutive 1′s

*/

#include<iostream>
#include<cstdlib>
using namespace std;

int count(int n,int index,int *z_start,int *o_start)
{
	if(n==index)
		return 2*(z_start[n-1])+o_start[n-1];
	
	z_start[index]=o_start[index-1]+z_start[index-1];
	o_start[index]=z_start[index-1];
	count(n,index+1,z_start,o_start);
}


int main()
{
	int n=3;
	int z_start[n+1],o_start[n+1];
	z_start[1]=1;o_start[1]=1;
	int r=count(n,2,z_start,o_start);
	cout<<r<<endl;
}
