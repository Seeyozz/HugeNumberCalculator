#ifndef  h_addition
#define  h_addition

#include "main.h"

struct List* addition(struct List* l1, struct List* l2, struct List* result);
struct List* addSameSize(struct List* l1, struct List* l2, int *carry);
void addCarryToRemaining(struct List* l1, struct List* cur, int* carry, struct List** result);

#endif