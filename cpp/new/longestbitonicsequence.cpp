#include<iostream>

using namespace std;

int bitonic(int *a,int size,int index,int previous,int sign)
{
	if((sign==-1 && index<0)|| (sign==1 && index>=size))
		return 0;
	
	if(sign==-1)
	{
	
		if(a[index]<=a[previous])
		{
			
			int count=bitonic(a,size,index-1,index,-1);
			//cout<<a[index]<<" ";
			count++;
			return count;
		}
		else
		{
			int count=bitonic(a,size,index-1,previous,-1);
			return count;	
		}
		
	}
	
	if(sign==1)
	{
		if(a[index]<=a[previous])
		{
			//cout<<a[index]<<" ";
			int count=bitonic(a,size,index+1,index,1);
			count++;
			return count;
		}
		else
		{
			int count=bitonic(a,size,index+1,previous,1);
			return count;	
		}
		
	}

}


int main()
{
	int a[]={10 ,9, 5, 7, 9, 1, 3, 4, 5, 8, 12, 13, 11, 12, 9, 6},size=16,max=0,middle;
	for(int i=0;i<size;i++)
	{
		int x=bitonic(a,size,i-1,i,-1);
		int y=bitonic(a,size,i+1,i,1);
		
		int count=1+x+y;
		if(count>max)
		{
			max=count;
			middle=i;
		}
	}
	
	cout<<max<<endl;
	cout<<middle<<endl;


}
