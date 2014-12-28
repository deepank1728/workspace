/*
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. 
For example, boundary traversal of the following tree is “20 8 4 10 14 25 22″
*/

#include<iostream>
#include<cstdlib>
#include<queue>

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

void print_boundary(node *root)
{
	queue<node *> q;
	node *temp=NULL,*first=NULL,*last=NULL;
	int flag=0;
	
	q.push(root);
	q.push(NULL);
	
	while(q.size()!=0)
	{
		temp=q.front();
		q.pop();
		
		if(flag==1)
		{
			if(temp && (temp->left || temp->right))
				cout<<temp->val<<" ";
			flag=0;
		}
		if(!temp && q.size()!=0 )
		{
			if(last && (last->left || last->right))
				cout<<last->val<<" ";
			flag=1;
			q.push(NULL);
		}
		
		if(temp && !temp->left && !temp->right)
			cout<<temp->val<<" ";
		if(temp && temp->left)
			q.push(temp->left);
		if(temp && temp->right)
			q.push(temp->right);
		last=temp;
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
	
	root->left->right->left=getnode(8);
	root->left->right->right=getnode(9);
	
	print_boundary(root);
}
