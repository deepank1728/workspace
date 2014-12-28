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

int ismirror(node *root1,node *root2)
{
	int a=0;
	if((root1 && !root2) ||(!root1 && root2))
		return -1;
	if(root1 && root2)
	{
		if(a>0)
			return a;
	
		else if(root1->val!=root2->val)
			return 1;
		else
		{
			a=ismirror(root1->left,root2->left);
			a+=ismirror(root1->right,root2->right);
			return a;
		}
	}
}

int main()
{
	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->left=getnode(4);
	root->left->right=getnode(5);
	
	root->right->left=getnode(6);
	root->right->right=getnode(7);
	
	node *root2=getnode(1);
	root2->left=getnode(2);
	root2->right=getnode(3);
	
	root2->left->left=getnode(4);
	root2->left->right=getnode(5);
	
	root2->right->left=getnode(6);
	root2->right->right=getnode(8);
	
	int r=ismirror(root,root2);
	
	if(!r)
		cout<<"is mirror\n";
	else
		cout<<"is not mirror\n";
}
