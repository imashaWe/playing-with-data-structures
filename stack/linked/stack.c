#include <stdlib.h>
#include <stdbool.h>

typedef int EntryType;

typedef struct node {
    EnteryType data;
    struct node *next;
} Node;

typedef struct stack {
    int numItems;
    Node *top;
} Stack;


bool IsStackEmpty(Stack *s)
{
    return s->top == NULL;
}

void CreateStack(Stack *s)
{
    s->top = NULL;
    s->numItems = 0;
}

void Push(EntryType item,Stack *s)
{
    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->data = item;
    np->next = s->top;

    s->top = np;
    s->numItems++;

}

void Pop(EntryType *item,Stack *s)
{
    Node *temp;
    temp = s->top;

    s->top = s->top->next;
    s->numItems--;

    *item = temp->data;

    free(temp);
}

