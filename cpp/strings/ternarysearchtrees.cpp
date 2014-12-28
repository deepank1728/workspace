#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
	char data;
	int end_of_string;
	struct node *left,*right,*equal;
}node;

node *getnode(char a)
{
	node *temp=new node();
	temp->data=a;
	temp->right=temp->left=temp->equal=NULL;
	temp->end_of_string=0;
	return temp;
}

node *insert_node(node *root,string word,int i)
{
	if(i==word.length())
		return NULL;

	if(root==NULL && i<word.length())
	{
		root=getnode(word[i]);
		root->equal=insert_node(root->equal,word,i+1);
		return root;
	}
	
	if(root->data>word[i])
		root->left=insert_node(root->left,word,i);
	if(root->data<word[i])
		root->right=insert_node(root->right,word,i);
	if(root->data==word[i])
	{
		if(i<word.length())	
			root->equal=insert_node(root->equal,word,i+1);
		else
		root->end_of_string=1;
	}
	return root; 
}

int main()
{
	string word="deepank";
	node *root=insert_node(root,word,0);
}
