

// ****************************** hash funcitons(dependency) *******************************************


hash_node *get_rhs_node(string var,hash_node *hash_right[]){

	int val = get_key(var),count=0;
	bool flag = false;
	hash_node *temp2 = hash_right[val];
	
	if(temp2==NULL)
		return NULL;
	else{

		while(temp2){
		
			if(temp2->var_name==var)
				return temp2;
			temp2=temp2->next;
		
		}
		
	}
	return NULL;

}



bool check_RHS_hash(cs_node *control_stmt, string var, hash_node *hash_right[], int curr_index)
{
	int val = get_key(var),count=0;
	bool flag = false;
	
	hash_node *temp2 = hash_right[val];
	while(temp2 != NULL)
	{
		if(temp2->var_name == var)
		{
			index_node *temp = temp2->below;
			while(temp != NULL)
			{
				if(temp->index < curr_index)
				{
					flag = true;
					count++;
				}
				
				temp = temp->next;
			}
			break;
		}
		temp2 = temp2->next;
	}
	control_stmt[curr_index].dep_count += count;
	return flag;
}


bool check_LHS_hash(cs_node *control_stmt, string var, hash_node *hash_left[], int curr_index)
{
	int val = get_key(var),count=0;
	bool flag = false;
	
	hash_node *temp2 = hash_left[val];
	while(temp2 != NULL)
	{
		if(temp2->var_name == var)
		{
			index_node *temp = temp2->below;
			while(temp != NULL)
			{
				if(temp->index < curr_index)
				{
					flag = true;
					count++;
				}				
				temp = temp->next;
			}
			break;
		}
		temp2 = temp2->next;
	}
	control_stmt[curr_index].dep_count += count;
	return flag;
}


void dep_indep_segregation(cs_node *control_stmt,int total,hash_node *hash_right[],hash_node *hash_left[])
{

	for(int i=0;i<total;i++)
	{
		string temp = control_stmt[i].left;
		if( check_RHS_hash(control_stmt, temp, hash_right,i) )
			control_stmt[i].type = true;
		
		
		int j=0;
		bool flag = false;
		while( j < control_stmt[i].var_on_right )
		{
			if( check_LHS_hash(control_stmt ,control_stmt[i].right[j], hash_left, i) )
				flag = true;
			
			j++;
		}
		
		control_stmt[i].type = flag;
	}
}
