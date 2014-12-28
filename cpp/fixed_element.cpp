/*Given an array of n distinct integers sorted in ascending order, 
write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array,
 else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i.
  Note that integers in array can be negative.
   Examples: Input: arr[] = {-10, -5, 0, 3, 7} Output: 3 // arr[3] == 3 Input: arr[] = {0, 2, 5, 8, 17} Output: 0 // arr[0] == 0 
   Input: arr[] = {-10, -5, 3, 4, 7, 9} Output: -1 // No Fixed Point
   */
   
#include<iostream>
#include<cstdlib>

using namespace std;

int fixed_point(int a[],int lower,int upper,int size)
{
	//int *r=(int *)malloc(sizeof(int )*size),count=0,k=0;
	int mid;
	if(a[lower]==lower)
		return lower;
	if(a[upper]==upper)
		return upper;
	mid=(upper+lower)/2;
	if(a[mid]==mid)
		return mid;
	if(lower<mid)
	{
		if(a[i]>size)
			return -1;
	}
}

int main()
{
	int a[]={0, 1, 5, 7, 17},size=5,r;
	r=fixed_point(a,0,size-1,size-1);
	cout<<r<<endl;
	
}
