#include<iostream>

using namespace std;

void reverse(string a,int index)
{
	if(index==a.length())
		return;
		
	reverse(a,index+1);
	cout<<a[index];
	
}

int main()
{
	string a="deepankporwal";
	reverse(a,0);
	//cout<<a<<endl;
}
