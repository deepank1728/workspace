#include<iostream>
#include<cstdlib>

using namespace std;

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
int arr[10];
int n=100000;
void min_path(node *root,int *result,int size,int sum,int temp_sum,int temp_size)
{
	
	if(root)
	{
		if(!root->left && !root->right)
		{
			if((temp_sum+root->val)==sum && temp_size<n)
			{
				for(int i=0;i<temp_size;i++)
				{
					arr[i]=result[i];
				}
				arr[temp_size]=root->val;
				n=temp_size+1;
			}
		}
		
		else if((temp_sum+root->val)!=sum)
		{
			result[temp_size]=root->val;
			temp_sum+=root->val;
			min_path(root->left,result,size,sum,temp_sum,temp_size+1);
			min_path(root->right,result,size,sum,temp_sum,temp_size+1);
		}
	}
	
}


void display(int *result,int size)
{
	for(int i=0;i<size;i++)
		cout<<result[i]<<" ";
	cout<<endl;
}

int main()
{
	int size=10,sum=8;
	node *root=getnode(5);
	root->left=getnode(3);
	root->right=getnode(2);
	
	//root->left->right=getnode(7);
	//root->left->left=getnode(6);
	
	root->right->left=getnode(1);
	root->right->right=getnode(4);
	
	int *result=(int *)malloc(sizeof(int)*size);
	min_path(root,result,size,sum,0,0);
	
	display(arr,n);
}
