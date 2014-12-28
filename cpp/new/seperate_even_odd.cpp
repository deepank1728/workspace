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
	temp->next=NULL;
	return temp;
}

void print(node *head)
{
	node *p=head;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}

node *seperate_even_odd(node *head)
{
	node *p=head,*q=NULL;
	
	while(p)
	{
		if(p->val%2==0 && p!=head)
		{
			q->next=p->next;
			p->next=head;
			head=p;
			p=q;
		}
		q=p;
		p=p->next;
	}
	return head;
}

int main()
{
	node *head=getnode(1);
	node *p=head;
	int size=10;
	for(int i=2;i<size;i++)
	{
		p->next=getnode(i);
		p=p->next;
	}
	
	print(head);
	head=seperate_even_odd(head);
	print(head);
	
}
