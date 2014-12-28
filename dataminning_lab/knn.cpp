#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;

int abs(int a){
	
	if(a<0)
		return -1*a;
	else
		return a;
}

int main()
{
    int dimensions,points,K;
    
    ifstream q("input_knn");
     q>> dimensions;
    q>> points;
    q>> K;

	cout<<dimensions<<points<<K<<endl;
    int array[points][dimensions], newpoint[dimensions],classes[points];
    for(int i=0;i<points;i++)
    {
        for(int j=0;j<dimensions;j++)
        {
            q>> array[i][j];
        }
        q>> classes[i];
    }
   
    for(int j=0;j<dimensions;j++)
    {
        q>> newpoint[j];
    }
    int finalset[K];
    int distancefromnew[K];
    for(int j=0;j<K;j++)
        distancefromnew[j] = 0;

    int maxdistance,distance=0,dis,maximum=-9999999,reject;
    int i=0;
    for(i=0;i<K;i++)
    {
        finalset[i] = i;
        for(int j=0;j<dimensions;j++)
        {
            distancefromnew[i] += abs(array[i][j] - newpoint[j]);
        }
    }
    while(i<points)
    {
        maximum = -99999;
        for(int j=0;j<K;j++)
        {
            if(distancefromnew[j]> maximum){
                maximum = distancefromnew[j];
                reject = j;
            }
        }
        dis=0;
        for(int j=0;j<dimensions;j++)
        {
            dis += abs(array[i][j] - newpoint[j]);
        }
        if(dis < maximum)
        {
            finalset[reject] = i;
            distancefromnew[reject] = dis;
        }
        i++;
    }

    int counter=0;
    for(int j=0;j< K;j++)
    {
        if(classes[finalset[j]] == 1)
            counter++;
        else
            counter--;
    }
    for(int j=0;j< K;j++)
    {
        cout << finalset[j] << "    ";
    }
    if(counter >=0)
        cout << "the new point belongs to class 1\n";
    else
        cout << "the new point belongs to class 2\n";

}

