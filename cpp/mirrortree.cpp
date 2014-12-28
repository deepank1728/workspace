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

node *mirror(node *root,int level)
{
	if(root)
	{
		root->left=mirror(root->left,level+1);
		root->right=mirror(root->right,level+1);
		
		node *temp=NULL;
		if(level%2==0)
		{
			temp=root->left;
			root->left=root->right;
			root->right=temp;
		}
		return root;
	}
	
}


void display(node *root)
{
	if(root)
	{
		display(root->left);
		cout<<root->val<<" ";
		display(root->right);
	}
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
	
	int max=0;
	display(root);
	cout<<endl;
	root=mirror(root,0);
	display(root);
	cout<<endl;
	
	
}
