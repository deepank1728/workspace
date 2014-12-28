#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int n;
	fstream file;
	file.open("cinput", ios::in);
	file >> n;
	
	cout << "Enter the number till you want the cluster" << endl;
	int clus;
	cin >> clus;
	
	string cluster[n];
	
	for(int i = 0; i < n; i++){
		cluster[i] = 'a' + i + '\0';
	}
	
	int index = 1;
	int minx, miny, i, j, min = 0;
	int matrix[n][n];
	
	for(i = 0; i < n; i++){
		for(j = 0; j <= i; j++){
			file >> matrix[i][j];
			matrix[j][i] = matrix[i][j];
		}
	}
	cout << endl << "L(0) = 0" << endl;
	while(index < n && clus > min){
		if(index != 1)
			cout << "L(" << index - 1 << ") = " << min << endl;
		cout << "Clusters are" << endl;
		for(int s = 0; s < n; s++){
			if(cluster[s] != "\0")
				cout << cluster[s] << endl;
		}
		cout << endl;	
		min = 65681;		
		for(i = 0; i < n; i++){
			for(j = 0; j < i; j++){
				if(matrix[i][j] == 0)
					continue;
				if(matrix[i][j] < min){
					min = matrix[i][j];
					minx = i;
					miny = j;
				}
			}
		}

		for(i = 0; i < n; i++){
			if(i == minx || i == miny) 
				continue;
			matrix[i][minx] = matrix[i][minx]>matrix[i][miny] ? matrix[i][miny] : matrix[i][minx];
			matrix[minx][i] = matrix[i][minx];
		}
		
		cluster[minx] += cluster[miny];
		cluster[miny] = "\0";
		
		for(i = 0; i < n; i++)
			matrix[i][miny] = matrix[miny][i] = 0;
			
		index++;
	}
	
	cout << "L(" << index - 1 << ") = " << min << endl;
	cout << endl;
	file.close();
}
