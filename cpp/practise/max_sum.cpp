/*
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.
*/

#include<iostream>
using namespace std;

int main()
{
	int a1[]={2, 3, 7, 10, 12, 15, 30, 34},size1=sizeof(a1)/sizeof(int);
	int a2[]={1, 5, 7, 8, 10, 15, 16, 19},size2=sizeof(a2)/sizeof(int);
	
	int sum1=0,sum2=0,final_sum=0,i=0,j=0;
	
	while(i<size1 && j<size2)
	{
		if(a1[i]==a2[j])
		{
			sum1+=a1[i++];
			sum2+=a2[j++];
			final_sum+=sum1>sum2?sum1:sum2;
			sum1=sum2=0;
		}
		
		if(a1[i]>a2[j])
			sum2+=a2[j++];
		
		if(a1[i]<a2[j])
			sum1+=a1[i++];
	}
	
	while(j<size2)
		sum2+=a2[j++];
	
	while(i<size1)
		sum1+=a1[i++];

	final_sum+=sum1>sum2?sum1:sum2;
	
	cout<<final_sum<<endl;
}
