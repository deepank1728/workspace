#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node
{
	int min;
	int max;
}node;

node *getnode(int min,int max)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->min=min;
	temp->max=max;
	return temp;
}

node *min_max(int a[],int i,int j)
{
	int max,min;
	if(i==j)
	{
		min=max=a[i];
		node *m=getnode(min,max);
		return m;
	}
	else if(j==i+1)
	{
		if(a[i]>a[j])
		{
			max=a[i];
			min=a[j];
		}
		else
		{
			max=a[j];
			min=a[i];
		}
		node *m=getnode(min,max);
		return m;
	}
	else
	{
		int mid=(i+j)/2;
		node *p=min_max(a,i,mid);
		node *q=min_max(a,mid+1,j);
		
		if(p->max>q->max)
			max=p->max;
		else
			max=q->max;
		if(p->min<q->min)
			min=p->min;
		else
			min=q->min;
		p->max=max;
		p->min=min;
		return p;
	}	
}

int main()
{
	int a[]={5,3,7,15,13,4,6,23,1,11},size=10;
	
	node *r=min_max(a,0,size-1);
	cout<<r->max<<"\t"<<r->min<<endl;
}
