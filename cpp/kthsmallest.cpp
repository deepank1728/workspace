#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int val;
	struct node *left,*right;
}node;

node *getnode(int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=n;
	temp->left=temp->right=NULL;
	return temp;
}

node *kthsmallest(node *root,int k,int *a)
{
	node *p=NULL;
	if(root)
	{
		p=kthsmallest(root->left,k,a);
		*a=*a+1;
		if(*a==k)
		{
			if(root)
			p=root;
		}
		if(!p)
		p=kthsmallest(root->right,k,a);
		else
		kthsmallest(root->right,k,a);
		

	}
	return p;
}

int main()
{
	node *root=getnode(4);
	root->left=getnode(2);
	root->right=getnode(6);
	
	//root->left->left=getnode(1);
	root->left->right=getnode(3);
	
	//root->right->left=getnode(5);
	root->right->right=getnode(7);
	
	int a=0,k=5;
	
	node *r=kthsmallest(root,k,&a);
	if(r)
	cout<<k<<"th smallest is "<<r->val<<endl;
}
