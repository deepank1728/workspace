/*Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). 
If the complete Binary Tree is BST, then return the size of whole tree.
*/

#include<iostream>
#include<cstdlib>
#include<algorithm>

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

int find_bst(node *root,int *max)
{
	int a=0,b=0,temp=0;
	if(root)
	{
		a=find_bst(root->left,max);
		b=find_bst(root->right,max);
		
		if(a==0 && b==0)
			return 0;
		
		if(root->left && root->right && root->left->val<=root->val && root->right->val>=root->val)
		{
			if(a==0 || b==0)
			{
				a=0;b=0;
				temp=0;
			}
			temp=a>b?a+1:b+1;
			
		}
		
		else if(!root->right && root->left && root->left->val<=root->val )
			temp=a+1;
		else if(!root->left && root->right && root->right->val>=root->val)
			temp=b+1;
		else if(!root->left && !root->right)
			temp=1;
		else
			temp=0;
		
		
		if(temp>*max)
			*max=temp;
		return temp;
	}
	return 1;
}

int main()
{
	node *root=getnode(100);
	root->left=getnode(90);
	root->right=getnode(103);
	
	root->left->left=getnode(80);
	//root->left->right=getnode(95);
	
	root->right->left=getnode(105);
	root->right->right=getnode(120);
	
	root->left->left->left=getnode(60);
	root->left->left->right=getnode(85);
	
	//root->left->right->left=getnode(93);
	//root->left->right->right=getnode(97);
	
	root->right->left->left=getnode(102);
	root->right->left->right=getnode(107);
	
	root->right->right->left=getnode(115);
	root->right->right->right=getnode(130);
	
	int max=-1;
	int r=find_bst(root,&max);
	cout<<endl;
	cout<<"max size of bst is "<<max<<endl;
	
}
