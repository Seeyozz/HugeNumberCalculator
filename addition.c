#include "addition.h"

struct List* addSameSize(struct List* l1, struct List* l2, int *carry) 
{
    if (l1 == NULL) 
        return NULL; 
  
    int sum; 

    List* result = (List *)malloc(sizeof(List)); 
  
    result->next = addSameSize(l1->next, l2->next, carry); 
  
    sum = l1->data + l2->data + *carry; 
    *carry = sum / 10; 
    sum = sum % 10; 

    result->data = sum; 
  
    return result; 
} 

void addCarryToRemaining(struct List* l1, struct List* cur, int* carry, struct List** result) 
{ 
    int sum; 
  
    if (l1 != cur) 
    { 
        addCarryToRemaining(l1->next, cur, carry, result); 
  
        sum = l1->data + *carry; 
        *carry = sum/10; 
        sum %= 10; 
  
        push(result, sum); 
    } 
} 

struct List* addition(struct List* l1, struct List* l2, struct List* result)
{
    if (!l1)
    {
        result = l2;
        return result;
    }

    else if (!l2)
    {
        result = l1;
        return result;
    }

    int size1 = getSize(l1);
    int size2 = getSize(l2);

    int carry = 0;

    if (size1 == size2)
    {
        result = addSameSize(l1, l2, &carry);
    }

    else
    {
        int diff = abs(size1 - size2); 

        if (size1 < size2) 
            swapPointer(&l1, &l2); 

        struct List *cur = l1;

        while (diff)
        {
            cur = cur->next;
            diff--;
        }

        result = addSameSize(cur, l2, &carry); 
        addCarryToRemaining(l1, cur, &carry, &result); 
    }
    

    if (carry)
        push(&result, carry);

    return result;
    
}