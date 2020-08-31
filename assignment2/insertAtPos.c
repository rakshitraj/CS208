// Program to insert a value at the start of an array

#include <stdio.h>

#define MAX 100	// maximum size of array

int main()
{
	int arr[MAX] = {0};
	int i, pos, value;
	char ch = 'y';

	int N = 4; 	// number of elements
	printf("The array if of fixed size 100.\nHow many elements do you want to begin with?\n\a");
	scanf("%d",&N);

	if(N<MAX){
		for (i=0; i<MAX; ++i)
			if(i<N)
				arr[i] = i+1;
			else
				arr[i] = 0;
	}

	// // insert at position
	// pos =0; 		// initial input position
  // printf("Insert the position(1-100). There are %d elements.\n", N);
	// scanf("%d",&pos);
	//
	// pos--;
	//
	// if (pos > N){
	// 		if(pos >= MAX)
	// 			ch == 'n';
	// 		N = pos;
	// 	}

	while ( N < MAX && ch == 'y' || ch == 'Y')
	{
		// insert at position
		pos =0; 		// initial input position
	  printf("Insert the position(1-100). There are %d elements.\n", N);
		scanf("%d",&pos);

		pos--;

		if (pos > N){
				if(pos >= MAX)
				{
					printf("Position out of scope.");
					break;
				}
				N = pos;
			}
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
