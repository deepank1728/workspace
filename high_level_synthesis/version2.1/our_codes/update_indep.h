int get_length(i_node *ind_list)
{
	int counter=0;
	while(ind_list)
	{
		counter++;
		ind_list = ind_list->next;
	}
	return counter;
}



i_node *cslist(i_node *ind_list, cs_node *control_stmt, int n)
{
	for(int i=0;i<n;i++)
	{
		if(control_stmt[i].type == 0)
		{
			if(ind_list == NULL)
				ind_list = get_indnode(control_stmt[i], i);
			else
			{
				i_node *temp = ind_list;
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = get_indnode(control_stmt[i], i);
			}
		}
	}
	return ind_list;
}

i_node *remove_dependency(i_node *recently_independent, cs_node control_stmt[], hash_node *temp, int curr_index)
{
	index_node *t = temp->below;
	while(t)
	{
		if(t->index > curr_index)
		{
			control_stmt[t->index].dep_count--;
			if(control_stmt[t->index].dep_count == 0)
			{
				if(recently_independent==NULL)
					recently_independent=get_indnode(control_stmt[t->index] , t->index);
				else
				{
					i_node *temper=recently_independent;
					
					recently_independent=get_indnode(control_stmt[t->index] , t->index);
					recently_independent->next=temper;
				}
			}
		}
		t=t->next;
	}
	return recently_independent;
}


i_node *get_recently_independent(i_node *recently_independent,cs_node control_stmt[],int cs_index,hash_node *hash_left[],hash_node *hash_right[]){

		
		// computing the left var in right_hash
		hash_node *temp = get_rhs_node(control_stmt[cs_index].left, hash_right);
		if(temp)
			recently_independent = remove_dependency(recently_independent, control_stmt , temp , cs_index);

		// computing the right vars in left_hash
		for(int i=0;i<control_stmt[cs_index].var_on_right;i++)
		{
			temp = get_rhs_node(control_stmt[cs_index].right[i], hash_left);
			if(temp)
				recently_independent = remove_dependency(recently_independent, control_stmt , temp , cs_index);
		}

		return recently_independent;
}


void update(resource *array,cs_node control_stmt[],int n,int total,hash_node *hash_left[],hash_node *hash_right[],int timer, int &counter,cs_id_node *in_execution[]){

	i_node *ind_list=NULL;
	int column;
	
	if(timer == 0)
	{
		ind_list = cslist(ind_list, control_stmt, n);
		column = get_length(ind_list);
		scheduling(control_stmt , array , hash_right, hash_left, ind_list, total, column);
		for(int i=0;i<total;i++)
		{
			cs_id_node *temp=NULL;
			temp = array[i].next;
			if(temp)
			{
				array[i].next = temp->next;
				temp->next = NULL;

				array[i].last_serviced = 0;
				in_execution[i] = temp;
			}
			else
				in_execution[i] = NULL;
		}

	}

	else
	{

		int flag = 0;

		// finding new indepen on the basis of just executed ones.
		for(int i=0;i<total;i++)
		{
			if(array[i].waiting_time > 0)
				array[i].waiting_time--;

			//cout << " last_serviced of " << i << "resource is " << array[i].last_serviced << endl;
			if(timer - array[i].last_serviced >= array[i].tim)
			{
				if(in_execution[i])
				{

					//cout << "yoooooooooooooooooooo\n";
					flag = 1;
					control_stmt[in_execution[i]->id].executed = 1;
					cout << "statement " << control_stmt[in_execution[i]->id].cs_stmt<<" id "<< control_stmt[in_execution[i]->id].cs_id << " executed " << "on " << array[i].name << " at time " << timer << endl;
					array[i].stmt_executed++;
					counter++;
					ind_list = get_recently_independent(ind_list,control_stmt,in_execution[i]->id,hash_left,hash_right);
					
				}
			}
		}

		if(flag)
		{

			column = get_length(ind_list);
			if(column)
			{
				scheduling(control_stmt , array , hash_right, hash_left, ind_list, total, column);
			}
			


			for(int i=0;i<total;i++)
			{
				if(timer - array[i].last_serviced >= array[i].tim)
				{
					cs_id_node *temp=NULL;
					temp = array[i].next;
					if(temp)
					{
						array[i].next = temp->next;
						temp->next = NULL;

						array[i].last_serviced = timer;
						in_execution[i] = temp;
					}
					else
						in_execution[i] = NULL;
				}
			}
		}

	}
}
