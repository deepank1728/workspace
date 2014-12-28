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

node *swap(node *head)
{
	node *p=head,*previous1=NULL,*previous2=NULL,temp;
	int i=0;
	while(p)
	{
		
		if(i%2)
		{
			if(i==1)
			{
				previous1->next=p->next;
				p->next=previous1;
				head=p;
				p=p->next;
				previous1=head;
			
			}
			
			else
			{
				previous1->next=p->next;
				p->next=previous1;
				previous2->next=p;
				previous1=p;
				p=p->next;
			
			}
		} 
		previous2=previous1;
		previous1=p;
		p=p->next;
		i++;
	}
	return head;
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


node *reverse_linklist(node *head)
{
	if(!head->next)
		return head;
	node *head2=reverse_linklist(head->next);
	node *p=head2;
	while(p->next)
	{
		p=p->next;
	}
	head->next=NULL;		//here  i made a mistake............................
	p->next=head;
	return head2;
}

node *kswapping(node *head,int k)
{
	node *p=head,*head2,*temp_head=head,*previous=head,*next,*temp_previous;
	int i=1;
	while(p)
	{
		if(i%k)
		{
			temp_previous=previous;
			next=p->next;
			p->next=NULL;
			temp_head=reverse_linklist(temp_previous);
			if(i!=k)
			previous->next=temp_head;
			if(i==k)
				head2=temp_head;
			while(temp_head->next!=NULL)
				temp_head=temp_head->next;
			temp_head->next=next;
			previous=temp_head;
			
		}
		p=p->next;
		i++;
			
	}
}

int main()
{
	node *head=getnode(0);
	node *p=head;
	for(int i=1;i<10;i++)
	{
		p->next=getnode(i);
		p=p->next;
	}	
	//head=swap(head);
	//head=reverse_linklist(head);
	head=kswapping(head,3);
	print(head);
}
