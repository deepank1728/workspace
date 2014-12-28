/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
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



void display(node *head)
{
	node *p=head;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->right;
	}
}


node *convert(node *root)
{
	static node *head=NULL,*q =NULL;
	if(root)
	{
		convert(root->left);
		
		if(head==NULL)
		{
			head=root;
			q=head;
		}
		else
		{
			q->right=root;
			node *temp=q;
			q=q->right;
			q->left=temp;
		}
		convert(root->right);
		
		
	}
	return head;
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
	
	root->left->left->left =getnode(10); 
	root->left->left->right =getnode(11);
	 root->left->right->left =getnode(13); 
	 root->left->right->right =getnode(14);
	node *head=NULL;
	head=convert(root);
	display(head);

}
