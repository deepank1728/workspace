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

int get_level(node *root,node *r,int level)
{
	int l=-1;
	if(root)
	{
		if(root==r)
			return level;
		else
		{
			l=get_level(root->left,r,level+1);
			if(l==-1)
			l=get_level(root->right,r,level+1);
			
		}
	}
	return l;
}

int main()
{
	node *root=getnode(4);
	root->left=getnode(2);
	root->right=getnode(6);
	
	root->left->left=getnode(1);
	root->left->right=getnode(3);
	
	root->right->left=getnode(5);
	root->right->right=getnode(7);
	
	root->right->left->right=getnode(8);
	root->right->left->right->left=getnode(9);
	
	int a=0,k=5;
	
	int r=get_level(root,root->right->left->right->left,0);
	if(r!=-1)
	cout<<"level is "<<r<<endl;
}
