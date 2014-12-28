#include<iostream>
#include<cstring>
using namespace std;

int naive_matching(string s1,string s2)
{
	for(int i=0;i<s1.length();i++)
	{
		int k=i;
		for(int j=0;j<s2.length();j++)
		{
			if(s1[k]==s2[j])
			{
				k++;
			}
			else
				break;
		}
		
		if(k-i==s2.length())
			return 1;
			
	}
	return 0;
}

int main()
{
	string s1="abcd";
	string s2="cdab";
	string s3=s1+s1;
	
	int r=naive_matching(s3,s2);
	cout<<r<<endl;
}
