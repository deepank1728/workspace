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

void display(node *root)
{
	if(root)
	{
		cout<<root->val<<" ";
		display(root->left);
		display(root->right);
	}
}

int check_sum_root_to_node(node *root,int sum,int temp_sum)
{
	if(root)
	{
		temp_sum+=root->val;
		if(temp_sum==sum)
			return 1;
		else
		{
			int a=check_sum_root_to_node(root->left,sum,temp_sum);
			int b=check_sum_root_to_node(root->right,sum,temp_sum);
			return a+b;
		}
	}
}

int sum_binary_tree(node *root)
{
	if(root)
		return sum_binary_tree(root->left)+sum_binary_tree(root->right)+root->val;
	return 0;
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
	
	int sum=8;
	int r=check_sum_root_to_node(root,sum,0);
	
	if(r)
		cout<<"Path Exists!!!\n";
	else
		cout<<"Path doesn't exists\n";
		
	cout<<"Sum of binary tree = "<<sum_binary_tree(root)<<endl;
}
