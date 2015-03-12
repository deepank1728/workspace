
void update_waiting(resource *resource_no, int total)
{
	cs_id_node *temp;
	for(int i=0;i<total;i++)
	{
		int count=0;
		temp = resource_no[i].next;
		while(temp)
		{
			count++;
			temp= temp->next;
		}
		resource_no[i].waiting_time = count * resource_no[i].tim;
	}
}


int mintime(int **matrix,resource *resource_no, int i, int j)
{
	int prev_max = matrix[i][0] + resource_no[i].waiting_time, k=1;
	while(true)
	{
		int temp = matrix[i][0]*k + resource_no[i].waiting_time;
		if (temp < matrix[i-1][j-k]) 
			prev_max = max(temp , matrix[i-1][j-k]);
		
		else if (temp == matrix[i-1][j-k])
		{
			prev_max = temp;
			break;
		}
		else
		{
			//prev_max = min(temp, prev_max);
			break;
		}
		k++;		
	}
	return min(prev_max, matrix[i-1][j]);
}

void fillmatrix(int **matrix, resource *resource_no, int row , int column)
{
	// setting the initial conditions
	for(int i=1;i<=column;i++)
		matrix[0][i] = matrix[0][0]*i + resource_no[0].waiting_time;
	for(int i=1;i<row;i++)
		matrix[i][1] = min(matrix[0][1], resource_no[i].waiting_time + resource_no[i].tim);
	
	//making the final table
	for(int i=1;i<row;i++)
	{
		for(int j=2;j<=column;j++)
		{
			matrix[i][j] = mintime(matrix,resource_no, i , j);
		}
	} 
}

void backtrace_matrix(int **matrix, i_node *ind_list, resource *resource_no, int row, int column)
{
	row=row-1;

	while(column > 0 && row >= 0)
	{
		int count;
		count = floor( (matrix[row][column] - resource_no[row].waiting_time)/matrix[row][0]);
		column -= count;
		if(count)
		{
			cs_id_node *tem = resource_no[row].next;

			if(tem == NULL)
			{
				resource_no[row].next = get_idnode(ind_list->cs_id);
				ind_list = ind_list->next;
				tem = resource_no[row].next;
				count--;
				resource_no[row].waiting_time += resource_no[row].tim;
			}
			while(tem->next != NULL)
				tem = tem->next;
			
			
			for(int i=0;i<count;i++)
			{
				
				tem->next = get_idnode(ind_list->cs_id);
				tem = tem->next;
				resource_no[row].waiting_time += resource_no[row].tim;
				ind_list = ind_list->next;
			}


		}
		row--;	
	}
}

resource *scheduling(cs_node *control_stmt,resource *resource_no, hash_node *right_hash[], hash_node *left_hash[], i_node *ind_list, int total, int column)
{

	int row = total;
	int **dp_matrix;
	dp_matrix = new int*[row];
	for(int i=0;i<row;i++)
	{
		dp_matrix[i] = new int[column+1];
		dp_matrix[i][0] = resource_no[i].tim;
	}

	

	// NOW gonna code the dynamic algorithm :) :) :)
	// matrix filled with min time for executing for i number of CS on j resources
	fillmatrix(dp_matrix,resource_no, row, column);

	
	// TESTED!! WORKING CODE FOR DP PROBLEM
	
/*
	for(int i=0;i<row;i++)
	{
		for(int j=1;j<=column;j++)
			cout << dp_matrix[i][j] << "   ";
		cout << endl;
	} 

	*/
	
	
	
	
	backtrace_matrix(dp_matrix, ind_list, resource_no, row, column);
	
	//update_waiting(resource_no, total);
	//for(int i=0;i<total;i++)
	//	cout << resource_no[i].waiting_time << "   is the waiting time"  << endl;
	/*
	for(int i=0;i<total;i++)
	{
		cs_id_node *t = resource_no[i].next;
		while(t)
		{
			cout << t->id << "   ";
			t=t->next;
		}
		cout << endl;
	} 
	*/
}
