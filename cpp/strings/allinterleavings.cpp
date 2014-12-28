#include<iostream>

using namespace std;

void print(char a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i];
	cout<<endl;
}

void interleavings(string s1,string s2,int indexs1,int indexs2,char a[],int i)
{
	if(s1.length()+s2.length()==indexs1+indexs2)
	{
		print(a,s1.length()+s2.length());
		return;
	}
	
	if(indexs1<s1.length())
	{
		a[i]=s1[indexs1];
		interleavings(s1,s2,indexs1+1,indexs2,a,i+1);
	}
	
	if(indexs2<s2.length())
	{
		
		a[i]=s2[indexs2];
		interleavings(s1,s2,indexs1,indexs2+1,a,i+1);
	}
}

int main()
{
	string s1="AB",s2="CD";
	
	char a[s1.length()+s2.length()];
	interleavings(s1,s2,0,0,a,0);
}
