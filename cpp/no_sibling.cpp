/*
Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. 
In a Binary Tree, there can be at most one sibling). Root should not be printed as root cannot have a sibling.
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

void print_no_sibling(node *root)
{
	queue<node *> q;
	node *temp=NULL,*last2=NULL,*last=NULL;
	int flag=0;
	
	q.push(root);
	
	while(q.size()!=0)
	{
		temp=q.front();
		q.pop();
	
		if(temp && temp->left)
			q.push(temp->left);
		if(temp && temp->right)
			q.push(temp->right);
			
		if(temp->left && !temp->right)
			cout<<temp->left->val<<" ";
		if(!temp->left && temp->right)
			cout<<temp->right->val<<" ";
		
		
	}
}

int main()
{
	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->right=getnode(5);
	
	root->right->right=getnode(7);
	
	root->left->right->right=getnode(9);
	
	print_no_sibling(root);
}
