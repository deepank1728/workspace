#include<iostream>
#include<fstream>
#include<cstdlib>

#define v 100
#define w 100

using namespace std;
char filename[255]="input_medoids";
int cost[v][w];
int last_cost[v][w];


typedef struct node{
	
	float x,y,index;
	struct node *next;

}node;

node *last_medoids[v];
node *getnode(float x,float y,float index){

	node *temp=new node();
	temp->x=x;
	temp->y=y;
	temp->index=index;
	return temp;
}

float abs(float a){

	if(a<0)
		return -a;
	else
		return a;
}

float distance(node *c,node *k){

	return abs(c->x - k->x) + abs(c->y - k->y);
}



float calculate_cost(node **medoids,node **coordinate,int k,int t){

	int min_index;
	float temp;
	
	for(int i=0;i<t;i++){
		for(int j=0;j<k;j++)
			cost[i][j]=0;
	}

	for(int i=0;i<t;i++){
	
		temp=999999;
		min_index=100;
		for(int j=0;j<k;j++){
			cost[i][j]=distance(medoids[j],coordinate[i]);
			if(cost[i][j]<temp){
				temp=cost[i][j];
				min_index=j;
			}
		}
		for(int j=0;j<k;j++){
			cost[i][j]=0;
		}
		cost[i][min_index]=temp;
	}
	
	
	
	float sum=0;
	//cout<<endl;
	for(int i=0;i<t;i++){
		for(int j=0;j<k;j++)
			sum+=cost[i][j];
	}	
	return sum;
}



void check_minimum_cost(node **medoids,node **coordinate,int arr[],int temp_arr[],int k,int total_points,int index,float &min_cost){


	
	
	if(index==k){
				float c=calculate_cost(medoids,coordinate,k,total_points);
				if(c<min_cost){
					for(int i=0;i<k;i++){
						arr[i]=temp_arr[i];
					}
					min_cost=c;
					
					for(int i=0;i<total_points;i++){
					
						for(int j=0;j<k;j++)
							last_cost[i][j]=cost[i][j];
					}
					
					for(int i=0;i<k;i++)
						last_medoids[i]=getnode(medoids[i]->x,medoids[i]->y,medoids[i]->index);
				}
				return;
			
			}
	
	
	for(int i=0;i<total_points;i++){
		temp_arr[i]=0;
	}
	
	for(int i=0;i<k;i++){
		temp_arr[(int)medoids[i]->index]=1;
	}
	
	
	for(int i=0;i<total_points;i++){
	
		if(!temp_arr[i]){
		
			check_minimum_cost(medoids,coordinate,arr,temp_arr,k,total_points,index+1,min_cost);
			
			//cout<<"hello\n";
			
			temp_arr[(int)coordinate[i]->index]=1;
			temp_arr[(int)medoids[index]->index]=0;
			
			//cout<<index<<endl;
			node *temp=medoids[index];
			medoids[index]=coordinate[i];
			int ind=medoids[index]->index;
			//coordinate[i]=temp;
			
				
			check_minimum_cost(medoids,coordinate,arr,temp_arr,k,total_points,index+1,min_cost);
			temp=medoids[index];
			medoids[index]=coordinate[ind];
			//coordinate[i]=temp;
			
			
		}
	}
	
}

int main(){

	ifstream q(filename);
	
	int total_points, k;
	
	q>>total_points;
	
	q>>k;
	
	node **medoids=new node*[k];
	node **coordinate=new node*[total_points];
	
	
	
	for(int i=0;i<k;i++){
	
		float a,b;
		q>>a>>b;
		medoids[i]=getnode(a,b,i);
		coordinate[i]=getnode(a,b,i);
	}
	//initialize(medoids,k,q,coordinate);
	int arr[total_points],temp_arr[total_points];
	
	for(int i=0;i<total_points;i++)
		arr[i]=0;
		
	for(int i=0;i<k;i++)
		arr[i]=1;
		
	for(int i=k;i<total_points;i++){
		
		float a,b;
		q>>a>>b;
		coordinate[i]=getnode(a,b,i);
	}
	
	for(int i=0;i<total_points;i++)
		cout<<"("<<coordinate[i]->x<<","<<coordinate[i]->y<<")"<<" ";
	cout<<endl;
	float min_cost=calculate_cost(medoids,coordinate,k,total_points);
	//cout<<min_cost<<endl;
	//void check_minimum_cost(node **medoids,node **coordinate,int arr[],int k,int total_points,int index,float &min_cost)
	
	check_minimum_cost(medoids,coordinate,arr,temp_arr,k,total_points,0,min_cost);
	
	int z=0;
	for(int i=0;i<total_points;i++){
	
		if(arr[i]==1){
			medoids[z++]=coordinate[i];
		}
	}
	
	int cost[total_points][k],min_index;
	for(int i=0;i<total_points;i++){
		for(int j=0;j<k;j++)
			cost[i][j]=0;
	}

	for(int i=0;i<total_points;i++){
	
		float temp=999999;
		for(int j=0;j<k;j++){
			cost[i][j]=distance(medoids[j],coordinate[i]);
			if(cost[i][j]<temp){
				temp=cost[i][j];
				min_index=j;
			}
		}
		for(int j=0;j<k;j++){
			cost[i][j]=0;
		}
		cost[i][min_index]=temp;
	}
	
	cout<<endl;
	/*for(int i=0;i<total_points;i++)
	{
		for(int j=0;j<k;j++)
			cout<<last_cost[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	*/
	
	for(int i=0;i<total_points;i++)
	cout<<coordinate[i]->x<<" "<<coordinate[i]->y<<endl;
	for(int i=0;i<k;i++){
		node *p=last_medoids[i];
		for(int j=0;j<total_points;j++){
		
			if(last_cost[j][i]!=0){
				//cout<<last_cost[i][j]<<endl;
				p->next=getnode(coordinate[j]->x,coordinate[j]->y,coordinate[j]->index);
				p=p->next;
			}
		}
	}
	
	cout<<"mediod "<<last_medoids[0]->x<<" "<<last_medoids[0]->y<<endl;
	cout<<"mediod "<<last_medoids[1]->x<<" "<<last_medoids[1]->y<<endl;
	
	for(int i=0;i<k;i++){
	
		node *p=last_medoids[i];
		while(p){
			cout<<"("<<p->x<<","<<p->y<<")"<<" ";
			p=p->next;
		}
		cout<<endl<<endl;
		
	}
	cout<<min_cost<<endl;
	
}
