#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include<fstream>
#include<cstdlib>
using namespace std;
#define M 20

int MAXLEN;

char filename[255]="id3_input";
vector <vector <string> > state;
vector <string> item(M);
vector <string> attribute_row;
string end("end");
string yes("C1");
string no("C2");
string blank("");
string all_attribute[M];
int total_no_class_attr;
map<string,vector < string > > map_attribute_values;
int tree_size = 0;
struct Node{
	string attribute;//
	string arrived_value;//
	vector<Node *> childs;//
	Node(){
		attribute = blank;
		arrived_value = blank;
	}
};
Node * root;

//map
void map__attribute(){
	unsigned int i,j,k;
	bool exited = false;
	vector<string> values;
	cout<<"fine in\n";
	for(i = 1; i < MAXLEN-1; i++){//
		for (j = 1; j < state.size(); j++){
			for (k = 0; k < values.size(); k++){
				if(!values[k].compare(state[j][i])) exited = true;
			}
			if(!exited){
				values.push_back(state[j][i]);//Vector?it?vector
			}
			exited = false;
		}
		
		map_attribute_values[state[0][i]] = values;
		values.erase(values.begin(), values.end());
	}
	
}

//
double Entropy(vector <vector <string> > remain_state, string attribute, string value,bool ifparent){
	vector<int> count (2,0);
	unsigned int i,j;
	bool done_flag = false;//
	for(j = 1; j < MAXLEN; j++){
		if(done_flag) break;
		if(!attribute_row[j].compare(attribute)){
			for(i = 1; i < remain_state.size(); i++){
				if((!ifparent&&!remain_state[i][j].compare(value)) || ifparent){//ifparent
					if(!remain_state[i][MAXLEN - 1].compare(yes)){
						count[0]++;
					}
					else count[1]++;
				}
			}
			done_flag = true;
		}
	}
	if(count[0] == 0 || count[1] == 0 ) return 0;//
	double sum = count[0] + count[1];
	double entropy = -count[0]/sum*log(count[0]/sum)/log(2.0) - count[1]/sum*log(count[1]/sum)/log(2.0);
	return entropy;
}

//attribute
double ComputeGain(vector <vector <string> > remain_state, string attribute){
	unsigned int j,k,m;
	//
	double parent_entropy = Entropy(remain_state, attribute, blank, true);
	double children_entropy = 0;
	//
	vector<string> values = map_attribute_values[attribute];
	vector<double> ratio;
	vector<int> count_values;
	int tempint;
	for(m = 0; m < values.size(); m++){
		tempint = 0;
		for(k = 1; k < MAXLEN - 1; k++){
			if(!attribute_row[k].compare(attribute)){
				for(j = 1; j < remain_state.size(); j++){
					if(!remain_state[j][k].compare(values[m])){
						tempint++;
					}
				}
			}
		}
		count_values.push_back(tempint);
	}

	for(j = 0; j < values.size(); j++){
		ratio.push_back((double)count_values[j] / (double)(remain_state.size()-1));
	}
	double temp_entropy;
	for(j = 0; j < values.size(); j++){
		temp_entropy = Entropy(remain_state, attribute, values[j], false);
		children_entropy += ratio[j] * temp_entropy;
	}
	return (parent_entropy - children_entropy);
}

int FindAttriNumByName(string attri){
	for(int i = 0; i < MAXLEN; i++){
		if(!state[0][i].compare(attri)) return i;
	}
	cerr<<"can't find the numth of attribute"<<endl;
	return 0;
}

///
string MostCommonLabel(vector <vector <string> > remain_state){
	int p = 0, n = 0;
	int array[total_no_class_attr];
	
	
	for(unsigned i = 0; i < remain_state.size(); i++){
		if(!remain_state[i][MAXLEN-1].compare(yes)) p++;
		else n++;
	}
	if(p >= n) return yes;
	else return no;
	
	//return all_attribute[max_i];
}

//label
bool AllTheSameLabel(vector <vector <string> > remain_state, string label){
	int count = 0;
	for(unsigned int i = 0; i < remain_state.size(); i++){
		if(!remain_state[i][MAXLEN-1].compare(label)) count++;
	}
	if(count == remain_state.size()-1) return true;
	else return false;
}


Node * BulidDecisionTree(Node * p, vector <vector <string> > remain_state, vector <string> remain_attribute){
	//if(remain_state.size() > 0){
		//printv(remain_state);
	//}
	
	
	if (p == NULL)
		p = new Node();
	//
	
	if (AllTheSameLabel(remain_state, yes)){
		p->attribute = yes;
		return p;
	}
	if (AllTheSameLabel(remain_state, no)){
		p->attribute = no;
		return p;
	}
	
	
	/*
	for(int i=0;i<total_no_class_attr;i++)
	{
		if (AllTheSameLabel(remain_state,all_attribute[i])){
			p->attribute = all_attribute[i];
			return p;
		}
	
	}
	*/
	cout<<"kkkksss\n";
	if(remain_attribute.size() == 0){//,
		string label = MostCommonLabel(remain_state);
		p->attribute = label;
		return p;
	}
	cout<<"dfdsfdf\n";

	double max_gain = 0, temp_gain;
	vector <string>::iterator max_it = remain_attribute.begin();
	vector <string>::iterator it1;
	for(it1 = remain_attribute.begin(); it1 < remain_attribute.end(); it1++){
		temp_gain = ComputeGain(remain_state, (*it1));
		if(temp_gain > max_gain) {
			max_gain = temp_gain;
			max_it = it1;
		}
	}
	//max_it?
	
	vector <string> new_attribute;
	vector <vector <string> > new_state;
	for(vector <string>::iterator it2 = remain_attribute.begin(); it2 < remain_attribute.end(); it2++){
		if((*it2).compare(*max_it)) new_attribute.push_back(*it2);
	}
	//?
	
	p->attribute = *max_it;
	cout<<*max_it<<endl;
	vector <string> values = map_attribute_values[*max_it];
	cout<<"dfdsfdf\n";
	int attribue_num = FindAttriNumByName(*max_it);
	new_state.push_back(attribute_row);
	for(vector <string>::iterator it3 = values.begin(); it3 < values.end(); it3++){
		for(unsigned int i = 1; i < remain_state.size(); i++){
			if(!remain_state[i][attribue_num].compare(*it3)){
				new_state.push_back(remain_state[i]);
			}
		}
		Node * new_node = new Node();
		new_node->arrived_value = *it3;
		if(new_state.size() == 0){//?new_node
			cout<<"not cool\n";
			new_node->attribute = MostCommonLabel(remain_state);
			cout<<"cool\n";
		}
		else
			BulidDecisionTree(new_node, new_state, new_attribute);
		//1  2new_state
		p->childs.push_back(new_node);
		new_state.erase(new_state.begin()+1,new_state.end());//new_state?
	}
	return p;
}

void Input(){

    ifstream q(filename);

	q>>MAXLEN;
	string s;
	
	while(q>>s,s.compare(end) != 0){//-1
		item[0] = s;
		for(int i = 1;i < MAXLEN-1; i++){
			q>>item[i];
		}
		state.push_back(item);//?
	}
	
	
	for(int j = 0; j < MAXLEN; j++){
		attribute_row.push_back(state[0][j]);
	}
}

void PrintTree(Node *p, int depth){
	for (int i = 0; i < depth; i++) cout << '\t';//tab
	if(!p->arrived_value.empty()){
		cout<<p->arrived_value<<endl;
		for (int i = 0; i < depth+1; i++) cout << '\t';//tab
	}
	cout<<p->attribute<<endl;
	for (vector<Node*>::iterator it = p->childs.begin(); it != p->childs.end(); it++){
		PrintTree(*it, depth + 1);
	}
}



int main(){
	Input();
	vector <string> remain_attribute;
	
	ifstream fs(filename);
	string str="";
	int garbage;
	fs>>garbage;
	
	for(int i=0;i<MAXLEN;i++)
	{
		fs>>str;
		remain_attribute.push_back(str);
		str="";
	}
	
	vector <vector <string> > remain_state;
	for(unsigned int i = 0; i < state.size(); i++){
		remain_state.push_back(state[i]);
	}
	map__attribute();
	root = BulidDecisionTree(root,remain_state,remain_attribute);
	cout<<"the decision tree is :"<<endl;
	PrintTree(root,0);
	cout<<endl;
	//cout<<"tree_size:"<<tree_size<<endl;
	return 0;
}

