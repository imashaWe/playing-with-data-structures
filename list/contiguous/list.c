#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef int EntryType;

typedef struct list {
    int count;

    EntryType entry[MAX_SIZE];

} List;


void CreateList(List *l)
{
    l->count = 0;
}

bool IsListEmpty(List *l)
{
    return l->count == 0;
}

bool IsListFull(List *l)
{
    return l->count == MAX_SIZE;
}

int ListSize(List *l)
{
    return l->count;

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

        for (int i = l->count - 1; i >= position; i--) {

           l->entry[i + 1] = l->entry[i];

        }

        l->entry[position] = item;
        l->count++;

    }
}

void InsertEnd(EntryType item,List *l)
{
    if (IsListFull(l)) {

        printf("List is full");
        exit(1);

    } else {

        l->entry[l->count++] = item;

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

        *item = l->entry[position];

        for (int i = position; i < l->count - 1; i++) {

            l->entry[i] = l->entry[i + 1];

        }

        l->count--;
    }
}

void removeEnd(EntryType *item,List *l)
{
    if (IsListEmpty(l)) {

        printf("List Empty");
        exit(1);

    } else {

        *item = l->entry[l->count - 1];
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

        l->entry[postion] = item;

    }
}

void Display(List *l)
{
    for (int i = 0; i < l->count;i++) {

        printf("%d\n",l->entry[i]);

    }
}

