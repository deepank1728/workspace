#include<iostream>
using namespace std;

typedef struct node{
	char c;
	int is_end;
	struct node *child[26];
}node;

node *getnode(char c)
{
	node *temp=new node();
	temp->c=c;
	temp->is_end;
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	return temp;
}

void sub_node(node *root)
{
	if(root)
	{
		cout<<root->c;
		for(int i=0;i<26;i++)
		{
			if(root->child[i])
				sub_node(root->child[i]);
		}
	}
	
}

node *insert_in_tries(node *root,string word,int index)
{
	if(!root)
	{
		root=getnode(word[index]);
		index++;
	}
	
	if(index==word.length())
		root->is_end=1;
	
	else if(index < word.length())
	{
		root->child[word[index]-97]=insert_in_tries(root->child[word[index]-97],word,index+1);
		
	}
	return root;
	
}

int search_string(node *root,string word,int index)
{
	if(!root)
	{
		cout<<"hello\n";
		return -1;
	}
		
	if(index ==word.length()-1 && root->is_end)
		return 1;
	else if(index ==word.length())
	return -1;
	
	if(root->c==word[index])
	{
		cout<<"tried\n";
		return search_string(root->child[word[index]-97],word,index+1);
	}
	else return -1;
}

int main()
{
	node *root=NULL;
	
	string word="deep",word2="deepa",word3="deepank";
	
	root=insert_in_tries(root,word,0);
	//root=insert_in_tries(root,word2,0);
	//root=insert_in_tries(root,word3,0);
	sub_node(root);
	cout<<endl;
	int r=search_string(root,"de",0);
	
	cout<<r<<endl;
	
}
