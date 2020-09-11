// C program to demonstrate Queue operations
#include <stdio.h>
#include <stdlib.h>

// Linked list to store queue entry
struct QNode {
    char key;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

// Create new linked list node
/**
 * @brief Funtion to create a Linnked List for Queue 
 * @param key   Value to insert in queue node
 */
struct QNode* newNode(char key)
{
    struct QNode* newnode = (struct QNode*)malloc(sizeof(struct QNode));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

/**
 * @brief Funtion to create a queue. 
 */
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

/**
 * @brief Function to insert elements to queue.
 * 
 * @param q Queue to insert element in
 * @param key   value to insert in queue node
 * 
 */
void enQueue(struct Queue* q, char key)
{
    // Create a new linked list node
    struct QNode* newnode  = newNode(key);

    // Add newnode to Queue q
    if (q->rear == NULL)    // if queue is empty
    {
        q->front = q->rear = newnode;
        return;
    }

    // If queue is not empty, add newnode at the end of rear
    q->rear->next = newnode;
    q->rear = newnode;
}

/**
 * @brief Function to delete elements from queue.
 * 
 * @param q Queue to delete element from
 * 
 */
char deQueue(struct Queue* q)
{   
    char key;
    // Check if queue is empty
    if (q->front == NULL)
    {
        printf("\nQUEUE EMPTY!! Cannot delete. RETURN. ");
        return '\0';
    }

    struct QNode* temp = q->front;

    q->front = q->front->next;

    if( q->front == NULL)
        q->rear = NULL;

    key = temp->key;
    free(temp);
    return key;
}

/**
 * @brief Function to display the queue.
 * 
 * @param q Queue to display
 * 
 */
void show(struct Queue* q)
{
    struct QNode *temp = q->front;
    printf("\nPrinting Queue:\n(FRONT)-- ");
    while(temp->next != NULL )
    {
        printf("%c --> ", temp->key);
        temp = temp->next;
        if (temp == q->front)
        {
            printf("(REAR -----> FRONT)\n");
            return;
        }
    }
    printf("(REAR)\n");
}

/**
 * @brief Function to display the queue.
 * 
 * @param q Queue to initialize
 */
void initQueue(struct Queue *q)
{
    char key = 'A';
    printf("\nInitializing Queue...\n");
    for ( ; key <= 'G'; key++)
    {
        
        enQueue(q, key);
        show(q);
    }
}

void deallocate(struct Queue *q)
{
    struct QNode *current = q->front, *temp;
    while( current != NULL )
    {
        temp = current;
        free(temp);

        current = current->next;
    }
}

// Driver Code
int main()
{
    struct Queue* q = createQueue();
    // initialize queue (i)
    initQueue(q);
    // (ii) Remove 2 elments from queue
    printf("\nRemoved Element: %c", deQueue(q));
    show(q);
    printf("\nRemoved Element: %c", deQueue(q));
    show(q);
    printf("\nDONE.\n");

    deallocate(q);
    free(q);
}
