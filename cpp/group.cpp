//Input: arr[] = {3, 6, 7, 2, 9}
//Output: 8
// Groups are {3,6}, {3,9}, {9,6}, {7,2}, {3,6,9},
// {3,7,2}, {7,2,6}, {7,2,9}


#include<iostream>
using namespace std;

int group_count(int a[],int size)
{
	int l=0,m=0,n=0;
	
	for(int i=0;i<size;i++)
	{
		if(a[i]%3==0)
			l++;
		else if(a[i]%3==1)
			m++;
		else
			n++;
	}
	int result_2group=n*m +((l*(l-1))/2);
	int result_3group=l*n*m + ((l*(l-1)*(l-2))/6)+((m*(m-1)*(m-2))/6)+((n*(n-1)*(n-2))/6);
	return result_2group+result_3group;
}


int main()
{
	int a[]={3,6,5,2,9,11},size=6;

	int result=group_count(a,size);
	cout<<result<<endl;	
	cout<<"complexity O(n)"<<endl;
	
}
