#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef int EntryType;

typedef struct queue {

    int count;
    int front;
    int rear;

    EntryType entry[MAX_SIZE];

} Queue;

bool IsQueueEmpty(Queue *q)
{
    return q->count == 0;
}

bool IsQueueFull(Queue *q)
{
    return q->count == MAX_SIZE;
}

void Create(Queue *q)
{
    q->count++;
    q->front = q->rear = -1;
}

void Insert(EntryType item,Queue *q)
{
    if (IsQueueFull(q)) {

        printf("queue is full");
        exit(1);

    } else {

        if (IsQueueEmpty(q)) {
            q->front = 0;
        }

        q->rear = (q->rear + 1) % MAX_SIZE;
        q->entry[q->rear] = item;
        q->count++;
    }
}

void Remove(EntryType *item,Queue *q)
{
    if (IsQueueEmpty(q)) {

        printf("Queue empty");
        exit(1);

    } else {

        *item = q->entry[q->front];

        q->front = (q->front + 1) % MAX_SIZE;
        q->count--;

    }

}

