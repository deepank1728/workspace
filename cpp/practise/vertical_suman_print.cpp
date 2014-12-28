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


void left(node *root,int sum,int &min)
{
	if(root)
	{
		if(sum<min)
			min=sum;
		left(root->left,sum-1,min);
		left(root->right,sum+1,min);
	}
}

int size(node *root)
{
	int a=0,b=0;
	if(root)
	{
		a=size(root->left);
		b=size(root->right);
		return a+b+1;
	}
	return 0;
}


node **create_hash(node **hash,int index,int min,int val)
{

	index=(min*-1)+index;
	
	if(!hash[index])
		hash[index]=getnode(val);
	else
	{
		node *temp=hash[index];
		hash[index]=getnode(val);
		hash[index]->right=temp;
		
	}
	return hash;
}

void vertical_sum(node *root,node **hash,int index,int min)
{
	if(root)
	{
		hash=create_hash(hash,index,min,root->val);
		vertical_sum(root->left,hash,index-1,min);
		vertical_sum(root->right,hash,index+1,min);
	}
}

void print_hash(node **hash,int size,int min)
{
	for(int i=0;i<size;i++)
	{
		if(hash[i])
		{
			node *p=hash[i];
			cout<<"Vertical "<<i+min<<" : ";
			while(p)
			{
				cout<<p->val<<" ";
				p=p->right;
			}
			cout<<endl;
		}
	}
}

int main()
{
	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->left=getnode(4);
	root->left->right=getnode(5);
	root->left->right->left=getnode(7);
	root->left->right->left->left=getnode(8);
	root->left->right->left->left->left=getnode(9);
	
	root->right->left=getnode(6);
	root->right->right=getnode(7);
	
	int min=0;
	int siz=0;
	left(root,0,min);
	siz=size(root);
	
	node **hash=new node*[siz];
	
	vertical_sum(root,hash,0,min);
	
	/*for(int i=0;i<siz;i++)
	{
		if(hash[i]!=0)
			cout<<"vertical "<<i+min<<" : "<<hash[i]<<endl;
	}*/
	
	print_hash(hash,siz,min);
	
}
