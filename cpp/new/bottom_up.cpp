/*

Print the elements in a n x m matrix diagonally and from bottom to top  . 
Eg. :  for  a simple 3×3 matrix filled with number 1 – 9 print  7 , 4 8, 1 5 9, 2 6, 3                     

*/

#include<iostream>
#include<queue>

using namespace std;

void print(int **a,int n,int m,int indexn,int indexm)
{

	queue<int > qn,qm;
	
	qn.push(indexn);
	qm.push(indexm);
	while(qn.size())
	{
		cout<<a[qn.front()][qm.front()]<<" ";
		
		
		if(qn.front()-1>-1 && qm.front()<m)
		{
			qn.push(qn.front()-1);
			qm.push(qm.front());
		}
		
		if(qm.front()+1<m && qn.front()>-1)
		{
			qn.push(qn.front());
			qm.push(qm.front()+1);
		}
		qn.pop(); qm.pop();
			
	}
			
}

int main()
{
	int n=3,m=3;
	int **a=new int*[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
	}
	
	int k=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[i][j]=k++;
		}
	}
	
	print(a,n,m,n-1,0);
	
	

}
