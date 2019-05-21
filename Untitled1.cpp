#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
 
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int ctr)
{

	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = ctr + 1;
 
	while (i <= ctr && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= ctr)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int ctr;
	if (low < high)
	{
		ctr=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low,ctr);
		MergeSort(a, ctr+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, ctr);
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "
		    <<i+1
		    <<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 
	        // Printing the sorted data
	cout<<"\n the data which has been merge sorted";
	for (i = 0; i < n; i++)
        cout<<" "
		    <<arr[i];
 
	return 0;
}
