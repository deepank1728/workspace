#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node
{
	int present;
	int *neighbour;
}node;


void fill_neighbour(char **a,int size,node **hash,int indexi,int indexj)
{
	for(int i=indexi-1;i<indexi+2;i++)
	{
		for(int j=indexj-1;j<indexj+2;j++)
		{
			if(j>=0 && j<size && i>=0 && i<size )
			{
				if((i==indexi && j==indexj))
					continue;
				hash[a[indexi][indexj]]->neighbour[a[i][j]]=1;
			}

		}
	}
}


void fill_hash(char **a,int size,node **hash)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			hash[a[i][j]]->present=1;
			fill_neighbour(a,size,hash,i,j);
		
		}
	}
}


int check_word(node **hash,string str)
{
	char neighbour;
	for(int i=0;i<str.length();i++)
	{
		if(hash[str[i]]->present==1)
		{
			if(i<str.length()-1)
			{
				if(hash[str[i]]->neighbour[str[i+1]])
					neighbour=str[i+1];
				else
					return 0;
			}
		}
		else
			return 0;
	}
	return 1;
}

int check(char **a,int size,string str,int indexi,int indexj,int string_index)
{
	int r=0;
	int count=0;
	
	if(string_index==str.length())
		return 1;
	
	for(int i=indexi-1;i<indexi+2;i++)
	{
		for(int j=indexj-1;j<indexj+2;j++)
		{
			if(j>=0 && j<size && i>=0 && i<size && a[i][j]==str[string_index])
			{
				
				if((i==indexi && j==indexj))
					continue;
				count++;
				int temp=a[i][j];
				a[i][j]='@';
				r+=check(a,size,str,i,j,string_index+1);
				a[i][j]=temp;
			}

		}
	}
	
	return r>0?r:0;
	
	
	
}

int main()
{
	int size=5;
	string str="MINIC";
	char **a=new char*[size];
	for(int i=0;i<size;i++)
		a[i]=new char[size];
		
	a[0][0]='A';a[0][1]='C';a[0][2]='P';a[0][3]='R';a[0][4]='C';
	
	a[1][0]='X';a[1][1]='S';a[1][2]='O';a[1][3]='P';a[1][4]='C';
	
	a[2][0]='V';a[2][1]='O';a[2][2]='V';a[2][3]='N';a[2][4]='I';
	
	a[3][0]='W';a[3][1]='G';a[3][2]='F';a[3][3]='M';a[3][4]='N';
	
	a[4][0]='Q';a[4][1]='A';a[4][2]='O';a[4][3]='I';a[4][4]='T';
	
	/*node **hash=new node*[256];

	for(int i=0;i<256;i++)
	{
		hash[i]=new node();
		hash[i]->neighbour=new int[256];
	}
		
	fill_hash(a,size,hash);
	
	int r=check_word(hash,str);
	cout<<r<<endl;
	*/
	
	int r=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(a[i][j]==str[0])
				r+=check(a,size,str,i,j,1);
		}
	}
	
	if(r>0)
		cout<<"present\n";
	else
		cout<<"not present\n";
}
