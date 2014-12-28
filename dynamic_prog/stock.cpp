#include<iostream>

using namespace std;


void find_date(int a[],int size)
{
	int min=-10000,diff=0,count,enddate,startdate;
	for(int i=0;i<size;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			diff=0;
		}
		else
		{
			count_temp++;
			diff_temp=a[i]-min;
			if(diff_temp>maxdiff)
			{
				maxdiff=diff_temp;
				enddate=i;
				
			}
		}
	}
}

int main()
{
	a[]={100, 180, 260, 310, 40, 535, 695},size=7;
	
	find_date(a,size);
}

