// C code to linearly search for query in array
// is present then return its location, otherwise 
// return -1 
  
#include <stdio.h> 
  
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = {90, 22, 79, 59, 54, 12, 29, 47, 7, 96};
    int n = sizeof(arr) / sizeof(arr[0]); 
    // Take query input
    int query;
    printf("Enter an integer query: ");
    	// Since scanf() expects (int *), passing integer leads to
    	// Segmentation fault (core dumped)
    scanf("%d", &query);

    // Calling linear search
    int result = search(arr, n, query); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d \n", 
                            (result+1)); 
    return 0;
}
