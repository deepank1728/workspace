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

void display(node *root)
{
	if(root)
	{
		display(root->left);
		cout<<root->val<<" ";
		display(root->right);
	}
}

node *convert_to_bst(node *root,int *array,int *index)
{
	if(root)
	{
		convert_to_bst(root->left,array,index);
		root->val=array[*index];
		*index=*index+1;
		convert_to_bst(root->right,array,index);
	}
	return root;
}

void find_inorder(node *root,int *array,int *index)
{
	if(root)
	{
		
		find_inorder(root->left,array,index);
		*index=*index+1;
		array[*index]=root->val;
		find_inorder(root->right,array,index);
	}

}

void disp(int *a,int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int find_size(node *root)
{
	if(root)
		return find_size(root->left) + find_size(root->right) + 1;
}

int main()
{
	node *root=getnode(1);
	root->left=getnode(2);
	root->left->left=getnode(3);
	
	root->right=getnode(4);
	root->right->left=getnode(5);
	root->right->right=getnode(6);
	
	root->right->right=getnode(7);
	
	display(root);
	cout<<endl;
	//root=convert_to_bst(root);
	
	int size=find_size(root);
	int array[size];
	//cout<<size<<endl;
	int index=-1;
	find_inorder(root,array,&index);
	index=0;
	
	sort(array,array+size);
	root=convert_to_bst(root,array,&index);
	cout<<"After conversion:\n";
	display(root);
	cout<<endl;
}
