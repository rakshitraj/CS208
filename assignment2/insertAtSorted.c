// Program to insert a value at its sorted position in an randomly generated array.

#include <stdio.h>

#define MAX 100	// maximum size of array

// Compare function
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
 }

int numRandom()
{
	int lower = 15, upper=450;
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int getPos(int arr[], int N, int value)
{
	int i;
	for (i=0; i<N; i++)
		if( arr[i] > value)
		 break;
	return i;
}

int main()
{
	int arr[MAX] = {0};
	int i, pos, value;
	char ch = 'y';

	int N = 4; 	// number of elements
	printf("The array if of fixed size 100.\nHow many elements do you want to begin with?\n\a");
	scanf("%d",&N);

	if(N<MAX){
		for (i=0; i<N; ++i)
			arr[i] = numRandom();
	}

	// Sort array using qsort
	qsort(arr, N, sizeof(int), cmpfunc);

	while ( N < MAX && ch == 'y' || ch == 'Y')
	{
		printf("Array before insertion\n");
		for (i=0; i<N; i++)
			printf("array[%d] -- %d\n", i, arr[i]);
		printf("\n");

		// Element to be inserted
		printf("Enter an integer to insert: ");
		scanf("%d",&value);

		// Get position to inserte
		pos = getPos( arr, N, value);

		// Insert element
		// increse element count
		N++;

		// shift elements
		for(i=(N-1); i>pos; --i)
			arr[i] = arr[i-1];
		arr[pos] = value;

		// print updated array
		printf("Array after insertion\n");
		for (i=0; i<N; i++)
			printf("array[%d] -- %d\n", i, arr[i]);
		printf("\n");

		printf("Continue Insertion? [y]/n :");
		getchar();
		ch = getchar();
		if (ch=='\n')
			ch = 'y';



	}
	if(N >= MAX)
		printf("\nOVERFLOW! -- Array is full. No more inserion.\n");
	printf("DONE.\n");
}
