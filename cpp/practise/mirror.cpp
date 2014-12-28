#include<iostream>

using namespace std;

typedef struct node
{
	int val;
	struct node *left,*right;
}node;

node *getnode(int n)
{
	node *temp=new node();
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

node *mirror(node *root)
{
	node *h=NULL;
	if(root)
	{
		h=getnode(root->val);
		h->left=mirror(root->right);
		h->right=mirror(root->left);
	}
	return h;
}

node *mirror_inplace(node *root)
{
	if(root)
	{
		root->left=mirror_inplace(root->left);
		root->right=mirror_inplace(root->right);
		
		node *temp=root->right;
		root->right=root->left;
		root->left=temp;
	}
	return root;
}

int main(){

	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->left=getnode(4);
	root->left->right=getnode(5);
	
	root->right->left=getnode(6);
	root->right->right=getnode(7);
	
	node *h=mirror(root);
	display(root);
	cout<<endl;
	display(h);
	cout<<endl;
	display(root);
	cout<<endl;
	root=mirror_inplace(root);
	display(root);
	cout<<endl;
}

