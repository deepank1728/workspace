/*

How to implement a stack which will support following operations in O(1) time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
Push and pop are standard stack operations.

*/


#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int val;
	struct node *next,*previous;
}node;

node *getnode(int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=n;
	temp->next=temp->previous=NULL;
	return temp;
}

typedef struct stack
{
	node *head;
	node *tail;
	int node_count;
	node *middle;
}stack;

stack *create_stack(stack *s)
{
	s->head=NULL;
	s->tail=NULL;
	s->node_count=0;
	s->middle=NULL;
}

void push(stack *s,int n)
{
	if(s->head==NULL)
	{
		s->tail=s->head=getnode(n);
		s->node_count++;
		s->middle=s->tail;
	}
	else
	{
		s->tail->next=getnode(n);
		s->tail->next->previous=s->tail;
		s->tail=s->tail->next;
		s->node_count++;
		if(s->node_count%2!=0)
		{
			s->middle=s->middle->next;
		}
	}
}

int pop(stack *s)
{
	int result;
	if(s->head==NULL)
	{
		cout<<"stack empty\n";
		return NULL;
	}
	else
	{
		result=s->tail->val;
		
		s->tail=s->tail->previous;
		s->tail->next=NULL;
		s->node_count--;
		
		if(s->node_count%2==0)
			s->middle=s->middle->previous;
			
	}
	return result;
}

int find_middle(stack *s)
{
	return s->middle->val;
}

void delete_middle(stack *s)
{
	if(s->node_count==0)
	{
		cout<<"stack empty\n";
	}
	node *temp=NULL;
	s->node_count--;
	if(s==0)
	{
		int r=s->head->val;
		s->head=s->tail=s->middle=NULL;
		return;
	}
		temp=s->middle->next;
		s->middle=s->middle->previous;
		s->middle->next=temp;
		s->middle->next->previous=s->middle;
	
	if(s->node_count%2!=0)
	{
		s->middle=s->middle->next;
	}
		
	
	
}

void display(stack *s)
{
	node *p=s->head;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	pop(s);
	int size=10;
	for(int i=0;i<size;i++)
	{
		push(s,i);
	}
	
	display(s);
	cout<<"middle is "<<find_middle(s)<<endl;
	cout<<"poped element is "<<pop(s)<<endl;
	cout<<"poped element is "<<pop(s)<<endl;
	cout<<"poped element is "<<pop(s)<<endl;
	display(s);
	
	
	cout<<"middle is "<<find_middle(s)<<endl;
	delete_middle(s);
	cout<<"after middle deleted \n";
	display(s);
	cout<<"middle is "<<find_middle(s)<<endl;
	delete_middle(s);
	cout<<"after middle deleted \n";
	display(s);
	cout<<"middle is "<<find_middle(s)<<endl;
	
	
	
	

	
	
}
