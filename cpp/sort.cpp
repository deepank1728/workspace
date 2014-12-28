//Input: arr[] = {0, 23, 14, 12, 9}
//Output: arr[] = {0, 9, 12, 14, 23}

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



void create_hash(int a[],int size,node** array)
{
	node *p,*q;
	for(int i=0;i<size;i++)
	{
		if(array[a[i]/size]==NULL)
			array[a[i]/size]= getnode(a[i]);
		else
		{
			node *p=array[a[i]/size];
			if(a[i]<=p->val)
			{
				array[a[i]/size]=getnode(a[i]);
				array[a[i]/size]->next=p;
			}
			else
			{
				while(p->next!=NULL)
				{
					if(p->next==NULL && p->val<=a[i])
						{
							p->next=getnode(a[i]);
						}
					
					if(p->val>=a[i] && q->val<=a[i])
					{
						q->next=getnode(a[i]);
						q->next->next=p;
						break;
					}
					q=p;
					p=p->next;
				}
			}
		}
	}
}


int main()
{
	int a[]={0,23,14,12,9,0,6},size=7;
	node **array;

	
	array=(node **)malloc(sizeof(node *) *size);
	create_hash(a,size,array);
		
		
		for(int i=0;i<size;i++)
		{
			if(array[i])
			{
				while(array[i]!=NULL)
				{
					cout<<array[i]->val<<" ";
					array[i]=array[i]->next;
				}
			}
		}
}
