/*

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void print(int a[],int size,int k)
{

	queue<int> q1;
	vector<int> q2;
	vector<int >::iterator it;
	int temp;
	for(int i=0;i<size;i++)
	{
		if(i<k)
		{
			q1.push(a[i]);
			if(i==0)
			{
				q2.push_back(a[i]);
				temp=a[i];
			}
			else if(a[i]>temp)
			{
				q2.push_back(a[i]);
				temp=a[i];
			}
			else
			q2.push_back(temp);
			
			if(i==2)
			{
				it=q2.end();
				it--;
				cout<<*it<<" ";
				q1.pop();
				q2.erase(q2.begin());
				it=q2.end();
				temp=*it;
			}
		}
		else
		{
			q1.push(a[i]);
			if(a[i]>temp)
			{
				q2.push_back(a[i]);
				temp=a[i];
			}
			else
				q2.push_back(temp);
			
			it=q2.end();
			it--;
			cout<<*it<<" ";
			q1.pop();
			q2.erase(q2.begin());
			it=q2.end();
				temp=*it;
		
		}
	}
}

int main()
{
	int a[]= {6,1 ,2, 5, 3, 1, 24, 7},size=8,k=3;
	print(a,size,k);
}
