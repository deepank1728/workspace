/*

Given an input string, write a function that returns the Run Length Encoded string for the input string.

For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

*/

#include<iostream>
using namespace std;

string runlength_encoding(string a)
{
	int count=0;
	char ch;
	string r;
	for(int i=1;i<a.length();i++)
	{
		count=1;
		ch=a[i-1];
		while(a[i-1]==a[i] && i<a.length())
		{
			count++;
			i++;
		}
		
		r+=ch;
		r+=count+48;	
		if(i==a.length()-1 && a[i-1]!=a[i])
			r+=a[i];
		
	}
	return r;
}

using namespace std;

int main()
{
	string a="wwwwaaadexxxxxx";
	string r=runlength_encoding(a);
	cout<<r<<endl;
}
