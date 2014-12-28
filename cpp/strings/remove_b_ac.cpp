#include<iostream>

using namespace std;


string remove(string a)
{
	char current=NULL,previous=NULL;
	int count=0;
	for(int i=0;i<a.length();i++)
	{
		previous=current;
		current=a[i];
		
		a[i-count]=a[i];
		if(current=='b')
		{
			count++;
			current=a[i-count];
		}
		if(previous=='a' && current=='c')
		{
			count=count+2;
		}
		
	}
	return a.substr(0,a.length()-count);
}

int main()
{
	string a="abcaacbaabcdjwcbacab";
	cout<<a<<endl;
	string p=remove(a);
	cout<<p<<endl;
	
}
