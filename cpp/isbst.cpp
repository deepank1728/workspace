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

node *isbst(node *root,int *a)
{
	node *previous=NULL;
	if(root)
	{
		previous=isbst(root->left,a);
		if(previous)
		{
			if(root->val<previous->val)
				*a=1;
		}
		isbst(root->right,a);
		previous=root;
	}
	return previous;
	
}

int main()
{
	node *root=getnode(4);
	root->left=getnode(2);
	root->right=getnode(4);
	
	root->left->left=getnode(1);
	root->left->right=getnode(3);
	
	root->right->left=getnode(4);
	root->right->right=getnode(8);
	int result=0;
	isbst(root,&result);
	if(!result)
		cout<<"it is bst\n";
	else
		cout<<"its not a bst\n";
}
