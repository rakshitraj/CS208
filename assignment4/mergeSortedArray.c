// Merge two sorted arrays to obtain a sorted arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX2 200

int arr1[MAX] = {0}, arr2[MAX] = {0};
int N1=0, N2=0;
int mergeArr[MAX2] = {0};

void dispArray(int arr[], int N)    // print array
{
  int i;
  for (i=0; i<N; i++)
    printf("array[%d]\t--->\t%d\n", i, arr[i]);
  printf("\n");
}

 // Compare function for quick Sort
int cmpfunc(const void * a, const void * b)
{
  return (*(int *)a - *(int *)b);
}

void sort() // sort initial arrays
{
  // Sort array 1
  qsort(arr1, N1, sizeof(int), cmpfunc);
  // Sort Array 2
  qsort(arr2, N2, sizeof(int), cmpfunc);
}

int randomNum(int lower, int upper) // return random numbers
{
  //int lower = 15, upper=450;
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

void init( ) // initialize both arrays
{
  int i;

  printf("The arrays are of fixed size 100.\nHow many elements in first array? : ");
  scanf("%d",&N1);
  if(N1>MAX)
  {
    printf("OVERFLOW! Exiting with status 1...");
    exit(1);
  }

  printf("How many elements in second array? : ");
  scanf("%d",&N2);
  if(N2>MAX)
  {
    printf("OVERFLOW! Exiting with status 1...");
    exit(1);
  }

  for(i=0; i<N1; i++)
    arr1[i] = randomNum(15, 450);

  for(i=0; i<N2; i++)
    arr2[i] = randomNum(20, 200);

  // Sort both arrays
  sort();
}

void merge() // merge sorted arrays
{
  int a; // first element of array 1
  int b; // first element of array 2
  int i=0, j=0, k=0;

  while(i<N1 || j<N2 && k<=((N1-1)+(N2-1)))
  {
    a = arr1[i];
    b = arr2[j];

    if (a<=b)
    {
      mergeArr[k] = a;
      k++;
      i++;
    }
    else
    {
      mergeArr[k] = b;
      k++;
      j++;
    }
  }
}

int main()
{
  init();
  printf("\nThe first array is: \n");
  dispArray(arr1, N1);
  printf("\nThe second array is: \n");
  dispArray(arr2, N2);
  merge();
  printf("\nThe sorted, merged array is: \n");
  dispArray(mergeArr, (N1+N2));
  printf("DONE!");
  return 0;
}
