// C++ code to linearly search and find
// the position of an input query value in an array
// if not present return -1

#include <iostream>

using namespace std;

int search(int arr[], int n, int x) 
{
	int i;
	for (i=0; i<n; i++) {
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int main(void)
{
	int arr[] = {90, 22, 79, 59, 54, 12, 29, 47, 7, 96};
	int n = sizeof(arr) / sizeof(arr[0]);
	// input query
	int query;
	cout << "Input a query: ";
	cin >> query;
	
	int result = search(arr, n, query);
	(result == -1)? cout<<"Element is not present in array" 
		: cout<<"Element is present at position " << (result+1) << endl;
	
	return 0;
}
