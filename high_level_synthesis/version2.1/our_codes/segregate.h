
// ****************************** hash funcitons(segregation) *******************************************

void insert_hash(hash_node *hash_table[],string str,int index)
{

	int key=get_key(str);
	
	if(hash_table[key] == NULL)
	{
		hash_table[key] = get_hashnode(str);
		hash_table[key]->below = get_indexnode(index);
		return;
	}
	
	hash_node *temp=hash_table[key];
	
	while(temp!=NULL)
	{
		if(temp->var_name==str)
		{
			index_node *temp2 = temp->below;
			temp->below = get_indexnode(index);
			temp->below->next = temp2;
			break;
		}
		if(temp->next == NULL)
		{
			temp->next = get_hashnode(str);
			temp->next->below = get_indexnode(index);
			break;
		}
		temp=temp->next;
	}
}



void segregation(cs_node control_stmt[],int n,hash_node *hash_left[],hash_node *hash_right[])
{
	for(int i=0;i<n;i++)
	{
		string temp=control_stmt[i].cs_stmt;
		int total_operator=0;
		total_operator=count_operator(temp);
					
		string temp2="";
		
		int j=0;
		while(temp[j] != '=')
			temp2 += temp[j++];	

		control_stmt[i].left=temp2;
		insert_hash(hash_left,temp2,i);
		

		control_stmt[i].right=new string[total_operator+1];
		control_stmt[i].oper=new char[total_operator];
		
		int right_index=0;
		int operator_index=0;
		string rhs_temp="";
		for(int k=++j;k<temp.length();k++)
		{
			if( is_operator(temp[k]))
			{
				control_stmt[i].right[right_index++]=rhs_temp;
				insert_hash(hash_right,rhs_temp,i);

				control_stmt[i].oper[operator_index++]=temp[k];
				rhs_temp="";
			
			}
			else
			rhs_temp += temp[k];
		}
		
		control_stmt[i].right[right_index++]=rhs_temp;
		insert_hash(hash_right,rhs_temp,i);
		control_stmt[i].var_on_right=right_index;
	}
}