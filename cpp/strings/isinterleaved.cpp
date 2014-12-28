#include<iostream>
#include<cstdlib>

using namespace std;

int is_interleaved(string s1,string s2,string s3,int indexs1,int indexs2,int indexs3)
{
	if(indexs3==s3.length())
		return 1;
	
	int r=0;
	if(s3[indexs3]==s1[indexs1])
		r=is_interleaved(s1,s2,s3,indexs1+1,indexs2,indexs3+1);
	else if(s3[indexs3]==s2[indexs2])
		r=is_interleaved(s1,s2,s3,indexs1,indexs2+1,indexs3+1);
	
	if(r==1)
		return 1;
	else
		return 0;
	
}

int main()
{
	string s1="AB",s2="CD",s3="ACBD";
	
	int r=is_interleaved(s1,s2,s3,0,0,0);
	cout<<r<<endl;
}
