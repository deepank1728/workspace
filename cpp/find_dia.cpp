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

int find_dia(node *root,int l)
{
	int left=0,right=0;
	if(root)
	{
		left=find_dia(root->left,l+1);
		right=find_dia(root->right,l+1);
		return left>right?left:right;
		
	}
	return 1;
	
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
	int r=find_dia(root,0);
	cout<<r<<endl;
	
	
}
