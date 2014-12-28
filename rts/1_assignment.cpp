#include<iostream>
#include<unistd.h>
#include<random>

using namespace std;

typedef struct task{
	int number;
	int time_period;
	int Ri;
	int Ci;
	int Di;
	
}task;

task *get_task( int number,int Ri,int Ci,int time_period,int Di ){

	task *temp=new task();
	temp->number=number;
	temp->Ri=Ri;
	temp->Ci=Ci;
	temp->Di=Di;
	temp->time_period=time_period;
	return temp;
}

typedef struct instance{

	int number;
	int execution_time;
	task *t;

}instance;

int gcd(int a,int b){

	for(;;)
	{
		if(a==0) return b;
		b%=a;
	
		if(b==0) return a;
		a%=b;
	}
}

int lcm(int a,int b){

	int temp=gcd(a,b);
	return temp?(a/temp*b):0;
}

int lcm_all(task **arr,int total_task){

	int temp=arr[0]->time_period;
	
	for(int i=1;i<total_task;i++){
	
		temp=lcm(temp,arr[i]->time_period);
	}
	
	return temp;

}


int main(){

	int total_task=10;
	
	task **arr=new task*[total_task]();
	
	int t[10];
	
	for(int i=0;i<10;i++)
		t[i]=i+1;
		
	int hyper_period=lcm_all(arr,total_task);
	
	random_device rd;
	mt19937 gen(rd());
	std::uniform_int_distribution <> dis(1,10);
		
	for(int i=0;i<total_task;i++)
	{
		int temp=dis(gen);
		arr[i]=get_task(i,0,1,temp,temp);
	}
		
	
	int time=0;
	
	
	while(1){
	
		if(time==hyper_period)
			break;
		time+=1;
		
		for(int i=0;i<total_task;i++){
		
			cout<<time/arr[i]->time_period<<" instance is running of task "<<arr[i]->number<<endl;
		}
		cout<<endl<<endl<<endl;
		usleep(1000);
	}
}





