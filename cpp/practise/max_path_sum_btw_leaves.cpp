#include<iostream>

//using namespace std;

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


int max_path_sum(node *root,int &max)
{
	if(root)
	{
		int l=max_path_sum(root->left,max);
		int r=max_path_sum(root->right,max);
		
		if(l+r+root->val>max)
		{
			max=l+r+root->val;
		}
		return l>r?l+root->val:r+root->val;
	}
	return 0;
}

int main(){

	node *root=getnode(1);
	root->left=getnode(2);
	root->right=getnode(3);
	
	root->left->left=getnode(4);
	root->left->right=getnode(5);
	
	root->right->left=getnode(6);
	root->right->right=getnode(7);
	int max=0;
	int r=max_path_sum(root,max);
	cout<<max<<endl;
}

