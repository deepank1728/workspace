
#define max_hash_size 100

struct cs_id_node
{
	int id;
	struct cs_id_node *next;
};
struct resource
{
	string name;
	int last_serviced;
 	int waiting_time, instances;
	int tim, res_id, stmt_executed;
	double area;
	cs_id_node *next;
};




struct cs_node
{
	string cs_stmt;
	int cs_id;
	bool type;
	string left;
	string *right;
	int var_on_right;
	char *oper;
	int dep_count;
	bool executed;
};



struct index_node
{
	int index;
	struct index_node *next;
};
struct hash_node
{
	string var_name;
	struct hash_node *next;
	index_node *below;
};


struct i_node
{
	string stmt;
	int cs_id;
	struct i_node *next;
};

