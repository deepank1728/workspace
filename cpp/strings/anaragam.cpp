#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

void anargams(string a,int count)
{
	string p=a;
	char temp;
	if(count==a.length())
	{
		cout<<a<<"\t";
		return;
	}
	
	for(int i=count;i<a.length();i++)
	{
		if(a[i]==a[count] && i!=count)
			continue;
		temp=a[count];
		a[count]=a[i];
		a[i]=temp;
		anargams(a,count+1);
	}
	
	
}

int main()
{
	string a="abad";
	anargams(a,0);
}
