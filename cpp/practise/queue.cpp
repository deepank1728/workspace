#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct queue
{
	int front,rear,size;
	int *a;
}queue;

queue *create_queue(int size)
{
	queue *q=new queue();
	q->a=new int[size];
	q->front=q->rear=-1;
	q->size=size;
	return q;
}

void enqueue(queue *q,int n)
{
	if(q->front==(q->rear+1)%q->size)
		cout<<"queue full \n";
	else
	{
		if(q->front ==-1 && q->rear==-1)
		{
			q->front=0;
			q->rear=(q->rear+1)%q->size;
			q->a[q->rear]=n;
		}
		else
		{
			q->rear=(q->rear+1)%q->size;
			q->a[q->rear]=n;
		}
	}
		
}

int dequeue(queue *q)
{
	if(q->front==-1)
	{
		cout<<"queue empty\n";
		return NULL;
	}
		
	else
	{
		int temp= q->a[q->front];
		if(q->front==(q->rear)%q->size)
			q->front=q->rear=-1;
		else
			q->front++;
		return temp;
		
	}
}

int main()
{
	queue *q=create_queue(2);
	//int a=dequeue(q);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
	cout<<dequeue(q)<<endl;
}
