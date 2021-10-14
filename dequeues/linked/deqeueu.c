#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int EntryType;

typedef struct node {

    EntryType data;

    struct node *previous;
    struct node *next;

} Node;

typedef struct dequeue {
    int count;

    Node *front;
    Node *rear;

} Dequeue;

void CreateDeqeueue(Dequeue *dq)
{
    dq->front = dq->rear = NULL;
    dq->count = 0;
}

bool IsDequeueEmpty(Dequeue *dq)
{
    return dq->front == NULL && dq->rear == NULL;
}

void InsertRear(EntryType item,Dequeue *dq)
{
    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->data = item;

    if (IsDequeueEmpty(dq)) {

        dq->front = dq->rear = np;

    } else {

        np->previous = dq->rear;
        np->next = NULL;

        dq->rear->next = np;
        dq->rear = np;

    }

    dq->count++;
}

void InsertFront(EntryType item,Dequeue *dq)
{
    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->data = item;

    if (IsDequeueEmpty(dq)) {

        dq->front = dq->rear = np;

    } else {

         np->next = dq->front;
         np->previous = NULL;

         dq->front->previous = np;
         dq->front = np;

    }

    dq->count++;

}

void RemoveRear(EntryType *item,Dequeue *dq)
{
    if (IsDequeueEmpty(dq)) {

        printf("Dequeue is empty");
        exit(1);

    } else {

        Node *temp;
        temp = dq->rear;

        *item = temp->data;

        dq->rear = dq->rear->previous;

        if (!dq->rear) {

            dq->front = NULL;

        } else {

            dq->rear->next = NULL;

        }

        free(temp);

        dq->count--;
    }
}

void RemoveFront(EntryType *item,Dequeue *dq)
{
    if (IsDequeueEmpty(dq)) {

        printf("Dequeue is empty");
        exit(1);

    } else {

        Node *temp;
        temp = dq->front;

        *item = temp->data;

        dq->front = dq->front->next;

        if (!dq->front) {

            dq->rear = NULL;

        } else {

            dq->front->previous = NULL;

        }

        free(temp);

        dq->count--;
    }
}

void Display(Dequeue *dq)
{
    Node *np;

    np = dq->front;

    while (np) {

        printf("%d\n",np->data);
        np = np->next;
    }
}
