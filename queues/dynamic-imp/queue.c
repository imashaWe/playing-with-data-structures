#include <stdlib.h>
#include <stdbool.h>

typedef int EntryType;

typedef struct node {
    EntryType data;
    struct node *next;
} Node;


typedef struct queue {
    int count;
    Node *front;
    Node *rear;
} Queue;

bool IsQueueEmpty(Queue *q)
{
    return q->count == 0;
}

void Create(Queue *q)
{
    q->count = 0;
    q->front = q->rear = NULL;
}

void Insert(EntryType item,Queue *q)
{

    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->data = item;
    np->next = NULL;

    if (IsQueueEmpty(q)) {

        q->front = q->rear = np;

    } else {

        q->rear->next = np;
        q->rear = np;

    }

    q->count++;


}

void Remove(EntryType *item,Queue *q)
{
    if (IsQueueEmpty(q)) {

        printf("Queue is empty");
        exit(1);

    } else {

        Node *temp;
        temp = q->front;

        *item = temp->data;

        q->front = q->front->next;
        q->count--;

        free(temp);

    }

}
