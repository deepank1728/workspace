/*
Given a Binary Tree, find the deepest leaf node that is left child of its parent.
 For example, consider the following tree. The deepest left leaf node is the node with value 9.
 */
 
 #include<iostream>
 #include<cstdlib>
 
 using namespace std;
 
/* typedef struct node_link
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
 */
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
 
 int deepest_left(node *root,int v,int k)
 {
	static int max=-10000,max_val=-10000;
 	if(root)
 	{
 		v++;
 		
 		if(!root->left && !root->right)
 		{
 			if(k=-1)
 			{
 				if(v>max)
 				{
 					max=v;
 					max_val=root->val;
 				}
 			}
 		}
 		deepest_left(root->left,v+1,-1);
 		deepest_left(root->right,v+1,0);
 		
 	}
 	return max_val;
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
 	
 	p=p->right;
 	p->left=getnode(20);
 	p->right=getnode(30);
 	//p->left->left=getnode(40);
 	
 	int r=deepest_left(root,0,0);
 	cout<<"r is "<<r<<endl;
 }
