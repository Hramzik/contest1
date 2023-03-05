

#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>




#define STACK_PUSH_RESIZE(x)  stack_resize (x, x->capacity * 2 + 1)



typedef struct Stack {

    char*  elements;

    size_t size;
    size_t capacity;

} Stack; const size_t STACK_SIZE = sizeof (Stack);



const size_t CHAR_SIZE = sizeof (char);


int hyppo_work (Stack* stack);

Stack*  stack_ctor   (size_t capacity);
Stack*  stack_dtor   (Stack* stack);
int     stack_clear  (Stack* stack);
int     stack_resize (Stack* stack, size_t new_capacity);
int     stack_push   (Stack* stack, char  value);
int     stack_top    (Stack* stack, char* buffer);
int     stack_pop    (Stack* stack, char* buffer);



