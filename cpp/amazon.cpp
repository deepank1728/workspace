//4 6 8 3 6   27
//-2 -2 5 -3  -2
//0 -7 8 		1
//7 -15
//22

#include<iostream>

using namespace std;

int sum_iteration(int a[],int size,int iteration)
{
	int count=0,sum=0;
	int *temp=a;
	for(count=0;count<iteration;count++)
	{
		sum=0;
		for(int i=0;i<size-count;i++)
		{
			if(i<size-count-1)
			{
				temp[i]=temp[i]-temp[i+1];
				sum+=temp[i];
			}
				
		}
	}
	return sum;
}

int main()
{
	int a[]={4,6,8,3,6},size=5;
	int iteration=1;
	if(iteration>=size)
		cout<<"invalid iterations\n";
	int result=sum_iteration(a,size,iteration);
	cout<<result<<endl;
}
