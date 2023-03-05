

#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>




#define STACK_PUSH_RESIZE(x)  stack_resize (x, x->capacity * 2 + 1)


typedef struct Node {

    int value;
    int min;

} Node; const size_t NODE_SIZE = sizeof (Node);


typedef struct Stack {

    Node*  elements;

    size_t size;
    size_t capacity;

} Stack; const size_t STACK_SIZE = sizeof (Stack);


typedef struct Queue {

    Stack* in;
    Stack* out;

    size_t size;

} Queue; const size_t QUEUE_SIZE = sizeof (Queue);


const size_t INT_SIZE = sizeof (int);


int queue_work (Queue* q);

Stack*  stack_ctor   (size_t capacity);
Stack*  stack_dtor   (Stack* stack);
int     stack_clear  (Stack* stack);
int     stack_resize (Stack* stack, size_t new_capacity);
int     stack_push   (Stack* stack, int value);
int     stack_top    (Stack* stack, int* buffer);
int     stack_pop    (Stack* stack, int* buffer);
int     stack_min    (Stack* stack, int* buffer);

Queue* queue_ctor  (size_t capacity);
int    queue_dtor  (Queue* q);
int    queue_clear (Queue* q);
int    queue_shift (Queue* q);
int    queue_push  (Queue* q, int value);
int    queue_top   (Queue* q, int* buffer);
int    queue_pop   (Queue* q, int* buffer);
int    queue_min   (Queue* q, int* buffer);



//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------








int main (void) {


    Queue* queue = queue_ctor (1);


    queue_work (queue);


    return 0;
}


int queue_work (Queue* q) {

    if (!q) { return 1; }


    int bastard_compiler = 69420;
    int m = 0;
    bastard_compiler = scanf ("%d", &m); // количество команд


    char cmd [8] = "";
    int  arg     = 0;
    int  code    = 0;

    while (m > 0) {

        bastard_compiler = scanf ("%s", cmd);

        if (!strcmp (cmd, "enqueue")) {

            bastard_compiler = scanf ("%d", &arg);
            queue_push (q, arg);
            printf ("ok\n");
        }

        if (!strcmp (cmd, "dequeue")) {

            code = queue_pop (q, &arg);
            if (code) { printf ("error\n"); }
            else      { printf ("%d\n", arg); }
        }

        if (!strcmp (cmd, "front")) {

            code = queue_top (q, &arg);
            if (code) { printf ("error\n"); }
            else      { printf ("%d\n", arg); }
        }

        if (!strcmp (cmd, "size")) {

            printf ("%zd\n", q->size);
        }

        if (!strcmp (cmd, "clear")) {

            queue_clear (q);
            printf ("ok\n");
        }

        if (!strcmp (cmd, "min")) {

            code = queue_min (q, &arg);
            if (code) { printf ("error\n"); }
            else      { printf ("%d\n", arg); }
        }


        m -= 1;
    }


    return bastard_compiler; // never happens
}
































Stack* stack_ctor (size_t capacity) {

    Stack* stack = (Stack*) calloc (STACK_SIZE, 1);


    stack->elements = (Node*) calloc (capacity * NODE_SIZE, 1);

    stack->size     = 0;
    stack->capacity = capacity;


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


    stack->elements = (Node*) realloc (stack->elements, NODE_SIZE * new_capacity);
    if (stack->elements == NULL && new_capacity != 0) { return 1; }


    stack->capacity = new_capacity;


    if (stack->size > new_capacity) { stack->size = new_capacity; }


    return 0;
}


int stack_push (Stack* stack, int value) {

    assert (stack);


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


    int new_min = 0;

    if (stack->size) {

        new_min = (value < stack->elements [stack->size - 1].min) ? (value):(stack->elements [stack->size - 1].min);
    }

    else {

        new_min = value;
    }

    stack->size += 1;


    stack->elements [stack->size - 1].value = value;
    stack->elements [stack->size - 1].min = new_min;


    return 0;
}


int stack_top (Stack* stack, int* buffer) {

    assert (stack);


    if (stack->size == 0) { return 1; }


    *buffer = stack->elements [stack->size - 1].value;


    return 0;
}


int stack_pop (Stack* stack, int* buffer) {

    assert (stack);


    if (stack->size == 0) {

        return 1;
    }


    if (buffer) {

        *buffer = stack->elements [stack->size - 1].value;
    }


    stack->size -= 1;


    return 0;
}


int stack_min (Stack* stack, int* buffer) {

    assert (stack);


    if (!stack->size) { return 1; }


    *buffer = stack->elements [stack->size - 1].min;


    return 0;
}


//--------------------------------------------------


Queue* queue_ctor (size_t capacity) {

    Queue* q = (Queue*) calloc (QUEUE_SIZE, 1);

    q->in  = stack_ctor (capacity);
    q->out = stack_ctor (capacity);

    q->size = 0;


    return q;
}


int queue_dtor (Queue* q) {

    stack_dtor (q->in);
    stack_dtor (q->out);

    free (q);


    return 0;
}


int queue_clear (Queue* q) {

    stack_clear (q->in);
    stack_clear (q->out);

    q->size = 0;


    return 0;
}


int queue_shift (Queue* q) {

    assert (q->out->size == 0);


    int temp = 0;
    size_t size_in = q->in->size;

    for (size_t i = 0; i < size_in; i++) {

        stack_pop  (q->in, &temp);
        stack_push (q->out, temp);
    }


    return 0;
}


int queue_push (Queue* q, int value) {

    assert (q);


    stack_push (q->in, value);


    q->size += 1;


    return 0;
}


int queue_top (Queue* q, int* buffer) {

    assert (q);


    if (!q->size) { return 1; }


    if (!q->out->size) { queue_shift (q); }


    stack_top (q->out, buffer);


    return 0;
}


int queue_pop (Queue* q, int* buffer) {

    assert (q);


    if (!q->size) { return 1; }


    if (!q->out->size) { queue_shift (q); }


    stack_pop (q->out, buffer);


    q->size -= 1;


    return 0;
}


int queue_min (Queue* q, int* buffer) {

    assert (q);


    if (!q->size) { return 1; }


    if (q->in->size && q->out->size) {

        int min_in  = 0;
        int min_out = 0;

        stack_min (q->in,  &min_in);
        stack_min (q->out, &min_out);


        *buffer = (min_in < min_out) ? (min_in):(min_out);


        return 0;
    }


    if (q->in->size) {

        int min_in  = 0;

        stack_min (q->in,  &min_in);


        *buffer = min_in;


        return 0;
    }


    int min_out  = 0;

    stack_min (q->out, &min_out);


    *buffer = min_out;


    return 0;
}


