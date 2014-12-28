
/*
Delete nodes which have a greater value on right side Given a singly linked list,
 remove all the nodes which have a greater value on right side. Examples: 
 a) The list 12->15->10->11->5->6->2->3->NULL should be changed to 15->11->6->3->NULL. 
 Note that 12, 10, 5 and 2 have been deleted because there is a greater value on the right side.

*/

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

node *delete_node(node *head)
{
	node *p=head,*q=NULL,*temp;
	
	static node *max,*head2;
	
	if(p->next)
	{
		delete_node(p->next);
		if(p->val>=max->val)
		{
			temp=head2;
			head2=p;
			head2->next=temp;
			max=p;
		}
			
	}
	else
	{
		max=p;
		head2=p;
	}
	
	return head2;
}

int main()
{
	node *head=getnode(80);
	node *p=head;
	p->next=getnode(70);
	p=p->next;
	
	p->next=getnode(60);
	p=p->next;
	
	p->next=getnode(50);
	p=p->next;
	
	p->next=getnode(40);
	p=p->next;
	
	p->next=getnode(30);
	p=p->next;
	
	p->next=getnode(20);
	p=p->next;
	
	p->next=getnode(10);
	p=p->next;
	
	head=delete_node(head);
	display(head);
	
	
	
	

}
