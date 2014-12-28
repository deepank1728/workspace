/*
a[]={3,2,1,2,3,4};

first repeated is 3 not 2

*/

#include<iostream>
using namespace std;

typedef struct node 
{
	int val;
	int index;
	struct node *next;
}node;

node *getnode(int n,int index)
{
	node *temp=new node();
	temp->val=n;
	temp->index=index;
	temp->next=NULL;
	return temp;
}

node **create_hash(int a[],int size)
{
	node **hash=new node*[size];
	for(int i=0;i<size;i++)
	{
		if(!hash[a[i]%size])
		{
			hash[a[i]%size]=getnode(a[i],i+1);
		}
		else
		{
			node *p=hash[a[i]%size];
			while(p->next)
			{
				if(p->val==a[i])
					break;
				p=p->next;
			}
			
			if(p->val==a[i] && p->index>=0)
				p->index*=-1;
				
			else if(p->val!=a[i])
				p->next=getnode(a[i],i);
			
		}
	}
	return hash;
}

void first_repeated(int a[],int size)
{
	node **hash=create_hash(a,size);
	int max_neg;
	int max_index=-999999;
	for(int i=0;i<size;i++)
	{
		if(hash[i])
		{
			if(hash[i]->index<0 && hash[i]->index > max_index)
			{
				max_index=hash[i]->index;
				max_neg=hash[i]->val;
			}
		}
	}
	cout<<"first repeated is "<<max_neg<<endl;
}

int main()
{
	int a[]={5,1,3,2,1,2,3,4,5,3,4},size=sizeof(a)/sizeof(int);
	first_repeated(a,size);
}
