ofstream file("permutation.txt");

void print_file(resource *resource_list, int total, int *globalarray)
{
	for(int i=0;i<total ; i++)
	{
		if(globalarray[i] == 1)
		{
			file << resource_list[i].name;
			file << " 1 ";
			file << resource_list[i].area << " ";
			file << resource_list[i].tim << endl;
		}
		else
		{
			file << resource_list[i].name;
			file << " 0 0 0\n";
		}
	}
	file << "break\n";
}

void permute(int *globalarray, resource *resource_list, int count, double maxarea, double area, int index, int total)
{
	if(index == total)
	{
		if(count == 0)
			return;

		if(area<=maxarea)
			print_file(resource_list, total, globalarray);
			
		return;
	}
	
	permute(globalarray, resource_list, count, maxarea, area, index+1, total);
	globalarray[index] = 1;
	area += resource_list[index].area;
	permute(globalarray, resource_list, count+1, maxarea, area, index+1, total);
	globalarray[index] = 0;
}

void make_permutation(resource *resource_list, int total, double maxarea)
{
	int globalarray[total];
	for(int i=0;i<total;i++)
		globalarray[i] = 0;
	int count=0;

	permute(globalarray, resource_list, count, maxarea, 0, 0, total);

	file.close();
}