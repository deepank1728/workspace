#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;
int final_clock;

int glob=0;
#include "structure.h"
#include "secondary.h"
#include "segregate.h"
#include "dependency.h"
#include "scheduling.h"
#include "update_indep.h"
#include "permute.h"
#include "slack_minimization.h"



int main(int argc, char const *argv[])
{
	
	hash_node *hash_left[max_hash_size] = {NULL};
	hash_node *hash_right[max_hash_size] = {NULL};
	
	ifstream q("input");
	int n;					// total number of control stmts
	q >> n;
	
	bool dependency[n];
	cs_node control_stmt[n];
	for(int i=0;i<n;i++)
	{
		control_stmt[i].executed = false;
		control_stmt[i].dep_count = 0;
		control_stmt[i].cs_id=i;
		control_stmt[i].category = "";
		q >> control_stmt[i].cs_stmt;
	}
	q.close();


	segregation(control_stmt,n,hash_left,hash_right);

	dep_indep_segregation(control_stmt, n, hash_right, hash_left );

	
	ifstream ip("resources");
	int total,max_time,t=0;
	double max_area;
	ip >> total >> max_area >> max_time;
	resource *tem_resource_no = new resource[total];
	// reading input from file
	// ****************** instances--------- area -------------- time in ns
	for(int i=0;i<total;i++)
	{
		ip >> tem_resource_no[i].name;
		ip >> tem_resource_no[i].category;
		ip >> tem_resource_no[i].instances;
		ip >> tem_resource_no[i].area;
		ip >> tem_resource_no[i].tim;
		tem_resource_no[i].waiting_time = 0;
		tem_resource_no[i].stmt_executed = 0;
		tem_resource_no[i].res_id = i;
		tem_resource_no[i].next = NULL;
		tem_resource_no[i].last_serviced = -tem_resource_no[i].tim;

		t += tem_resource_no[i].instances;
	}
	ip.close();
	int k=0;
	resource *resource_no = new resource[t];
	for(int i=0;i<total;i++)
	{
		for(int j=0;j<tem_resource_no[i].instances; j++)
		{
			resource_no[k++] = tem_resource_no[i];
		}
	}
	//delete[] tem_resource_no;
	total = t;
	
	//Permutaion by kabra
	
	make_permutation(resource_no,total,max_area);

	delete[] resource_no;
	
	
	
	//10th march 2015 1:00 pm      starting of 2nd semester
	
	//total = total no. of resources so loop to read all permutaion . we read resources in set of total no. of resources
	
	ifstream permut_cursor("permutation.txt");
	
	string resources_name_temp="";
	
	int final_max_time=100000000;
	
	resource *min_final_resource_no;
	min_final_resource_no=new resource[2]();
	
	int counter =0, timer=0, column=0;
	int test_counter=0, min_new_total, set=1, minset;
	while(permut_cursor >> resources_name_temp)
	{
	
		for(int i=0;i<n;i++)
		{
			control_stmt[i].executed = false;
			control_stmt[i].dep_count = 0;
		}
		dep_indep_segregation(control_stmt, n, hash_right, hash_left );
		
		
		counter =0, timer=0, column=0;
		cs_id_node *in_execution[total];
		for(int i=0;i<total;i++)
		{
			in_execution[i] = NULL;
		}
	

		//int new_total=0;
		int flag=1, new_total=0;
		resource *temp_resource_no=new resource[total];
		
		for(int permut_index=0;permut_index<total;permut_index++)
		{
			if(flag)
				temp_resource_no[permut_index].name=resources_name_temp;
			else
				permut_cursor >> temp_resource_no[permut_index].name;
				
			flag=0;
			permut_cursor >> temp_resource_no[permut_index].category;
			//permut_cursor >> temp_resource_no[permut_index].instances;
			permut_cursor >> temp_resource_no[permut_index].area;
			if(temp_resource_no[permut_index].area != 0)
				new_total++;

			permut_cursor >> temp_resource_no[permut_index].tim;
			temp_resource_no[permut_index].waiting_time = 0;
			temp_resource_no[permut_index].stmt_executed = 0;
			temp_resource_no[permut_index].res_id = permut_index;
			temp_resource_no[permut_index].next = NULL;
			
			temp_resource_no[permut_index].last_serviced = -temp_resource_no[permut_index].tim;
			
		
		}
		string _break="";
		permut_cursor >>_break;

		resource *final_resource_no = new resource[new_total];
		int index=0;
		for(int i=0;i<total;i++)
		{
			if(temp_resource_no[i].area != 0)
			{
				final_resource_no[index++] = temp_resource_no[i];
			}
		}

		
		// here we are going to calculate the clock cycle for each set of resources. 
		int clock_val;
		clock_val = slack_minimization(final_resource_no, index);
		for(int i=0;i<index;i++)
		{
			final_resource_no[i].tim = ceil((final_resource_no[i].tim*1.0)/clock_val);
			final_resource_no[i].last_serviced = -final_resource_no[i].tim;
		}

		
		glob=0;
		timer=0;
		while(1)
		{
			
			update(final_resource_no, control_stmt, n, new_total, hash_left, hash_right, timer , counter,in_execution);


			if(counter == n)
				break;
			timer++;
			glob=timer;
		}
		
		cout << "time taken by set " << set << " is " << timer << "\n";
		if(timer < final_max_time)
		{
			minset = set;
			final_max_time=timer;
			//cout<<"final name is "<<temp_resource_no[0].name<<endl;
			delete[] min_final_resource_no;
			min_final_resource_no=new resource[new_total]();
			
			for(int i=0;i<new_total;i++)
			{
				min_final_resource_no[i]=final_resource_no[i];
			}
			min_new_total = new_total;
			final_clock = clock_val;
		
		}
		else if(timer == final_max_time)
		{
			int area1=0, area2=0;
			for(int i=0;i<min_new_total; i++)
				area1 += min_final_resource_no[i].area;

			for(int i=0;i<new_total; i++)
				area2 += final_resource_no[i].area;

			if(area2 < area1)
			{
				minset = set;
				final_max_time=timer;
				delete[] min_final_resource_no;
				min_final_resource_no=new resource[new_total]();
				
				for(int i=0;i<new_total;i++)
				{
					min_final_resource_no[i]=final_resource_no[i];
				}
				min_new_total = new_total;
				final_clock = clock_val;
			}
		}

		
		delete[] temp_resource_no;
		delete[] final_resource_no;
		
		temp_resource_no=NULL;
		final_resource_no=NULL;

		set++;
	}
	
	cout << "\nstats of the set " << minset << " giving best results:\n";

	cout << "\nresource name\t\t" << "statements executed\t\t" "utilization"<< "\n";
	for(int i=0;i<min_new_total;i++)
	{
		cout << min_final_resource_no[i].name << "\t\t\t\t" << min_final_resource_no[i].stmt_executed << "\t\t\t" << 
		1.0*min_final_resource_no[i].stmt_executed*min_final_resource_no[i].tim/timer<< endl;
	}
	
	cout << "\nthe min time taken by the set is " << final_max_time << " with the clock rate of " << final_clock << "ns" << endl;
	

	cout << "\nresource name\t\t" << "slack time/" << final_clock*final_max_time << "\n";
	for(int i=0;i<min_new_total;i++)
	{
		int z=0;
		cout << min_final_resource_no[i].name << "\t\t\t";
		while(1)
		{
			if(tem_resource_no[z].name == min_final_resource_no[i].name)
			{
				cout << final_clock*final_max_time - min_final_resource_no[i].stmt_executed*tem_resource_no[i].tim << endl;
				break;
			}
			z++;
		}
	}


	return 0;
}
