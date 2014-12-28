#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	int n;
	struct node *left,*right;
}node;

node *getnode(int n)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=n;
	temp->left=temp->right=NULL;
	return temp;
}

int print_nodes(node *root,node *given,int k)
{
	if(root)
	{
		if(root==given)
		{
			
		}
		print_nodes(root->left,given,k);
		
	}
}
