#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
using namespace std;

char filename[255]="input";

typedef struct node{

	string s;
	int *count;
	struct node *next;
}node;


node *getnode(string s){

	node *temp=new node();
	temp->next=NULL;
	temp->s=s;
	temp->count=new int[s.length()];
	return temp;
}

void display(int check[],int n){

	for(int i=0;i<n;i++)
		if(check[i]!=0)
			cout<<(char)(i+97)<<"\t:"<<check[i]<<endl;
}

void get_update_count(node **array,int check[],int n){

	for(int i=0;i<n;i++)
		for(int j=0;j<array[i]->s.length();j++)
			check[array[i]->s[j]-97]++;
			
	for(int i=0;i<n;i++)
		for(int j=0;j<array[i]->s.length();j++)
			array[i]->count[j]=check[array[i]->s[j]-97];
}


void sort(node **array,int check[],int n){

	for(int i=0;i<n;i++){
	
		for(int j=0;j<array[i]->s.length();j++){
			for(int k=1;k<array[i]->s.length()-j;k++){
				if(array[i]->count[k-1]<=array[i]->count[k]){
					int temp=array[i]->count[k];
					array[i]->count[k]=array[i]->count[k-1];
					array[i]->count[k-1]=temp;
					
					char temp_char=array[i]->s[k];
					array[i]->s[k]=array[i]->s[k-1];
					array[i]->s[k-1]=temp_char;
				}
			}
		
		}
	}

}

void disp(node **array,int n){

	for(int i=0;i<n;i++)
		cout<<array[i]->s<<endl;
}

typdef struct node2{

	char c;
	struct node2 * next;
}node2;

typedef struct main_node{

	node2 **temp;
}main_node;




int main(){

	ifstream q(filename);
	
	int n;
	float support;
	int check[26]={0};
	q>>n;
	q>>support;
	
	int min_support=ceil(support * n/100.0);
	
	cout<<min_support<<endl;
	
	node **array=new node*[n];
	for(int i=0;i<n;i++){
	
		string temp;
		q>>temp;
		array[i]=getnode(temp);
	}
	
	get_update_count(array,check,n);
	display(check,n);
	
	sort(array,check,n);
	//disp(array,n);
	
	
	

}
