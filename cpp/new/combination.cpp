/*

Q) Given a digit string, return all possible letter combinations that the number could represent.

2=abc,3=def,4=ghi,5=jkl,6=mno,7=pqsr,8=tuv,9=wxyz

A mapping of digit to letters (just like on the telephone buttons) is given below.
Sample Input:
23

Sample Output:
ad, ae, af, bd, be, bf, cd, ce, cf 
*/

#include<iostream>
#include<cstdlib>

using namespace std;



string *all_combination(string input,string r[])
{
	
	//cout<<"entered";
	//string *r=(string *)malloc(sizeof(string)*input.length());
	int k=0;
	//cout<<"entered";
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='2')
		{
			r[k]="abc";
		}
		if(input[i]=='3')
			r[k]="def";
		if(input[i]=='4')
			r[k]="ghi";
		if(input[i]=='5')
			r[k]="jkl";
		if(input[i]=='6')
			r[k]="mno";
		if(input[i]=='7')
			r[k]="pqsr";
		if(input[i]=='8')
			r[k]="tuv";
		if(input[i]=='9')
			r[k]="wxyz";
			
		k++;
	}
	
	return r;
	
}

void print(string *r,int length,int index,string p)
{
	if(index==length)
	{
		cout<<p<<",  ";
		return;
	}
	else
	{
		for(int i=0;i<r[index].length();i++)
		{
			string q=p;
			p+=r[index][i];
			print(r,length,index+1,p);
			p=q;	
		}
	
	}
}

int main()
{
	
	string input="23";
	string p[input.length()];
	string *r;
	r=all_combination(input,p);
	print(r,input.length(),0,"");
}
