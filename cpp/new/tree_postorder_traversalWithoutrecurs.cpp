#include<iostream>
#include<cstdlib>
#include<stack>

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

typedef struct stack_member
{
	node *p;
	int again;
}stack_member;

stack_member *get_member(node *n)
{
	stack_member *temp=new stack_member();
	temp->p=n;
	temp->again=0;
	return temp;
	
}

void postorder(node *root)
{
	stack<stack_member *> s;
	
	s.push(get_member(root));
	
	stack_member *temp;
	while(s.size()!=0)
	{
		temp=s.top();
		
		if(temp->again==1)
		{
			cout<<temp->p->val<<" ";
			s.pop();
			continue;
		}
		
		temp->again=1;
		
		if(!(temp->p->left && temp->p->right))
		{
			cout<<temp->p->val<<" ";
			s.pop();
		}
		
		if(temp->p->right)
			s.push(get_member(temp->p->right));
		if(temp->p->left)
			s.push(get_member(temp->p->left));
		
		
	}
}

void postorder_recursive(node *root)
{
	if(root)
	{
		postorder_recursive(root->left);
		postorder_recursive(root->right);
		cout<<root->val<<" ";
	}
}

void preorder_iterative(node *root)
{
	stack<node *> s;
	
	s.push(root);
	node *temp;
	while(s.size()!=0)
	{
		temp=s.top();
		s.pop();
		cout<<temp->val<<" ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}

void preorder_recursive(node *root)
{
	if(root)
	{
		cout<<root->val<<" ";
		preorder_recursive(root->left);
		preorder_recursive(root->right);
	}
}

/*void inorder_iterative(node *root)
{
	stack<node *> s;
	
	s.push(root);
	node *temp;
	while(s.size!=0)
	{
		temp=s.pop();
	}
}
*/

int main()
{
	node *temp=getnode(0);
	temp->left=getnode(1);
	temp->right=getnode(2);
	
	temp->left->left=getnode(3);
	temp->left->right=getnode(4);
	
	temp->right->left=getnode(5);
	temp->right->right=getnode(6);
	
	temp->left->left->left=getnode(7);
	temp->left->left->right=getnode(8);
	
	temp->left->right->left=getnode(9);
	temp->left->right->right=getnode(10);
	
	temp->right->left->left=getnode(11);
	temp->right->left->right=getnode(12);
	
	temp->right->right->left=getnode(13);
	temp->right->right->right=getnode(14);
	
	cout<<"postorder iterative soln is:\n";
	postorder(temp);
	cout<<endl;
	cout<<"postorder recursive soln is:\n";
	postorder_recursive(temp);
	cout<<endl;
	
	cout<<"preorder iterative soln is:\n";
	preorder_iterative(temp);
	cout<<endl;
	cout<<"preorder recursive soln is:\n";
	preorder_recursive(temp);
	cout<<endl;
	
	/*cout<<"inorder iterative soln is:\n";
	preorder_iterative(temp);
	cout<<endl;
	cout<<"inorder recursive soln is:\n";
	preorder_recursive(temp);
	cout<<endl;
	*/
}
