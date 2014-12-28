/*Given a singly linked list, swap kth node from beginning with kth node from end. 
Swapping of data is not allowed, only pointers should be changed.
*/
// 0 1  2 3 4 5 6 7 8 9
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

node *swap_kthnode(node *head,int k)
{
	node *p=head,*q=head,*ele1=NULL,*ele2=NULL,*temp1,*temp2;
	int size=0,counter=0;
	
	while(p!=NULL)
	{
	
		p=p->next;
		size++;
	}
	cout<<size<<endl;
	p=head;
	if((size-k-1)<k)
	k=size-k-1;
	
		cout<<"in\n";
		for(int i=0;i<(size-1)-k;i++)
		{
			if(i==k)
			{
				cout<<"yes\n";
				ele1=p;
				temp1=q;
			}
			q=p;
			p=p->next;
		}
	
		ele2=p;
		temp2=ele2->next;
		if(ele1==ele2)
			return head;
		else if(ele1->next==ele2)
		{
			ele1->next=ele2->next;
			temp1->next=ele2;
			ele2->next=ele1;
		}
		else
		{
			temp1->next=ele2;
			ele2->next=ele1->next;
			q->next=ele1;
			ele1->next=temp2;
		}
		
	
	return head;
	
	
}

int main()
{
	node *head=getnode(0);
	int size=10;
	node *p=head;
	
	for(int i=1;i<size;i++)
	{
		p->next=getnode(i);
		p=p->next;
	}
	
	display(head);
	int k=9;
	head=swap_kthnode(head,k);
	
	display(head);
	
}
