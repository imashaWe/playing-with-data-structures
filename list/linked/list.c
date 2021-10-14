#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int EntryType;

typedef struct node {

    EntryType data;

    struct node *next;

} Node;

typedef struct list {

    int count;
    Node *head;

} List;

void CreateList(List *l)
{
    l->head = NULL;
}

bool IsListEmpty(List *l)
{
    return l->head == NULL;
}

bool IsListFull(List *l)
{
    return false;
}

int ListSize(List *l)
{
    return l->count;

}

void InsertStart(EntryType item,List *l)
{
     if (IsListFull(l)) {

        printf("List is full");
        exit(1);

    } else {

        Node *np;
        np = (Node *)malloc(sizeof(Node));

        np->data = item;

        if (IsListEmpty(l)) {

            l->head = np;
            np->next = NULL;

        } else {

            np->next = l->head;
            l->head = np;

        }

        l->count++;

    }

}

void Insert(EntryType item,int position,List *l)
{
    if (IsListFull(l)) {

        printf("List is full");
        exit(1);

    } else if(position < 0 || position > l->count) {

        printf("The position is out of index");
        exit(1);

    } else {

       Node *np;
       np = (Node *)malloc(sizeof(Node));

       np->data = item;

       Node *temp;
       temp = l->head;

       for (int i = 0; i < position - 1; i++) {

            temp = temp->next;

       }

       np->next = temp->next;
       temp->next = np;

       l->count++;


    }
}

void InsertEnd(EntryType item,List *l)
{
    if (IsListFull(l)) {

        printf("List is full");
        exit(1);

    } else {

       Node *np;
       np = (Node *)malloc(sizeof(Node));

       np->data = item;

       Node *temp;
       temp = l->head;

       while (temp->next) {

            temp = temp->next;

       }

       np->next = NULL;
       temp->next = np;

       l->count++;


    }
}

void Remove(EntryType *item,int position,List *l)
{
    if (IsListEmpty(l)) {

        printf("List is empty");
        exit(1);

    } else if (position < 0 || position > l->count) {

        printf("The position is out of index");
        exit(1);

    } else {

        Node *temp,*removeNode;

        temp = l->head;

        for (int i = 0; i < position - 1; i++) {

            temp = temp->next;

        }

        removeNode = temp->next;

        *item = removeNode->data;

        temp->next = removeNode->next;

        free(removeNode);

        l->count--;

    }
}

void RemoveEnd(EntryType *item,List *l)
{
    if (IsListEmpty(l)) {

        printf("List Empty");
        exit(1);

    } else {

        Node *temp,*removeNode;

        temp = l->head;

        while (temp->next->next) {

            temp = temp->next;

        }

        removeNode = temp->next;

        *item = removeNode->data;

        temp->next = NULL;

        free(removeNode);

        l->count--;

    }
}

void Replace(EntryType item,EntryType postion,List *l)
{
    if (IsListEmpty(l)) {

        printf("List is empty");
        exit(1);

    } else if (0 > postion || postion > l->count - 1){

        printf("The position is out of Index");
        exit(1);


    } else {

        Node *temp;

        for (int i = 0; i < postion; i++) {

            temp = temp->next;

        }

        temp->data = item;


    }
}

void Display(List *l)
{
    Node *np;
    np = l->head;

    while(np) {

        printf("%d \n",np->data);

        np = np->next;

    }

}

