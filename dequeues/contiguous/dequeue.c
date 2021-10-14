#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef int EntryType;

typedef struct dequeue {

    int front;
    int rear;
    int count;

    EntryType entry[MAX_SIZE];

} Dequeue;


void Create(Dequeue *dq)
{
    dq->front = dq->rear = -1;
    dq->count = 0;
}

bool IsDequeueEmpty(Dequeue *dq)
{
   return dq->front == -1;
}

bool IsDequeueFull(Dequeue *dq)
{
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

void InsertFront(EntryType item,Dequeue *dq)
{
    if (IsDequeueFull(dq)) {

        printf("Dequeue is full");
        exit(1);

    } else {

        if (IsDequeueEmpty(dq)) {

            dq->front = dq->rear = 0;

        } else {

            dq->front = dq->front == 0 ? MAX_SIZE - 1 : dq->front - 1;

        }

        dq->entry[dq->front] = item;
        dq->count++;

    }
}

void InsertRear(EntryType item,Dequeue *dq)
{
    if (IsDequeueFull(dq)) {

        printf("Dequeue is full");
        exit(1);

    } else {

        if (IsDequeueEmpty(dq)) {

            dq->rear = dq->front = 0;

        } else  {

            dq->rear = (dq->rear + 1) % MAX_SIZE;

        }

        dq->entry[dq->rear] = item;
        dq->count++;

    }
}

void RemoveFront(EntryType *item,Dequeue *dq)
{
    if (IsDequeueEmpty(dq)) {

        printf("Dequeue is empty");
        exit(1);

    } else {

        *item = dq->entry[dq->front];

        if (dq->front == dq->rear) {

            dq->front = dq->rear = -1;

        } else {

             dq->front = (dq->front + 1) % MAX_SIZE;

        }

        dq->count--;

    }
}


void RemoveRear(EntryType *item,Dequeue *dq)
{
    if (IsDequeueEmpty(dq)) {

        printf("Dequeue is empty");
        exit(1);

    } else  {

        *item = dq->entry[dq->rear];

         if (dq->front == dq->rear) {

            dq->rear = dq->front = -1;

        } else {

             dq->rear = dq->rear == 0 ? dq->rear = MAX_SIZE - 1 : dq->rear - 1;

        }

        dq->count--;

    }
}

void display(Dequeue *dq)
{
    int i = dq->front;

    while (i - 1 != dq->rear) {

        printf("%d\n",dq->entry[i]);

        i = (i + 1) % MAX_SIZE;

    };
}
