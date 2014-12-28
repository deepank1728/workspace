#include<iostream>

using namespace std;


void longest(string a)
{
	char low,high;
	int max=0;
	for(int i=1;i<a.length();i++)
	{
		low=i-1;
		high=i;
		
		int j=0;
		int count_even=0;
		while((low-j)>=0 && (high+j)<a.length())
		{
			if(a[low-j]==a[high+j])
			{
				count_even++;
				j++;
				if(count_even>max)
					max=count_even;
			}
			else
				break;
			
		}
		
		j=0;
		low=i-1;
		high=i+1;
		int count_odd=1;
		while((low-j>=0) && (high+j)<a.length())
		{
			if(a[low-j]==a[high+j])
			{
				count_odd++;
				j++;
				if(count_odd>max)
					max=count_odd;
			}
			else
				break;
		}
	}
	
	cout<<max<<endl;

}

int main()
{
	string a="forgeeksskeegfor";
	cout<<a<<endl;
	longest(a);

}
