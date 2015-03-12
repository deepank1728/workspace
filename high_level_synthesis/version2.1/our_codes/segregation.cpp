#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;
//int counter=0;

int glob=0;
#include "structure.h"
#include "secondary.h"
#include "segregate.h"
#include "dependency.h"
#include "scheduling.h"
#include "update_indep.h"
#include "permute.h"



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
		q >> control_stmt[i].cs_stmt;
	}
	q.close();
	
	segregation(control_stmt,n,hash_left,hash_right);

	dep_indep_segregation(control_stmt, n, hash_right, hash_left );
	

	
	ifstream ip("resources");
	int total,max_time;
	double max_area;
	ip >> total >> max_area >> max_time;
	resource resource_no[total];
	// reading input from file
	for(int i=0;i<total;i++)
	{
		ip >> resource_no[i].name;
		ip >> resource_no[i].instances;
		ip >> resource_no[i].area;
		ip >> resource_no[i].tim;
		resource_no[i].waiting_time = 0;
		resource_no[i].stmt_executed = 0;
		resource_no[i].res_id = i;
		resource_no[i].next = NULL;
		resource_no[i].last_serviced = -resource_no[i].tim;
	}
	ip.close();
	
	
	//Permutaion by kabra
	// ifstream permutation.txt
	
	make_permutation(resource_no,total,max_area);

	
	
	
	//10th march 2015 1:00 pm      starting of 2nd semester
	
	//total = total no. of resources so loop to read all permutaion . we read resources in set of total no. of resources
	
	ifstream permut_cursor("permutation.txt");
	int counter_permut=0;
	
	string resources_name_temp="";
	
	int final_max_time=100000000;
	
	resource *min_final_resource_no;
	min_final_resource_no=new resource[2]();
	
	int counter =0, timer=0, column=0;
	int test_counter=0, min_new_total;
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
	
		
	
	
		i_node *ind_list = NULL;
		ind_list=NULL;
		ind_list = cslist(ind_list, control_stmt, n); 
	
		int new_total=0;
		int flag=1;
		resource *temp_resource_no=new resource[total];
		
		for(int permut_index=0;permut_index<total;permut_index++)
		{
			if(flag)
				temp_resource_no[permut_index].name=resources_name_temp;
			else
				permut_cursor >> temp_resource_no[permut_index].name;
				
			flag=0;
			permut_cursor >> temp_resource_no[permut_index].instances;
			permut_cursor >> temp_resource_no[permut_index].area;
			permut_cursor >> temp_resource_no[permut_index].tim;
			temp_resource_no[permut_index].waiting_time = 0;
			temp_resource_no[permut_index].stmt_executed = 0;
			temp_resource_no[permut_index].res_id = permut_index;
			temp_resource_no[permut_index].next = NULL;
			
			temp_resource_no[permut_index].last_serviced = -temp_resource_no[permut_index].tim;
			new_total+=temp_resource_no[permut_index].instances;
			//cout<<" i am in"<<endl;
			//cout<<"resource instance is "<<temp_resource_no[permut_index].name<<"\t"<<temp_resource_no[permut_index].instances<<temp_resource_no[permut_index].area<<temp_resource_no[permut_index].tim<<endl;
		
		}
		string _break="";
			permut_cursor >>_break;
		
		resource *final_resource_no=new resource[new_total];
		int new_total_index=0;
		for(int i=0;i<total;i++)
		{
			int index=temp_resource_no[i].instances;
			while(index)
			{
				final_resource_no[new_total_index++]=temp_resource_no[i];
				cout<<"final res is "<<final_resource_no[new_total_index-1].name<<"\t"<<final_resource_no[new_total_index-1].instances<<final_resource_no[new_total_index-1].area<<final_resource_no[new_total_index-1].tim<<endl;
				index--;
			}
			
		
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
		
		if(timer<final_max_time)
		{
			final_max_time=timer;
			//cout<<"final name is "<<final_resource_no[0].name<<endl;
			delete[] min_final_resource_no;
			min_final_resource_no=new resource[new_total]();
			
			for(int i=0;i<new_total;i++)
			{
				min_final_resource_no[i]=final_resource_no[i];
			}
			min_new_total = new_total;
		
		}
		
		delete[] temp_resource_no;
		delete[] final_resource_no;
		
		temp_resource_no=NULL;
		final_resource_no=NULL;

		
	}
	
	cout << "\n\nresource name\t\t" << "statements executed\t\t" "utilisation"<< "\n";
		for(int i=0;i<min_new_total;i++)
		{
			cout << min_final_resource_no[i].name << "\t\t\t\t" << min_final_resource_no[i].stmt_executed << "\t\t\t" << 
			1.0*min_final_resource_no[i].stmt_executed*min_final_resource_no[i].tim/timer<< endl;
		}
	
	cout << "\nthe total time taken by the system is " << final_max_time << endl;
		
	return 0;
}
