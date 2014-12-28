#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct coordinate{
	float x, y;
};

float manhatten(coordinate first, coordinate second){
	return abs(first.x - second.x) + abs(first.y - second.y);
}

int main(){
	cout << "Enter the value of k" << endl;
	int k;
	cin >> k;
	
	coordinate *prevcentroid = new coordinate[k];
	coordinate *centroid = new coordinate[k];
	
	fstream file;
	file.open("input", ios::in);
	int n;
	file >> n;
	coordinate *a = new coordinate[n];
	for(int i = 0; i < n; i++){
		file >> a[i].x >> a[i].y;
	}
	
	for(int i = 0; i < k; i++){
		prevcentroid[i] = centroid[i] = a[i];
	}
	
	float dist[n][k], sumx, sumy;
	int minIndex, count;
	bool flag;
	while(!flag){
		flag = true;
		for(int i = 0; i < n; i++){
			minIndex = 0;
			for(int j = 0; j < k; j++){
				dist[i][j] = manhatten(centroid[j],a[i]);
				if(dist[i][j] < dist[i][minIndex])
					minIndex = j;
			}
			dist[i][minIndex] = -1;
			/*for(int j = 0; j < k; j++)
				cout << dist[i][j] << "\t";
			cout << endl;*/
		}
		//cout << endl << endl;
		for(int i = 0; i < k; i++){
			sumx = sumy = count = 0;
			for(int j = 0; j < n; j++){
				if(dist[j][i] == -1){
					count++;
					sumx += a[j].x;
					sumy += a[j].y;
				}
			}
			centroid[i].x = sumx * 1.0 / count;
			centroid[i].y = sumy * 1.0 / count;
		}
		
		for(int i = 0; i < k; i++){
			if(centroid[i].x != prevcentroid[i].x || centroid[i].y != prevcentroid[i].y)
				flag = false;
		}
		for(int i = 0; i < k; i++){
			prevcentroid[i] = centroid[i];
		}
	}
	cout << "Clusters are " << endl << endl;
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			if(dist[j][i] == -1)
				cout << "(" << a[j].x << "," << a[j].y << ")  ";
		}
		cout << endl << endl;
	}
}
