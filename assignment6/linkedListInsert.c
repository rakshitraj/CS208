// linked list operations
// 1. insert Node
// 2. delete Node

#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* prev;
  struct Node* next;

  int data;
};    // structure for nodes

struct Node* getNode(int* data) // Create Node
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  if(newNode == NULL)
  {
    printf("Error! Memory not allocated.\nmalloc() error. Exiting..." );
    exit(1);
  }
  // Enter data
  if (data == NULL)
  {
    printf("\nFill Node data field. Enter an integer value: ");
    scanf("%d", &(newNode->data));
  }
  else
    newNode->data = *data;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void displayList(struct Node *head, struct Node *tail) // Display Linked List
{
  struct Node* temp = head;
  printf("\nX--(HEAD) ");
  while (temp != tail)
  {
    printf("%d-->", temp->data);
    temp = temp->next;
  }
  printf("X (tail)\n");
}

int CreateList(struct Node *head, struct Node *tail) // Create Linked List
{
  int N = (rand() % (10)) + 1; // Arbitary number of nodes to begin with
printf("%d\n",N );
  int data;
  int upper= 10000, lower= 342;
  for (int i=0; i<N; i++)
  {
    data = (rand() % (upper - lower + 1)) + lower;
    struct Node* newNode = getNode( &data );
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

  return N;
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

void insertAtPos(int pos, int* size, struct Node *head, struct Node *tail) // insert node at position
{
  struct Node* current = head;
  // Check if the position is valid?
  if(pos <1 || pos > *size)
  {
    printf("Positonis Invalid. Cannot insertAtPos. Exiting with status code 1...");
    exit(1);
  }
  while(pos--)
  {
    if (pos==0)
    {
      // Adding node
      struct Node* temp = getNode(NULL);
      // Make the new node point to the next node
      temp->next = current;
      temp->prev = current->prev;
      current->prev = temp;
      // Updating the current position
      current = temp;
    }
    else
      current = current->next; // move ahead
  }
  size++;
}

int main()
{
  struct Node* head = NULL;
  struct Node* tail = NULL;

  int choice, pos;

  // Initailize a linked List
  int size = CreateList(head, tail);

  //Insert nodes
  displayList(head, tail);
  printf("\nSelect a node 'P' : ");
  scanf("%d",&pos);
  printf("Choose:\n1. Insert node before P\n2. Insert node after P\nYour Choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:   insertAtPos(pos, &size, head, tail);
              break;
    case 2:   insertAtPos((pos+1), &size, head, tail);
              break;
    default:  printf("Invalid Choice. Exiting...");
              exit(1);
  }
  displayList(head, tail);

  printf("Inserted Successfully.\n\nDeallocating memeory now...");
  deallocate(head, tail);
}
