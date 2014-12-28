/*
In a Red-Black Tree, the maximum height of a node is at most twice the minimum height (The four Red-Black tree properties make sure this is always followed).
 Given a Binary Search Tree, we need to check for following property.
 */
 
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

int is_balanced(node *root)
{
	int left=0,right=0;
	if(root)
	{
		left=is_balanced(root->left);
		right=is_balanced(root->right);
		
		if(left== -1 || right==-1)
			return -1;
			
		if(left>right+1 || right>left+1)
			return -1;
		return left>right?left+1:right+1;	
	}
}

int main()
{
	node *root=getnode(3);
	root->left=getnode(4);
	root->right=getnode(6);
	
	
	root->left->left=getnode(5);
	
	int r=is_balanced(root);
	if(r==-1)
		cout<<"not balanced\n";
	else
		cout<<"balanced\n";
}
