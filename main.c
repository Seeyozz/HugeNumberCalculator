#include "main.h"

int main(int argc, char *argv[]) 
{
    //gcc -Wall -Wextra -Werror -std=c99 -O1 -o main *.c
    
    (void) argc;
    
    char* number = argv[1];
    List *list = (List *)malloc(sizeof(List));
    fillList(number, list);
    printList(list);
    printf("\n");

    char* number2 = argv[2];
    List *list2 = (List *)malloc(sizeof(List));
    fillList(number2, list2);
    printList(list2);
    printf("\n");

    List *result = (List *)malloc(sizeof(List));

    printList(addition(list, list2, result));
}

void push(struct List** list, int new_data) 
{ 
    struct List* new_List = (struct List*) malloc(sizeof(struct List)); 
  
    new_List->data  = new_data; 
  
    new_List->next = (*list); 
  
    (*list) = new_List; 
} 

int getSize(struct List *list) 
{ 
    int size = 0; 
    while (list != NULL) 
    { 
        list = list->next; 
        size++; 
    } 
    return size; 
} 

void swapPointer(List** a, List** b) 
{ 
    List* t = *a; 
    *a = *b; 
    *b = t; 
} 

void fillList(char* n, struct List* list)
{
    for (int i = 0; n[i] != 0; i++)
    {
        list->data = n[i] - '0';

        if (n[i+1] != 0)
        {
            list->next = malloc(sizeof(List));
            list = list->next;
        }
    }
}

void printList(struct List* list)
{
    while (list != NULL)
    {
        printf("%d\n", list->data);
        list = list->next;
    }
}