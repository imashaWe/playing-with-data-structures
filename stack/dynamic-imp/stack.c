#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int EnteryType;

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

void Push(EnteryType item,Stack *s)
{
    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->data = item;
    np->next = s->top;

    s->top = np;
    s->numItems++;
}

void Pop(EnteryType *item,Stack *s)
{
    Node *temp;
    temp = s->top;

    s->top = s->top->next;
    s->numItems--;

    *item = temp->data;

    free(temp);
}

int main()
{
    Stack s;
    CreateStack(&s);

    for (int i = 0; i < 20; i++) {
        Push(i,&s);
    }

    for (int i = 0; i < 5; i++) {
        int num;
        Pop(&num,&s);
        printf("deleted %d\n",num);
    }

   Node *np;
   np = s.top;
   while (np) {
        printf("%d\n",np->data);
        np = np->next;
   }
}
