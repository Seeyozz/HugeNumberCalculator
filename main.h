#ifndef  h_main
#define  h_main

#include <stdio.h>
#include <stdlib.h>
#include "addition.h"
#include "substraction.h"

typedef struct List
{
    struct List *next;
    int data;
}List;

void push(struct List** list, int new_data);
int getSize(struct List *list);
void fillList(char* n, struct List* list);
void printList(struct List* list);
void swapPointer(List** a, List** b);

#endif 