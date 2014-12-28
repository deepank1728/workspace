#include<iostream>
 #include<cstdlib>
 
 using namespace std;
 
 
 typedef struct node
 {
 	int val;
 	int count;
 	struct node *next;
 	struct node *element;
 }node;
 
 node *getnode(int n)
 {
 	node *temp=(node *)malloc(sizeof(node));
 	temp->val=n;
	temp->next=NULL;
 	return temp;
 }
 
 node *getnode2(int n,node *element)
 {
 	node *temp=(node *)malloc(sizeof(node));
 	temp->val=n;
 	temp->count=1;
 	temp->element=element;
 	return temp;
 }
 void create_hash(node *head,node **array,int length)
 {
	node *p,*q=NULL,*a=head,*b=NULL;
	
	while(a!=NULL)
	{
		int key=a->val%length;
			if(key<0)
				key=-1*key;
			if(array[key]==NULL)
				array[key]=getnode2(a->val,a);
			else
			{
				if(array[key]->val==a->val)
				{
					array[key]->count++;
				}
				else
				{
					p=array[key];
					while(p!=NULL)
					{
						if(p->val==a->val)
						{
							p->count++;
							break;
						}
						q=p;
						p=p->next;
					}
					if(p==NULL)
						q->next=getnode2(a->val,a);
				}
			}
			a=a->next;
	}
	
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
 
 node *remove_dupli(node *head,node **array,int size)
 {
 	node *p,*q=head;
 	int count=0;
 	for(int i=0;i<size;i++)
 	{
 		if(array[i])
 		{
 			p=array[i];
 			while(p)
 			{
 				if(count==0)
 				{
 					head=p;
 					q=head;
 					count=1;
 				}
 				else
 				{
 					q->next=p;
 					q=q->next;
 				}
 				p=p->next;
 				
 				
 			}
 		}
 		
 	}
 	return head;
 }
 int find_length(node *head)
 {
 	node *p=head;
 	int count=0;
 	while(p)
 	{
 		count++;
 		p=p->next;
 	}
 	return count;
 }
 int main()
 {
 	node *head=getnode(0);
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
	int length=find_length(head);
	node **array=(node **)malloc(sizeof(node *)* length);
	create_hash(head,array,length);
	
	head=remove_dupli(head,array,length);
	display(head);
	
 }
