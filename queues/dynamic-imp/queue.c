#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

int main()
{
    Queue q;
    Create(&q);

    for (int i = 0; i < 50; i++) {
        Insert(i+1,&q);
    }


    for (int i = 0; i < 20; i++) {
        int num;
        Remove(&num,&q);
        printf("removed %d\n",num);
    }

   Node *np;

   np = q.front;

   while (np) {
        printf("%d\n",np->data);
        np = np->next;
   }

}
