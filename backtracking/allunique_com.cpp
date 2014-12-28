#include<iostream>
#include<cstdlib>

using namespace std;


void print(string a,int count)
{
	char temp;
	if(count==a.length())
	{
		cout<<a<<endl;
		return;
	}
	
	for(int i=count;i<a.length();i++)
	{
		if(a[i]==a[count] && i!=count)
			continue;
		temp=a[i];
		a[i]=a[count];
		a[count]=temp;
		print(a,count+1);
	}
}

int main()
{
	string a="baad";
	char arr[a.length()];
	print(a,0);
}
