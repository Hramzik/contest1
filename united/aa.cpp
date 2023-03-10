#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
//--------------------------------------------------

#include <malloc.h>
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


#define STACK_PUSH_RESIZE(x)  stack_resize (x, x->capacity * stack_resize_coefficient + 1)


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









//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------







int main (void) {


    Stack* stack = stack_ctor (1, INT_SIZE);


    stack_work (stack);


    return 0;
}


int stack_work (Stack* stack) {

    if (!stack) { return 1; }


    char cmd [6] = "";
    int arg = 0;
    int code = 0;
    int bastard_compiler = 69420;

    while (1) {

        bastard_compiler = scanf ("%s", cmd);

        if (!strcmp (cmd, "push")) {

            bastard_compiler = scanf ("%d", &arg);
            stack_push (stack, &arg);
            printf ("ok\n");
        }

        if (!strcmp (cmd, "pop")) {

            code = stack_pop (stack, &arg);
            if (code) { printf ("error\n"); }
            else      { printf ("%d\n", arg); }
        }

        if (!strcmp (cmd, "back")) {

            code = stack_top (stack, &arg);
            if (code) { printf ("error\n"); }
            else      { printf ("%d\n", arg); }
        }

        if (!strcmp (cmd, "size")) {

            printf ("%zd\n", stack->size);
        }

        if (!strcmp (cmd, "clear")) {

            stack_clear (stack);
            printf ("ok\n");
        }

        if (!strcmp (cmd, "exit")) {

            printf ("bye\n");
            return 0;
        }
    }


    return bastard_compiler; // never happens
}


Stack* stack_ctor (size_t size, size_t element_size) {

    Stack* stack = (Stack*) calloc (STACK_SIZE, 1);


    stack->elements = (void*) calloc (size * element_size, 1);
    stack->element_size = element_size;

    stack->size     = 0;
    stack->capacity = size;


    return stack;
}


Stack* stack_dtor (Stack* stack) {

    assert (stack);


    free (stack->elements);
    free (stack);


    return NULL;
}


int stack_clear (Stack* stack) {

    assert (stack);


    stack->size = 0;


    return 0;
}


int stack_resize (Stack* stack, size_t new_capacity) {

    assert (stack);


    stack->elements = (void*) realloc (stack->elements, sizeof (void*) * new_capacity);
    if (stack->elements == NULL && new_capacity != 0) { return 1; }


    stack->capacity = new_capacity;


    if (stack->size > new_capacity) { stack->size = new_capacity; }


    return 0;
}


int stack_push (Stack* stack, void* buffer) {

    assert (stack);
    assert (buffer);


    if (stack->size == stack->capacity) {

        int resize_code = 1;

        if (!stack->capacity) {

            resize_code = stack_resize (stack, 1);
        }
        else {

            resize_code = STACK_PUSH_RESIZE (stack);
        }

        if (resize_code) { return resize_code; }
    }


    stack->size += 1;
    memcpy ((char*) stack->elements + (stack->size - 1) * (stack->element_size), buffer, stack->element_size);


    return 0;
}


int stack_top (Stack* stack, void* buffer) {

    assert (stack);


    if (stack->size == 0) { return 1; }


    memcpy (buffer, (char*) stack->elements + (stack->size - 1) * (stack->element_size), stack->element_size);


    return 0;
}


int stack_pop (Stack* stack, void* buffer) {

    assert (stack);


    if (stack->size == 0) {

        return 1;
    }


    memcpy (buffer, (char*) stack->elements + (stack->size - 1) * (stack->element_size), stack->element_size);


    stack->size -= 1;


    return 0;
}


