/*
Given a Binary Tree, find the deepest leaf node that is left child of its parent.
 For example, consider the following tree. The deepest left leaf node is the node with value 9.
 */
 
 
 #include<iostream>
 #include<cstdlib>
 
 using namespace std;
 
 typedef struct node_link
 {
 	int val;
 	struct node_link *next;
 }node_link;
 
 node_link *getnode2(int n)
 {
 	node_link *temp=(node_link *)malloc(sizeof(node_link));
 	temp->val=n;
 	temp->next=NULL;
 	return temp;
 }
 
 typedef struct node
 {
 	int val;
 	struct node *left;
 	struct node *right;
 }node;
 
 node *getnode(int n)
 {
 	node *temp=(node *)malloc(sizeof(node));
 	temp->val=n;
 	temp->left=temp->right=NULL;
 	return temp;
 }
 
void klevel_node(node *root,int k,int a[],int size)
 {
 
 	if(root)
 	{
 		a[size]=root->val;
 		if(!root->left && !root->right)
 			cout<<a[size-k]<<endl;
 		klevel_node(root->left,k,a,size+1);
 		klevel_node(root->right,k,a,size+1);
 			
 	}
 	
 }
 
 int main()
 {
 	node *root=getnode(5);
 	root->left=getnode(3);
 	root->right=getnode(4);
 	
 	node *p,*q;
 	p=root->left;
 	q=root->right;
 	p->left=getnode(7);
 	p->right=getnode(6);
 	
 	q->left=getnode(8);
 	q->right=getnode(11);
 	
 	p=p->left;
 	p->left=getnode(3);
 	
 	int a[8];
 	klevel_node(root,2,a,0);
 	
 }
