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

void divide_scheduling(cs_node control_stmt[], resource *array, hash_node *hash_right[],hash_node *hash_left[], i_node *ind_list, int total, int column)
{

	// ******************************seperating the statements on basis of the category to send them for scheduling
	int new_column[3] = {0};
	i_node *new_stmt_plus = NULL, *plus;
	i_node *new_stmt_minus = NULL, *minus;
	i_node *new_stmt_mul = NULL, *mul;

	while(ind_list)
	{
		if(ind_list->category == "+")
		{
			new_column[0]++;
			if(new_stmt_plus == NULL)
			{
				new_stmt_plus = ind_list;
				ind_list = ind_list->next;
				new_stmt_plus->next = NULL;
				plus = new_stmt_plus;

			}
			else
			{
				plus->next = ind_list;
				ind_list = ind_list->next;
				plus = plus->next;
				plus->next = NULL;
			}
		}

		else if(ind_list->category == "-")
		{
			new_column[1]++;
			if(new_stmt_minus == NULL)
			{
				new_stmt_minus = ind_list;
				ind_list = ind_list->next;
				new_stmt_minus->next = NULL;
				minus = new_stmt_minus;

			}
			else
			{
				minus->next = ind_list;
				ind_list = ind_list->next;
				minus = minus->next;
				minus->next = NULL;
			}
		}

		else if(ind_list->category == "*")
		{
			new_column[2]++;
			if(new_stmt_mul == NULL)
			{
				new_stmt_mul = ind_list;
				ind_list = ind_list->next;
				new_stmt_mul->next = NULL;
				mul = new_stmt_mul;

			}
			else
			{
				mul->next = ind_list;
				ind_list = ind_list->next;
				mul = mul->next;
				mul->next = NULL;
			}
		}
	}
	
	// ****************************************************seperating the resurces to send them for scheduling


	resource *new_res_plus = new resource[total];

	resource *new_res_minus = new resource[total];

	resource *new_res_mul = new resource[total];


	int _plus = 0, _minus = 0, _mul = 0;

	for(int i=0;i<total;i++)
	{
		if(array[i].category == "+" || array[i].category == "+-*")
		{
			new_res_plus[_plus] = array[i];
			new_res_plus[_plus++].index = i;
		}
	}
	if(new_stmt_plus)
	{
		scheduling(control_stmt, new_res_plus, hash_right, hash_left, new_stmt_plus, _plus, new_column[0]);
		for(int i=0;i<_plus; i++)
		{
			array[new_res_plus[i].index] = new_res_plus[i];
		}
	}


	for(int i=0;i<total;i++)
	{	
		if(array[i].category == "-" || array[i].category == "+-*")
			{
			new_res_minus[_minus] = array[i];
			new_res_minus[_minus++].index = i;
		}
	}
	if(new_stmt_minus)
	{
		scheduling(control_stmt, new_res_minus, hash_right, hash_left, new_stmt_minus, _minus, new_column[1]);
		for(int i=0;i<_minus; i++)
		{
			array[new_res_minus[i].index] = new_res_minus[i];
		}
	}
	


	for(int i=0;i<total;i++)
	{
		if(array[i].category == "*" || array[i].category == "+-*")
			{
			new_res_mul[_mul] = array[i];
			new_res_mul[_mul++].index = i;
		}
	}
	if(new_stmt_mul)
	{
		scheduling(control_stmt, new_res_mul, hash_right, hash_left, new_stmt_mul, _mul, new_column[2]);
		for(int i=0;i<_mul; i++)
		{
			array[new_res_mul[i].index] = new_res_mul[i];
		}
	}		
}


void update(resource *array,cs_node control_stmt[],int n,int total,hash_node *hash_left[],hash_node *hash_right[],int timer, int &counter,cs_id_node *in_execution[]){

	i_node *ind_list=NULL;
	int column;
	
	if(timer == 0)
	{
		ind_list = cslist(ind_list, control_stmt, n);
		column = get_length(ind_list);
		divide_scheduling(control_stmt , array , hash_right, hash_left, ind_list, total, column);
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
				//cout << "yooo\n";
				if(in_execution[i])
				{

					if(control_stmt[in_execution[i]->id].executed == false)
					{
						flag = 1;
						control_stmt[in_execution[i]->id].executed = true;
						//cout << "statement " << control_stmt[in_execution[i]->id].cs_stmt<<" id "<< control_stmt[in_execution[i]->id].cs_id << " executed " << "on " << array[i].name << " at time " << timer << endl;
						array[i].stmt_executed++;
						counter++;
						//cout << counter << endl;
						ind_list = get_recently_independent(ind_list,control_stmt,in_execution[i]->id,hash_left,hash_right);

					}
				}
			}
		}

		if(flag)
		{

			column = get_length(ind_list);
			if(column)
			{
				divide_scheduling(control_stmt , array , hash_right, hash_left, ind_list, total, column);
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
