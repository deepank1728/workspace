
// *****************************operator functions**********************************************
int is_operator(char a){

	if(a=='+' || a== '-' ||  a=='*' || a=='/')
		return 1;
	return 0;
}

int count_operator(string s)
{
	int count=0, size = s.length();

	for(int i=0;i<size;i++)
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' ||  (i>=0 && s[i-1]!='/' && s[i]=='/' && s[i+1]!='/')  )
			count++;
		
	return count;
}

// *******************************************get functions********************************************

index_node *get_indexnode(int i)
{
	index_node *temp = (index_node *)new index_node();
	temp->index = i;
	temp->next = NULL;
	return temp;
}

hash_node *get_hashnode(string str)
{
	hash_node *temp = (hash_node *)new hash_node();
	temp->var_name = str;
	temp->next = NULL;
	temp->below = NULL;
	return temp;
}


int get_key( string str)
{

	int hashval=0,size=str.length();
	
	for(int i=0;i<size;i++)
		hashval += str[i];
	
	hashval = hashval % max_hash_size;
	return hashval;
}

cs_id_node *get_idnode(int ids)
{
	cs_id_node *t = new cs_id_node();
	t->next = NULL;
	t->id = ids;
	return t;
}


i_node *get_indnode(cs_node temp, int i)
{
	i_node *t = new i_node();
	t->stmt = temp.cs_stmt;
	t->cs_id = i;
	t->next = NULL;
	return t;
}
