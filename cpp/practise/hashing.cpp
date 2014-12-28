#include<iostream>
using namespace std;

typedef struct node
{
	int val,count;
	struct node *next;
}node;

node *getnode(int n)
{
	node *temp=new node();
	temp->val=n;
	temp->next=NULL;
	temp->count=1;
	return temp;
}


int abs(int i)
{
	return i>=0?i:(-1*i);
}

void create_hash(int a[],node **arr,int size)
{
	
	for(int i=0;i<size;i++)
	{
		int key=abs(a[i])%size;
		if(!arr[key])
			arr[key]=getnode(a[i]);
		else
		{
			node *p=arr[key];
			node *q=NULL;
			while(p)
			{
				if(p->val==a[i])
				{
					p->count++;
					break;
				}
				q=p;
				p=p->next;
			}
			
			if(p==NULL)
				q->next=getnode(a[i]);
		}
	}
}


void print_hash(node **arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i])
		{
			node *p=arr[i];
			while(p)
			{
				cout<<p->val<<" ";
				p=p->next;
			}
		}
		cout<<endl;
	}
}

node *search(node **arr,int n,int size)
{
	int key=n%size;
	if(!arr[key])
		return NULL;
	else
	{
		node *p=arr[key];
		while(p)
		{
			if(p->val==n)
				return p;
			p=p->next;
		}
		return NULL;
	}
	
}

int main()
{
	int a[]={1,2,3,4,5,6,7,25,-3,8,9,5,12},size=sizeof(a)/sizeof(int);
	node **arr=new node*[size]();
	
	create_hash(a,arr,size);
	print_hash(arr,size);
	
	node *r=search(arr,11,size);
	
	if(r)
		cout<<"r count is "<<r->count<<endl;
	else
		cout<<"not found\n";
	
	
}
