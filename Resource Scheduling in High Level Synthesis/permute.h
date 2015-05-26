ofstream file("permutation.txt");

void print_file(resource *resource_list, int total, int *globalarray, int *categories)
{
	for(int i=0;i<3;i++)
	{
		if(categories[i] == 0)
		{
			return;
		}
	}
	for(int i=0;i<total ; i++)
	{
		if(globalarray[i] == 1)
		{
			file << resource_list[i].name;
			file << " " << resource_list[i].category;
			file << " ";
			file << resource_list[i].area << " ";
			file << resource_list[i].tim << endl;
		}
		else
		{
			file << resource_list[i].name;
			file << " " << resource_list[i].category;
			file << " 0 0\n";
		}
	}
	file << "break\n";
}

void permute(int *globalarray, resource *resource_list, int count, double maxarea, double area, int index, int total, int *categories)
{
	
	if(index == total)
	{
		if(count == 0)
			return;

		if(area<=maxarea)
			print_file(resource_list, total, globalarray, categories);
			
		return;
	}
	
	permute(globalarray, resource_list, count, maxarea, area, index+1, total, categories);

	globalarray[index] = 1;
	if(resource_list[index].category == "+")
		categories[0]++;
	else if(resource_list[index].category == "-")
		categories[1]++;
	else if(resource_list[index].category == "*")
		categories[2]++;
	else if(resource_list[index].category == "+-*")
	{
		categories[0]++;
		categories[1]++;
		categories[2]++;
		categories[3]++;
	}
	area += resource_list[index].area;

	permute(globalarray, resource_list, count+1, maxarea, area, index+1, total, categories);

	globalarray[index] = 0;
	if(resource_list[index].category == "+")
		categories[0]--;
	else if(resource_list[index].category == "-")
		categories[1]--;
	else if(resource_list[index].category == "*")
		categories[2]--;
	else if(resource_list[index].category == "+-*")
	{
		categories[0]--;
		categories[1]--;
		categories[2]--;
		categories[3]--;
	}
}

void make_permutation(resource *resource_list, int total, double maxarea)
{
	int globalarray[total];
	for(int i=0;i<total;i++)
		globalarray[i] = 0;
	int count=0, categories[4] = {0};

	permute(globalarray, resource_list, count, maxarea, 0, 0, total, categories);

	file.close();
}