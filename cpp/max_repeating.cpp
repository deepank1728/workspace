#include<iostream>
#include<algorithm>

using namespace std;

int max_repeating(int a[],int size)
{
	sort(a,a+size);
	int max_num=-100000,max_count=0,temp_num=0,temp_count=0;
	
	for(int i=0;i<size-1;i++)
	{
		if(a[i]==a[i+1])
		{
			temp_count++;
			temp_num=a[i];
		}
		if(a[i]!=a[i+1])
		{
			if(temp_count>max_count)
			{
				max_num=temp_num;
				max_count=temp_count;
			}
			temp_count=0;
		}
	}
	
	if(max_num==-100000)
	{
		cout<<"no repeating element\n";
		return -100000;
	}
	return max_num;
}


int main()
{
	int a[]={1,4,2,5,3,6,4,7,2,4,3,4,2,4,5,4,2,2,2,2},size=20;
	int result=max_repeating(a,size);
	cout<<result<<endl;
}
