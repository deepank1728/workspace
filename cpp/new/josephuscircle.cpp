#include<iostream>
using namespace std;

typedef struct node
{
	int val;
	struct node *next;
}node;

node *getnode(int n)
{
	node *temp=new node();
	temp->val=n;
	temp->next=temp;
	return temp;
}

void print(node *head)
{
	node *p=head->next;
	cout<<head->val<<" ";
	while(p!=head)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}


int find_last(node *head,int m)
{
	node *p=head,*q=NULL;
	int count=1;
	while(1)
	{
		if(p->next==p)
			return p->val;
		while(count!=m)
		{
			q=p;
			p=p->next;
			count++;
		}
		
		q->next=p->next;
		p=q->next;
		count=1;
	}
}
int main()
{
	node *head=getnode(1);
	node *p=head;
	int size=10,m=2;
	for(int i=2;i<size;i++)
	{
		p->next=getnode(i);
		p=p->next;
	}
	
	p->next=head;
	
	print(head);
	int r=find_last(head,m);
	cout<<r<<endl;
	
}
