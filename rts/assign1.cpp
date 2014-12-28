/*

Real-Time Sytems: Lab Assignment No 1 

1. 	Study the following probability distribution functions and write code for random generation of task sets (periodic, Aperiodic & Sporadic) using these distribution schemes :
a) Uniform 		b) Normal 		c) Exponential 		d) Poisson
Make use of the above distribution functions in the following problems. Clearly write the assumptions, distributions used. 


*/


#include<iostream>
#include <unistd.h>

using namespace std;

typedef struct task
{
	int name;
	int entry_time;
	int type;
}task;


int main()
{
	cout<<"enter no. task";
	int n;
	cin>>n;
	
	task **arr=new task*[n];
	
	for(int i=0;i<n;i++)
	{
		arr[i]=new task();
		arr[i]->name=i;
		arr[i]->type=0;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]->name<<"\t"<<arr[i]->type<<endl;
	}
	
	
	
	cout<<"enter period time\n";
	int p;
	cin>>p;
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]->name<<" is running\n";
		sleep(p);
	}
}
