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

int height(node *root)
{
	int left,right;
	if(root)
	{
		left=height(root->left);
		right=height(root->right);
		return left>right?left+1:right+1;
	}
	
}

int diameter(node *root,int *max)
{
	int left=0,right=0,temp=0;
	if(root)
	{
		left=diameter(root->left,max);
		right=diameter(root->right,max);
		
		if(left>right)
			temp=left+1;
		else
			temp=right+1;
		if(left+right>*max)
			*max=left+right;
		return temp;
	}
	return 0;
}

int main()
{
	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->left=getnode(4);
	root->left->left->left=getnode(5);
	
	
	root->left->left->right=getnode(11);
	root->left->left->right->left=getnode(13);
	root->left->left->right->left->left=getnode(14);
	root->left->left->right->left->right=getnode(15);
	
	root->left->right=getnode(16);
	root->left->right->right=getnode(17);
	root->left->right->right->left=getnode(18);
	root->left->right->right->right=getnode(19);
	root->left->right->right->right->right=getnode(20);
	
	root->right->right=getnode(7);
	
	
	int h=height(root);
	cout<<"height of tree is "<<h<<endl;
	
	int max=0;
	int d=diameter(root,&max);
	cout<<"diameter is "<<max+1<<endl;
}
