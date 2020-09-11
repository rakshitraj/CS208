// C program to demonstrate Circular Queue Operation
#include <stdio.h>
#include <stdlib.h>

struct qnode {
    char key;
    struct qnode *next;
};

struct queue {
    struct qnode *front, *rear;
};

struct qnode* newNode(char key)
{
    struct qnode* newnode = (struct qnode*)malloc(sizeof(struct qnode));
    newnode->key = key;
    newnode->next = NULL;
}

struct queue* createQueue()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct queue *q, char key)
{
    struct qnode* newnode = newNode(key);

    if(q->rear == NULL)
    {
        q->front = q->rear = newnode;
        // circular queue
        q->rear->next = q->front;
        return;
    }

    newnode->next = q->front;
    q->rear->next = newnode;
    q->rear = newnode;
}

char deQueue(struct queue* q)
{
    char key;
    if (q->front == NULL)
    {
        printf("\nQueue Empty!! Cannot delete elements. ");
        return '\0';
    }

    struct qnode *temp = q->front;
    key = q->front->key;
    if(q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front; 
    }
    free(temp);
    return key;
}

/**
 * @brief Function to display the queue.
 * 
 * @param q Queue to display
 * 
 */
void show(struct queue* q)
{
    struct qnode *temp = q->front;
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
void initQueue(struct queue *q)
{
    char key = 'A';
    printf("\nInitializing Queue...\n");
    for ( ; key <= 'G'; key++)
    {
        enQueue(q, key);
        show(q);
    }
}

void deallocate(struct queue *q)
{
    struct qnode *current = q->front, *temp;
    q->rear->next = NULL;
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
    struct queue* q = createQueue();

    // initialize queue (i)
    initQueue(q);
    // (ii) Remove 2 elments from queue
    printf("\nRemoved Element: %c", deQueue(q));
    show(q);
    printf("\nRemoved Element: %c", deQueue(q));
    show(q);
    printf("\nAdding Element: %c",'H'); 
    enQueue(q, 'H');
    show(q);

    printf("\nDONE.\n");

    // deallocate(q);
    free(q);
}