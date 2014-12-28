#include<iostream>
#include<random>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<ctime>
using namespace std;


typedef struct node
{
    int val;
    struct node *next;
}node;

typedef struct task_node
{
	int task_no;
	int val;
	struct task_node *next;
}task_node;

task_node *gettasknode(int a,int v)
{
	task_node *temp=new task_node();
	temp->task_no=a;
	temp->val=v;
	temp->next=NULL;
	return temp;
}
node *getnode(int s)
{
    node *temp=new node();
    temp->val=s;
    temp->next=NULL;
    return temp;
}

typedef struct message_center{

    task_node *buffer1;
    task_node *buffer2;
    task_node *buffer3;
    task_node *buffer4;
    int size;
    int b1,b2,b3,b4;
}message_center;

message_center *getcenter()
{
	message_center *temp=new message_center();
	temp->buffer1=NULL;
	temp->buffer2=NULL;
	temp->buffer3=NULL;
	temp->buffer4=NULL;
	temp->b1=temp->b2=temp->b3=temp->b4=0;
	return temp;
}

void disp(node *head)
{
    node *p=head;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}


void fill_buffer(message_center * center,node *message,int size)
{
	int d[4],sum=0;
	float p[4]={0.2,0.3,0.35,0.15};
	for(int i=0;i<3;i++)
	{
		d[i]=round(p[i]*size);
		sum+=d[i];
		cout<<d[i]<<endl;
	}
	d[3]=size-sum;
	cout<<d[3]<<endl;
	
	for(int i=0;i<size;i++)
	{
		task_node *p=NULL;
		int temp=rand()%4;
		while(d[temp]<0)
		{
			temp=rand()%4;
		}
		
		int value=message->val;
		message=message->next;
		
		if(temp==0 )
		{
			d[0]--;
			center->b1++;
			task_node *q=center->buffer1;
			if(center->buffer1!=NULL)
			{
				while(q->next!=NULL)
					q=q->next;
			}
			
			while(value>0)
			{
				if(value>20)
				{
					
					if(center->buffer1==NULL)
					{
						center->buffer1=gettasknode(center->b1,20);
						p=center->buffer1;
					}
					else
					{
						q->next=gettasknode(center->b1,20);
						q=q->next;
					}
					value=value-20;
				}
				else
				{
					if(center->buffer1==NULL)
					{
						center->buffer1=gettasknode(center->b1,value);
						
					}
					else
					{
						q->next=gettasknode(center->b1,value);
						q=q->next;
					}
					value=value-20;
				}
				
				
			}
		}
		
		if(temp==1)
		{
			d[1]--;
			center->b2++;
			task_node *q=center->buffer2;
			if(center->buffer2!=NULL)
			{
				while(q->next!=NULL)
					q=q->next;
			}
			
			
			while(value>0)
			{
				if(value>20)
				{
					
					if(center->buffer2==NULL)
					{
						center->buffer2=gettasknode(center->b2,20);
						//p=center->buffer2;
					}
					else
					{
						q->next=gettasknode(center->b2,20);
						q=q->next;
					}
					value=value-20;
				}
				else
				{
					if(center->buffer2==NULL)
					{
						center->buffer2=gettasknode(center->b2,value);
						//p=center->buffer2;
					}
					else
					{
						q->next=gettasknode(center->b2,value);
						q=q->next;
					}
					value=value-20;
				}
				
				
			}
		}
		
		if(temp==2 )
		{
			d[2]--;
			center->b3++;
			task_node *q=center->buffer3;
			if(center->buffer3!=NULL)
			{
				while(q->next!=NULL)
					q=q->next;
			}
			
			
			while(value>0)
			{
				if(value>20)
				{
					
					if(center->buffer3==NULL)
					{
						center->buffer3=gettasknode(center->b3,20);
						//p=center->buffer3;
					}
					else
					{
						q->next=gettasknode(center->b3,20);
						q=q->next;
					}
					value=value-20;
				}
				else
				{
					if(center->buffer3==NULL)
					{
						center->buffer3=gettasknode(center->b3,value);
						//p=center->buffer3;
					}
					else
					{
						q->next=gettasknode(center->b3,value);
						q=q->next;
					}
					value=value-20;
				}
				
				
			}
		}
		
		if(temp==3)
		{
			d[3]--;
			center->b4++;
			task_node *q=center->buffer4;
			if(center->buffer4!=NULL)
			{
				while(q->next!=NULL)
					q=q->next;
			}
			
			
			while(value>0)
			{
				if(value>20)
				{
					
					if(center->buffer4==NULL)
					{
						center->buffer4=gettasknode(center->b4,20);
						//p=center->buffer4;
					}
					else
					{
						q->next=gettasknode(center->b4,20);
						q=q->next;
					}
					value=value-20;
				}
				else
				{
					if(center->buffer4==NULL)
					{
						center->buffer4=gettasknode(center->b4,value);
						//p=center->buffer4;
					}
					else
					{
						q->next=gettasknode(center->b4,value);
						q=q->next;
					}
					value=value-20;
				}
				
				
			}
		}
	}
}

void disp_task(task_node *head)
{
	task_node *p=head;
	while(p)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}


int main()
{

    node *head=NULL;
    int s=0;
    int sum=0;
    node *message=NULL,*p=NULL;
    int temp;
    int count=0;
    int message_size=0;
    int previous=0;
    int b1_time=0,b2_time=0,b3_time=0,b4_time=0;
    message_center *center=getcenter();
    char filename[255]="output";
    int t_total=0;
    
    ofstream x(filename);
    int total=1000;
    srand(time(NULL));
    while(total--)
    {
    		
    		x<<"Time :"<<t_total++<<endl;
	    	
	    	temp=0,count=0,message_size=0,previous=0,s=0,sum=0;
	    	p=NULL;message=NULL;head=NULL;
	    	
	    while(s+previous<90)
	    {
	    	
		   if(count==0)
		   {
		   	
		       temp=rand()%10+10;
		        cout<<"temp is "<<temp<<endl;
		       previous=temp;
		       count++;
		       continue;
		   }
		   s+=previous;
		   temp=rand()%10 +10;
		   cout<<"temp is "<<temp<<endl;
		   if(message==NULL)
		   {
		        message=getnode(previous);
		        p=message;
		   }
		   else
		   {
		   	p->next=getnode(previous);
		   	p=p->next;
		   
		   }
		   message_size++;
		   previous=temp;

	    }
	    
	    p->next=getnode(100-s);

	    disp(message);
	    cout<<++message_size<<endl;
	    
	    fill_buffer(center,message,message_size);
	    disp_task(center->buffer1);
	    disp_task(center->buffer2);
	    disp_task(center->buffer3);
	    disp_task(center->buffer4);
	   
	   
	    if(center->buffer1!=NULL)
	    {
	    		x<<"packet"<<center->buffer1->task_no<<" of destination 1 is transmitted && length is "<<center->buffer1->val<<endl;
	    		center->buffer1=center->buffer1->next;
	    		b1_time++;
	    }
	    
	    if(center->buffer2!=NULL)
	    {
	    		x<<"packet"<<center->buffer2->task_no<<" of destination 2 is transmitted && length is "<<center->buffer2->val<<endl;
	    		center->buffer2=center->buffer2->next;
	    		b2_time++;
	    }
	    
	    if(center->buffer3!=NULL)
	    {
	    		x<<"packet"<<center->buffer3->task_no<<" of destination 3  is transmitted && length is "<<center->buffer3->val<<endl;
	    		center->buffer3=center->buffer3->next;
	    		b3_time++;
	    }
	    
	    if(center->buffer4!=NULL)
	    {
	    		x<<"packet"<<center->buffer4->task_no<<" of destination 4 is transmitted && length is "<<center->buffer4->val<<endl;
	    		center->buffer4=center->buffer4->next;
	    		b4_time++;
	    }
	    
	    
	    cout<<"\n----------------------------------------------------------\n";
	    free(message);
    
    }
    

    while(center->buffer1 || center->buffer2 || center->buffer3 || center->buffer4)
    {
    
    		x<<"Time :"<<t_total<<endl;
    		
    		
    		if(center->buffer1!=NULL)
	    {
	    		x<<"packet"<<center->buffer1->task_no<<" of destination 1 is transmitted && length is "<<center->buffer1->val<<endl;
	    		center->buffer1=center->buffer1->next;
	    		b1_time++;
	    }
	    
	    if(center->buffer2!=NULL)
	    {
	    		x<<"packet"<<center->buffer2->task_no<<"of destination 2 is transmitted && length is "<<center->buffer2->val<<endl;
	    		center->buffer2=center->buffer2->next;
	    		b2_time++;
	    }
	    
	    if(center->buffer3!=NULL)
	    {
	    		x<<"packet"<<center->buffer3->task_no<<" of destination 3 is transmitted && length is "<<center->buffer3->val<<endl;
	    		center->buffer3=center->buffer3->next;
	    		b3_time++;
	    }
	    
	    if(center->buffer4!=NULL)
	    {
	    		x<<"packet"<<center->buffer4->task_no<<" of destination 4 is transmitted && length is "<<center->buffer4->val<<endl;
	    		center->buffer4=center->buffer4->next;
	    		b4_time++;
	    }
	    cout<<"\n----------------------------------------------------------\n";
	    t_total++;
    
    }
    
    
    
    int e_b1=(((float)(b1_time)/(float)(t_total))*100);
    int e_b2=(((float)(b2_time)/(float)(t_total))*100);
    int e_b3=(((float)(b3_time)/(float)(t_total))*100);
    int e_b4=(((float)(b4_time)/(float)(t_total))*100);
    
    x<<"Performance of 1st is "<<e_b1<<endl;
    x<<"Performance of 2nd is "<<e_b2<<endl;
    x<<"Performance of 3rd is "<<e_b3<<endl;
    x<<"Performance of 4th is "<<e_b4<<endl;
    
    

}

