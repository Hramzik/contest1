

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

