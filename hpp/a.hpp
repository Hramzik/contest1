#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
//--------------------------------------------------


#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


//-------------------- SETTINGS --------------------

const double stack_resize_coefficient = 2;

//--------------------------------------------------


#define STACK_POP_RESIZE(x)   stack_resize (x, (size_t) fmin ( ceil ( (double) x->capacity / stack_resize_coefficient), x->capacity - 1) )
#define STACK_PUSH_RESIZE(x)  stack_resize (x, (size_t) fmax ( ceil ( (double) x->capacity * stack_resize_coefficient), x->capacity + 1) )


typedef struct Stack {

    void*  elements;
    size_t element_size;

    size_t size;
    size_t capacity;

} Stack; const size_t STACK_SIZE = sizeof (Stack);


const size_t INT_SIZE = sizeof (int);


Stack*  stack_ctor   (size_t size, size_t element_size);
Stack*  stack_dtor   (Stack* stack);
int     stack_clear  (Stack* stack);
int     stack_resize (Stack* stack, size_t new_capacity);
int     stack_push   (Stack* stack, void* buffer);
int     stack_top    (Stack* stack, void* buffer);
int     stack_pop    (Stack* stack, void* buffer);

int stack_work (Stack* stack);


//--------------------------------------------------
#endif