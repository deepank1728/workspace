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


int convert(node *root,int sum)
{
	int t=0;
	if(root)
	{
		sum=convert(root->right,sum);
		root->val+=sum;
		sum=root->val;
		sum=convert(root->left,sum);
	}
	return sum;
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
	
	display(root);
	cout<<endl;
	convert(root,0);
	display(root);
	cout<<endl;
}
