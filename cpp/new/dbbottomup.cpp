
    
    
  
  
 #include<iostream>
 using namespace std;
 
 int main()
{
	int n=3,m=3;
	int **a=new int*[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
	}
	
	int k=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[i][j]=k++;
		}
	}
	
	k=0;
	for(int i = n-1; i > 0 ; i++) 
	{ 
		k = i;
	 	for(int j = 0; k<n,j<m;j++,k++)
	 		cout<<a[k][j]<<" "; 
	 } 
	 for(int j = 1; j< m ; j++)
	 { 
	 	 k = j;
	   for(int i =0 ; i<n,k <m ;i++,j++)
	   { 
	   		cout<<a[i][k]<<" ";
	   } 
	   
	}

}
