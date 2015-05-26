

float find_avgslack(int clck, resource *resource_set, int total)
{
	int slack=0, temp;
	float avg_slack;
	for(int i=0;i<total;i++)
	{
		temp = clck;
		while(temp < resource_set[i].tim)
		{
				temp += clck;		
		}
		slack += (temp-resource_set[i].tim);	
		
	}
	avg_slack = (slack*1.0)/total;
	return avg_slack;
	
}


int slack_minimization(resource *resource_set, int total)
{
	int max_delay = -1, clck, finalclock, min_delay = 999999;
	float avg_slack, utilization, max_util=0;

	for(int i=0;i<total;i++)
	{
		if(resource_set[i].tim > max_delay)
			max_delay = resource_set[i].tim;

		if(resource_set[i].tim < min_delay)
			min_delay = resource_set[i].tim;
	}

	for(int i=0;i<total;i++)
	{
		clck = resource_set[i].tim;
		while(clck <= max_delay)
		{
			avg_slack = find_avgslack(clck, resource_set, total);
			
			utilization = 1-((avg_slack*1.0)/clck);
			if(utilization > max_util)
			{
				max_util = utilization;
				finalclock = clck;
			}
			clck += resource_set[i].tim;
		}
	}
	return finalclock;
}