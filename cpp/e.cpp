

#include "../hpp/e.hpp"


int main (void) {


    Stack* stack = stack_ctor (1);


    hyppo_work (stack);


    return 0;
}


int hyppo_work (Stack* stack) {

    if (!stack) { return 1; }


    int bastard_compiler = 69420;
    char c    = 0;
    char prev = 0;
    int  code = 0;
    bool pizdez_flag = false;


    while (c != '\n' && !pizdez_flag) {

        bastard_compiler = scanf ("%c", &c);

        switch (c) {

            case '(': stack_push (stack, '('); break;
            case '{': stack_push (stack, '{'); break;
            case '[': stack_push (stack, '['); break;

            case ')': {

                code = stack_pop (stack, &prev);
                if (code) { pizdez_flag = true; break; }

                if (prev != '(') { pizdez_flag = true; break; }

                break;
            }

            case '}': {

                code = stack_pop (stack, &prev);
                if (code) { pizdez_flag = true; break; }

                if (prev != '{') { pizdez_flag = true; break; }

                break;
            }

            case ']': {

                code = stack_pop (stack, &prev);
                if (code) { pizdez_flag = true; break; }

                if (prev != '[') { pizdez_flag = true; break; }

                break;
            }

            default: break;
        }
    }


    if (stack->size) { pizdez_flag = true; }


    if (pizdez_flag) printf ("NO");
    else             printf ("YES");


    return bastard_compiler; // never happens
}































Stack* stack_ctor (size_t capacity) {

    Stack* stack = (Stack*) calloc (STACK_SIZE, 1);


    stack->elements = (char*) calloc (capacity * CHAR_SIZE, 1);

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


    stack->elements = (char*) realloc (stack->elements, CHAR_SIZE * new_capacity);
    if (stack->elements == NULL && new_capacity != 0) { return 1; }


    stack->capacity = new_capacity;


    if (stack->size > new_capacity) { stack->size = new_capacity; }


    return 0;
}


int stack_push (Stack* stack, char value) {

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


    stack->size += 1;


    stack->elements [stack->size - 1] = value;


    return 0;
}


int stack_top (Stack* stack, char* buffer) {

    assert (stack);


    if (stack->size == 0) { return 1; }


    *buffer = stack->elements [stack->size - 1];


    return 0;
}


int stack_pop (Stack* stack, char* buffer) {

    assert (stack);


    if (stack->size == 0) {

        return 1;
    }


    if (buffer) {

        *buffer = stack->elements [stack->size - 1];
    }


    stack->size -= 1;


    return 0;
}



//--------------------------------------------------

