/*You are given an array of N elements. Each element in the range Min of int to Max of Int. 
You need to find the length of longest sequence in this array such that difference of largest
 and smallest element of that sequence is 1. The sequence need not be sequential. 
 For e.g. array[]={6,10,6,7,8,9,0} seq {6,10} = diff is 4 len 2 seq { 10,7,8} diff is 3 len 3 seq { 7,8,9} diff 2 len 3 seq {6,6,7} diff is 1 len 3 
 */
 
 
 #include<iostream>
 #include<cstdlib>
 
 using namespace std;
 
 
 typedef struct node
 {
 	int val;
 	int count;
 	struct node *next;
 }node;
 
 node *getnode(int n)
 {
 	node *temp=(node *)malloc(sizeof(node));
 	temp->val=n;
 	temp->count=1;
 	return temp;
 }
 void create_hash(int a[],int size,node **array)
 {
	node *p,*q=NULL;
	 for(int i=0;i<size;i++)
	 {
	 	int key=a[i]%size;
	 		if(key<0)
	 			key=-1*key;
	 			
	 	if(array[key]==NULL)
	 		array[key]=getnode(a[i]);
	 	else
	 	{
	 		p=array[key];
	 		if(array[key]->val==a[i])
	 			array[key]->count++;
	 		else
	 		{
	 			while(p!=NULL)
	 			{
	 				if(p->val==a[i])
	 				{
	 					p->count++;
	 					break;
	 				}
	 				q=p;
	 				p=p->next;
	 					
	 			}
	 			
	 			if(p==NULL)
	 				q->next=getnode(a[i]);
	 		}
	 	}
	 }
 }
 
 node *search(node **array,int size,int element)
 {
 	
 	int key=element%size;
 	if(key<0)
 		key=-1*key;
 		
 	node *p=array[key];
 	if(array[key]==NULL)
 		return NULL;
 	else
 	{
 		
		while(p!=NULL)
		{
			if(p->val==element)
				return p;
			p=p->next;
		}
		return NULL;
 			
 	}
 }
 
 void display(node **array,int size)
 {

 	for(int i=0;i<size;i++)
 	{
 		node *p=array[i];
 		if(p)
 		{
 				
 			while(p)
 			{
 				cout<<p->val<<" ";
 				p=p->next;
 			}
 			
 			cout<<endl;
 		}
 	}
 }
 int main()
 {
 	int a[]={6,10,6,7,8,9,0,-1,0,-1,0,-1},size=12;
 	int max_count=0,max_element1,max_element2,temp_count=0,temp_element1,temp_element2;
 	node **array=(node **)malloc(sizeof(node * )*size);
 	create_hash(a,size,array);
 
 	node *p=NULL;
 	node *q=NULL;
 	for(int i=0;i<size;i++)
 	{
 		p=search(array,size,a[i]-1);
 		if(p)
 		{
 			q=search(array,size,a[i]);
 			temp_element1=a[i]-1;
 			temp_element2=a[i];
 			temp_count=p->count+q->count;
 			
 			if(temp_count>max_count)
	 		{
	 			max_element1=temp_element1;
	 			max_element2=temp_element2;
	 			max_count=temp_count;
	 		}
 		
 		}
 		
 		temp_count=0;
 	
 	}
 	p=search(array,size,max_element1);
 	q=search(array,size,max_element2);
 	cout<<"{ ";
 	for(int i=q->count;i>0;i--)
 	{
 		cout<<q->val<<" ";
 	}
 	for(int i=p->count;i>0;i--)
 	{
 		cout<<p->val<<" ";
 	}
 	cout<<"}"<<endl;
 	cout<<"count is "<<max_count<<endl;
 	
 
 }
