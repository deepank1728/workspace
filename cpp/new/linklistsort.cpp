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

node *insert(node *head,node *h)
{
	node *p=head;
	if(p==NULL)
	{
		head=h;
		head->next=NULL;
	}
	else
	{
		while(p->next)
			p=p->next;
		p->next=h;
		
		p=p->next;
		if(p)
			p->next=NULL;
	}
	return head;
}

node *join(node *less,node *equal,node *greater)
{
	node *head2=NULL;
	node *p=less;
	if(p)
	{
		head2=p;
		while(p->next)
			p=p->next;
			
		p->next=equal;
		while(p->next)
			p=p->next;
		p->next=greater;
	}
	
	else
	{
		head2=equal;
		p=head2;
		
		while(p->next)
			p=p->next;
		p->next=greater;
	}
	
	return head2;
}


node *quick_sort(node *head)
{
	node *pivot=head;
	node *p=head,*less=NULL,*equal=NULL,*greater=NULL;
	
	if(!head)
		return NULL;
	
	if(head->next==NULL)
		return head;
	
	while(p)
	{
		if(p->val>pivot->val)
		{
			node *temp=p->next;
			greater=insert(greater,p);
			p=temp;
		}
		else if(p->val<pivot->val)
		{
			node *temp=p->next;
			less=insert(less,p);
			p=temp;
		}
		else if(p->val==pivot->val)
		{
			node *temp=p->next;
			equal=insert(equal,p);
			p=temp;
		}
				
	}
	
	greater=quick_sort(greater);
	less=quick_sort(less);
	
	node *head2=join(less,equal,greater);
	return head2;
}


int main()
{
	node *head=getnode(1);
	head->next=getnode(0);
	head->next->next=getnode(3);
	node *p=head->next->next;
	
	p->next=getnode(2);
	p->next->next=getnode(5);
	p->next->next->next=getnode(4);
	node *q=p->next->next->next;
	q->next=getnode(-3);
	
	
	head=quick_sort(head);
	print(head);
}
