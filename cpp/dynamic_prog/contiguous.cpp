

#include<iostream>

using namespace std;

int max_contiguous_sum(int a[],int size)
{
	int max,sum;
	
	
	for(int i=0;i<size;i++)
	{
		if(i==0)
			max=sum=a[0];
		else if(max<0 && a[i]<0)
			max=a[i];
		else
		{
			if(sum<0 && a[i]>0)
			{
				if(a[i]>max)
					max=a[i];
				sum=a[i];
			}
			else if(sum)
			{
				sum+=a[i];
				if(sum>max)
					max=sum;
			}
		}
	}
	
	return max;

}

int main()
{
	int a[]={-2,11,4,-13,5,-2},size=6;
	
	int r =max_contiguous_sum(a,size);
	cout<<"max contiguous sum is "<<r<<endl;
}
