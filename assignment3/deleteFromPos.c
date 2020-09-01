// Delete elements from Array

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int arr[MAX] = {0}; // array

int numRandom()
{
	int lower = 15, upper=450;
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int main()
{
  int i, pos, value;
  int choice;
	char ch = 'y';

	int N; 	//number of elements
	printf("The array if of fixed size 100.\nHow many elements do you want to begin with?\n");
	scanf("%d",&N);

	if(N<=MAX){
		for (i=0; i<N; ++i)
			arr[i] = numRandom();

    printf("Array[ POSITION ] is ----> \n");
    for (i=0; i<N; i++)
      printf("array[%d]\t--->\t%d\n", i, arr[i]);
    printf("\n");
  }

  while ( N < MAX && N>0 && ch == 'y' || ch == 'Y')
  {
		// Choosing deletion position
		{
  		printf("\nChose deletion position. Enter position [0 -- %d]: ", (N-1));
      scanf("%d", &pos);
      if(pos >= N)
      	{
        	printf("Position does not exist. Exiting...");
          exit(0);
        }
    }	// Choosing pos

    printf("Array[ POSITION ] before deletion\n");
		for (i=0; i<N; i++)
			printf("array[%d]\t--\t%d\n", i, arr[i]);
		printf("\n");

    // Delete element and shift the rest elements
    printf("\nDeleted Element: %d\n\n", arr[pos]);
    for (i=pos; i<(N-1); i++)
      arr[i] = arr[i+1];
    N--;

    printf("Array[ POSITION ] after deletion\n");
		for (i=0; i<N; i++)
			printf("array[%d]\t--\t%d\n", i, arr[i]);
		printf("\n");

    printf("Continue Deletion? [y]/n :");
		getchar();
		ch = getchar();
		if (ch=='\n')
			ch = 'y';

  }
  if(N >= MAX)
		printf("\nOVERFLOW! -- Array cannot be initialized.\n");
  else if(N <= 0)
    printf("\nUNDERFLOW! -- Not enough elements. Array is empty.");
	printf("DONE.\n");

exit(0);
}
