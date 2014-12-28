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

void display(node *root)
{
	if(root)
	{
		cout<<root->val<<" ";
		display(root->left);
		display(root->right);
	}
}

node *preorder_right(node *root,node **previous)
{
	if(root)
	{
		if(*previous)
		{
			*previous->right=root;
			*previous=root;
			preorder_right(root->left,previous);
			preorder_right(root->right,previous);
		}
		return root;
	}
}

void display_new(node *root)
{
	node *p=root;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->right;
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
	
	display(root);
	cout<<endl;
	node **previous=NULL;
	root=preorder_right(root,&previous);
	display_new(root);
	cout<<endl;
	
	
}
