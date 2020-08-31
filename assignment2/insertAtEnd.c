// Program to insert a value at the end of an array

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10	// maximum size of array

int main()
{
	int arr[MAX] = {0};
	int i, pos, value;
	char ch = 'y';

	int N = 4; 	// number of elements
	for (i=0; i<N; ++i)
		arr[i] = i+1;

	pos =i; 		// initial input position
	while (pos <= MAX && ch == 'y' || ch == 'Y')
	{
		// Print the orignal array
		printf("Array before insertion\n");
		for (i=0; i<N; i++)
			printf("array[%d] -- %d\n", i, arr[i]);
		printf("\n");

		// Element to be inserted
		printf("Enter an integer to insert: ");
		scanf("%d",&value);

		// Insert element
		// increse element count
		N++;
		arr[pos] = value;
		pos ++;

		// print updated array
		printf("Array after insertion\n");
		for (i=0; i<N; i++)
			printf("array[%d] -- %d\n", i, arr[i]);
		printf("\n");

		printf("Continue Insertion? [y]/n :");
		getchar();
		ch = getchar();

	}
	if(pos > MAX)
		printf("\nOVERFLOW!\n");
	printf("DONE.\n");
}
