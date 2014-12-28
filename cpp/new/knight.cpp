#include<iostream>

using namespace std;

int main()
{
	int a[8][8],size=8;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			a[i][j]=0;
	}
	
	find_path(a);

}
