/*
Given a binary matrix, print all unique rows of the given matrix
*/


#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int **row;
	
}


void makehashtable(int a[4][5],int *arr,int n,m)
{
	for(int i=0;i<n;i++)
	{
		int hash=0;
		for(int j=0;j<m;j++)
		{
			if(a[j]==1)
				hash++;
		}
		if(!arr[hash])
			arr[hash]=getnode(a[i]);
		else
		{
			int count=0;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]!=arr[hash]->row[j])
				{
					count++;
					break;
				}
			}
			
			for(int k=0;k<n;k++)
			{
				
			}
		}
	}
}


int main()
{
	int a[4][5]={{0,1,0,0,1},{1,0,1,1,0},{0,1,0,0,1},{1,1,1,0,0}},n=4,m=5;
	
	node *arr=(node *)malloc(sizeof(node)*n);
	makehashtable(a,arr,n,m);
	
	

}
