#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>

using namespace std;



char filename[255]="deepank";
typedef struct node{

	string s;
	struct node *next;
}node;


node *getnode(string s){

	node *temp=new node();
	temp->next=NULL;
	temp->s=s;
	return temp;
}


void is_anargam(string a,int count,string s,int &flag)
{
	string p=a;
	char temp;

	if(count==a.length())
	{
		if(a==s)
			flag=1;
		return;
	}
	
	for(int i=count;i<a.length();i++)
	{
		if(a[i]==a[count] && i!=count)
			continue;
		temp=a[count];
		a[count]=a[i];
		a[i]=temp;
		is_anargam(a,count+1,s,flag);
	}
	
	
	
}
node *insert(node *r,string s){

	int flag=0;
	if(r==NULL)
		r=getnode(s);
	else
	{
		node *p=r;
		
		while(p->next)
		{
			is_anargam(p->s,0,s,flag);
			p=p->next;
		}
		if(flag==1)
			return r;
		p->next=getnode(s);
	}
	return r;
	
	
}


void display(node *head){

	node *p=head;
	int size=0;
	
	while(p){
		size++;
		cout<<p->s<<endl;
		p=p->next;
	}
	
	cout<<endl;
	
}

int get_size(node *head){

	node *p=head;
	int size=0;
	
	while(p){
		size++;
		p=p->next;
	}
	return size;
}

node *make_set(node *head,int size,node *result){

	for(int i=0;i<size;i++){
	
		node *p=head,*q=head;
		
		for(int j=0;j<i;j++){
			p=p->next;
			q=q->next;
		}
			
		for(int j=i;j<size;j++){
		
			if(  p->s[p->s.length()-1]!=q->s[q->s.length()-1] && ( p->s.substr(0,p->s.length()-1)==q->s.substr(0,q->s.length()-1)  || ( p->s.length() ==1 && q->s.length() ==1 ) )  ){
			
				result=insert(result,p->s + q->s[q->s.length()-1]);
				//cout<<"hello\n";
			}
				
			q=q->next;
		}
	}
	return result;
}


int get_support(string *input,int size,string support_str){

	int count=0,flag=0,flag2=0;
	
	
	for(int k=0;k<size;k++){
	
		flag=0;
		for(int i=0;i<support_str.length();i++){
		
			flag2=0;
			for(int j=0;j<input[k].length();j++){
			
				if(support_str[i]==input[k][j])
					flag2++;
			}
			
			if(flag2==0)
			{
				flag=1;
				break;
			}
			
		}
		if(flag==0)
			count++;
	
	}
	
	return count;++
	+
	
}


node *deletion(node *head,node *d){

	node *p=head,*q=NULL;
	
	while(p!=d){
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	free(p);
	p=NULL;
}


int is_present_in_set(node *head,string s){

	node *p=head;
	
	while(p){
	
		if(p->s==s)
			return 1;
		p=p->next;
	}
	return 0;

}


void all_present(string a,int i,string temp,int index,node *head,int &flag){


	if(i == a.length()-1){
		if(!is_present_in_set(head,temp) && temp!="" && temp.length()==a.length()-1)
			flag=1;
		return;
	}
		
	all_present(a,i+1,temp,index,head,flag);
	temp+=a[i];
	all_present(a,i+1,temp,index+1,head,flag);


}


node  *prune(node *result,node *head,string *input,int size,int min_support){

	node *p=result,*q=NULL;
	int flag;
	
	while(p){
	
		string temp="";
		flag=0;
		all_present(p->s,0,temp,0,head,flag);
		
		if( flag==1 || get_support(input,size,p->s)<min_support){
		
			if(q==NULL)
			{
				result=p->next;
				p=result;
			}
			else{
			
				q->next=p->next;
				p=q->next;
			}
		}
		else{
		
			q=p;
			p=p->next;
		}
		
	}	
	return result;

}

void check_support(string *input,int n,node *result){


	node *p=result;
	
	while(p){
	
		int k=get_support(input,n,p->s);
		cout<<p->s<<"\t"<<k<<endl;
		p=p->next;
	
	}
	

}

node *initialize(node *head,int check[]){

	for(int i=0;i<26;i++){
	
		if(check[i]){
			char temp=i+97;
			string k="a";
			k[0]=temp;
			head=insert(head,k);
		}
	}
	return head;
}


node *add_result(node *l,node *result){

	node *p=result,*q=l;
	int flag=0;
	if(l==NULL){
	
		while(p){
			if(l==NULL){
				l=getnode(p->s);
				q=l;
			}
			else{
			
				q->next=getnode(p->s);
				q=q->next;
			}
			p=p->next;
			
		}
	}
	else{
	
		while(q->next){
			q=q->next;
		}
		while(p){
			q->next=getnode(p->s);
			q=q->next;
			p=p->next;
		}
	}
	
	return l;
}

int main(){

	int check[26];
	ifstream q(filename);
	
	int n,min_support;
	float min_supp;
	q>>n;
	q>>min_supp;
	
	min_support=ceil((min_supp*n)/100);
	string *input=new string[n]();
	
	for(int i=0;i<n;i++)
		q>>input[i];
		
	for(int i=0;i<26;i++)
		check[i]=0;
		
	for(int i=0;i<n;i++){
	
		for(int j=0;j<input[i].length();j++)
			check[input[i][j]-97]++;
	}
	
	
	
	node *l=NULL;
	node *head=NULL;
	head=initialize(head,check);
	node *result=NULL;
	result=head;
	result=prune(result,head,input,n,min_support);
	l=add_result(l,result);
	head=result;
	cout<<"min_support is "<<min_support<<endl;
	
	while(get_size(head)!=0)
	{
	
		//display(head);
		int size=get_size(head);
	
		result=NULL;
		result=make_set(head,size,result);
		//check_support(input,n,result);
		//cout<<endl;
		
		result=prune(result,head,input,n,min_support);
		l=add_result(l,result);
		
		
		//display(result);
		head=result;
	
	}
	
	cout<<"frequent sets are :\n";
	display(l);
	
}
