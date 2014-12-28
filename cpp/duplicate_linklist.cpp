#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int val;
	struct node *next;
}node;

node *getnode(int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=n;
	temp->next=NULL;
	return temp;
}

void display(node *head)
{
	node *p=head;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}

node *remove_duplicate(node *head)
{
	node *p=head,*q=NULL,*t=head;
	
	while(t!=NULL)
	{
		
		while(p!=NULL)
		{
			if(p==t)
			{
				q=p;
				p=p->next;
				
			}
			if(p)
			{
				if(p->val==t->val)
				{
					q->next=p->next;
					p=q;
				}
			}
			
			q=p;
			p=p->next;
		}
		t=t->next;
		p=head;
	}
	
	return head;
}

int main()
{
	node *head=getnode(0);
	int size=10;
	node *p=head;
	node *middle=NULL;
	
	p->next=getnode(5);
	p=p->next;
	
	p->next=getnode(3);
	p=p->next;
	
	p->next=getnode(2);
	p=p->next;
	
	p->next=getnode(3);
	p=p->next;
	
	p->next=getnode(5);
	p=p->next;
	
	p->next=getnode(2);
	
	display(head);
	
	head=remove_duplicate(head);
	display(head);
	
	
	
	
	
}
