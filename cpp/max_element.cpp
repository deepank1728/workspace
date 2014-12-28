/*Given an array of integers which is initially increasing and then decreasing, 
find the maximum value in the array. Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1} 
Output: 500 Input: arr[] = {1, 3, 50, 10, 9, 7, 6} Output: 50 Corner case (No decreasing part) 
Input: arr[] = {10, 20, 30, 40, 50} Output: 50 Corner
 case (No increasing part) Input: arr[] = {120, 100, 80, 20, 0} Output: 120
 
 */
 
 #include<iostream>
 
 using namespace std;
 
 int find_max(int a[],int lower,int upper)
 {
 	int mid=(lower+upper)/2;
 	
 	if(a[mid]>=a[mid-1] && a[mid]>a[mid+1])
 		return a[mid];
 		
 	else
 	{
 		if(mid==lower+1 && a[mid]<=a[mid-1] && a[mid]>=a[mid+1])
 			return a[lower];
 		if(mid==upper-1 && a[mid]<=a[mid+1] && a[mid]>=a[mid-1])
 			return a[upper];
 			
 		if(lower<mid)
 		{
 			if(a[mid]>=a[mid-1] && a[mid]<=a[mid+1])
	 			find_max(a,mid,upper);
	 		else if(a[mid]<=a[mid-1] && a[mid]>=a[mid+1])
	 			find_max(a,lower,mid);
 		}
 	}

 }
 
 int main()
 {
 	int a[]={10,8},size=2;
 	int result=find_max(a,0,size-1);
 	
 	cout<<result<<endl;
 }
