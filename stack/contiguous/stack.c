#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef int EntryType;

typedef struct stack {
    int top;
    EntryType entry[MAX_SIZE];
} Stack;

void CreateStack(Stack *s)
{
    s->top = -1;
}

bool IsStackEmpty(Stack *s)
{
    return s->top == -1;
}

bool IsStackFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void Push(EntryType item,Stack *s)
{
    if (IsStackFull(s)) {

        printf("stack is full");
        exit(1);

    } else {

        s->entery[++s->top] = item;
    }

}

void Pop(EntryType *item,Stack *s)
{
    if (IsStackEmpty(s)) {

        printf("stack is empty");
        exit(1);

    } else {

        *item = s->entry[s->top--];

    }
}


