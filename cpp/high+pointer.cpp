/*
Given a linked list with next and high pointers, populate high pointers to the next higher node, inplace and O(n).
*/

#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int val;
	struct node *next,*higher;
}node;

node *getnode(int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=n;
	temp->next=temp->higher=NULL;
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
}

void assign_high(node *head)
{
	
}

typedef struct stack
{
	node *
}

int main()
{

	node *head=getnode(3);
	node *p=head;
	
	p->next=getnode(1);
	p=p->next;
	
	p->next=getnode(5);
	p=p->next;
	
	p->next=getnode(2);
	p=p->next;
	
	p->next=getnode(3);
	p=p->next;
	
	p->next=getnode(2);
	p=p->next;
	
	p->next=getnode(6);
	p=p->next;
	
	p->next=getnode(9);
	p=p->next;
	
	display(head);
	assign_high(head);
	display(head);
}
