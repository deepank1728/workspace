/*
Given a Balanced Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, 
otherwise return false. Expected time complexity is O(n) and only O(Logn) extra space can be used. 
Any modification to Binary Search Tree is not allowed. Note that height of a Balanced BST is always O(Logn).
*/
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

node *exor_result(node *root,int sum)
{
	if(root)
	{
		exor_result(root->left,sum);
		root->val^=sum;
		exor_result(root->right,sum);
	}	
	reutrn root;
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
	
	int sum;
	sum=12;
	
	display(root);
	cout<<endl;
	
	root=exor_result(root,sum);
	
	int find=find_node(root);
	display(root);
	cout<<endl;
}
