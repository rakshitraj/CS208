// C program to create a linked list
// with N elements

#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* prev;
  int data;
  struct Node* next;
};

// Create a Node
struct Node* Create()
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  if(newNode == NULL)
  {
    printf("Error! Memory not allocated.\nmalloc() error. Exiting..." );
    exit(1);
  }
  // Enter data
  printf("\nFill Node data field. Enter an integer value: ");
  scanf("%d", &(newNode->data));

  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void deallocate(struct Node *head, struct Node *tail)
{
  struct Node *current;
  while(head != tail)
  {
    current = head;
    head = head->next;
    free(current);
  }
  free(tail);
}

int main()
{
  struct Node* head = NULL;
  struct Node* tail = NULL;

  int N;
  printf("\nEnter the number of Nodes: " );
  scanf("%d",&N);
  printf("\nCreating...");

  int i;
  for (i=0; i<N; i++)
  {
    printf("\nCreating node Number %d...",(i+1) );
    struct Node *newNode = Create();
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  deallocate(head, tail);
}
