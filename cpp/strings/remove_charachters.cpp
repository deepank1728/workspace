/*

Write an efficient C function that takes two strings as arguments and removes the characters from first string which are present in second string (mask string).
*/

#include<iostream>

using namespace std;

int main()
{
	string s1="deepankporwal";
	string s2="hemant";
	
	int a[256];
	
	for(int i=0;i<256;i++)
		a[i]=0;
		
	for(int i=0;i<s1.length();i++)
		a[s1[i]]++;
	
	for(int i=0;i<s2.length();i++)
		a[s2[i]]=0;
	
	int j=0;
	for(int i=0;i<s1.length();i++)
	{
		if(a[s1[i]]>0)
			s1[j++]=s1[i];
	}
	//s1=s1.substr(0,s1.length()-j+1);
	cout<<s1<<endl;
}
