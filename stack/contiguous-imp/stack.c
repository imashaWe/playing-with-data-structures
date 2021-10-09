#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef int EnteryType;

typedef struct stack {
    int top;
    EnteryType entery[MAX_SIZE];
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

void Push(EnteryType item,Stack *s)
{
    if (IsStackFull(s)) {
        printf("stack is full");
        exit(1);
    } else {
        s->entery[++s->top] = item;
    }

}

void Pop(EnteryType *item,Stack *s)
{
    if (IsStackEmpty(s)) {
        printf("stack is empty");
        exit(1);
    } else {
        *item = s->entery[s->top--];
    }
}

int main()
{
    Stack s;

    CreateStack(&s);

    for (int i = 0; i < 50; i++) {
        Push(i,&s);
    }

    for (int i = 0; i < 10; i++) {
        int n;
        Pop(&n,&s);
        printf("deleted %d\n",n);
    }
   int i = 0;
   while(!IsStackEmpty(&s)) {
    printf("%d\n",s.entery[i++]);
   }
}


