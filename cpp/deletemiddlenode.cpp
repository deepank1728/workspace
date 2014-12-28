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


int main()
{
	node *head=getnode(0);
	int size=10;
	node *p=head;
	node *middle=NULL;
	
	for(int i=1;i<size;i++)
	{
		p->next=getnode(i);
		if(i==size/2)
			middle=p;
		p=p->next;
		
	}
	display(head);
	
	
	
	
	
}
