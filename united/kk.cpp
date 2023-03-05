

#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>



typedef struct Array {

    int* elements;
    size_t size;

} Array; const size_t ARRAY_SIZE = sizeof (Array);



const size_t INT_SIZE = sizeof (int);


Array*      array_ctor      (size_t size);
Array*      array_dup       (Array* array);
int array_copy      (Array* src, Array* dst);
int array_to_zero   (Array* array);
int array_reverse   (Array* array);
int array_print     (Array* array);
int array_dtor      (Array* array);

int swap_int (int* int1, int* int2);


int quick_sort       (Array* array);
size_t      partition        (Array* array, int pivot);
int         pick_pivot       (Array* array);
int         pick_middle      (Array* array);



//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------











int main (void) {

    int n = 0;
    int dumb_compiler = 666;
    dumb_compiler = scanf ("%d", &n);

    Array* a = array_ctor (n);

    for (int i = 0; i < n; i++) {

        dumb_compiler = scanf ("%d", &a->elements [i]);
    }


    quick_sort (a);


    array_print (a);


    return 0 * dumb_compiler;
}


int quick_sort (Array* array) {

    if (!array) { return 1; }


    if (array->size <= 1) { return 0; }



    int pivot = pick_pivot (array); // value

    size_t middle_pos = partition (array, pivot);


    Array array1 = { array->elements,              middle_pos };
    Array array2 = { array->elements + middle_pos, array->size - middle_pos };


    quick_sort (&array1);
    quick_sort (&array2);


    return 0;
}


size_t partition (Array* array, int pivot) {

    if (!array) { return 0; }


    size_t left  = 0;
    size_t right = array->size - 1;

    while (true) {

       while (array->elements [left] < pivot && left < right) {

            left += 1;
       }

       while (array->elements [right] > pivot && left < right) {

            right -= 1;
       }

       if (left >  right) { return left; }
       if (left == right) { return (array->elements [left] >= pivot) ? (left):(left + 1); }; // в общем случае, этот элемент мы ни с чем не сравнивали,
                                                                                             // непонятно к какой половине он относится!


       swap_int (&array->elements [left], &array->elements [right]);

       left  += 1;
       right -= 1;
    }


    return 0;
}


int pick_pivot (Array* array) {

    if (!array) { return 0; }


    return pick_middle (array);


    return 0;
}


int pick_middle (Array* array) {

    if (!array) { return 0; }


    return array->elements [array->size / 2];
}




//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------









Array* array_ctor (size_t size) {

    Array* array = (Array*) calloc (ARRAY_SIZE, 1);
    assert (array);


    array->elements = (int*) calloc (size * INT_SIZE, 1);
    assert (array->elements);

    array->size = size;


    array_to_zero (array);


    return array;
}



Array* array_dup (Array* array) {

    if (!array) { return NULL; }


    Array* new_array = array_ctor (array->size);

    for (size_t i = 0; i < array->size; i++) {

        new_array->elements [i] = array->elements [i];
    }


    return new_array;
}


int array_copy (Array* src, Array* dst) {

    if (!src) { return 1; }
    if (!dst) { return 1; }


    if (dst->size != src->size || dst->elements == NULL) {

        free (dst->elements);
        dst->elements = (int*) calloc (src->size * INT_SIZE, 1);
        dst->size = src->size;
    }


    for (size_t i = 0; i < src->size; i++) {

        dst->elements [i] = src->elements [i];
    }


    return 0;
}


int array_to_zero (Array* array) {

    if (!array) { return 1; }


    for (size_t i = 0; i < array->size; i++) {

        array->elements [i] = 0;
    }


    return 0;
}


int array_reverse (Array* array) {

    if (!array) { return 1; }


    Array* temp = array_ctor (array->size);

    for (size_t i = 0; i < array->size; i++) {

        temp->elements [i] = array->elements [array->size - 1 - i];
    }


    array_copy (temp, array);
    array_dtor (temp);


    return 0;
}


int array_print (Array* array) {



    for (size_t i = 0; i < array->size; i++) {

        printf ("%d\n", array->elements [i]);
    }


    return 0;
}


int array_dtor (Array* array) {

    if (!array) { return 1; }


    free (array->elements);
    free (array);


    return 0;
}


int swap_int (int* int1, int* int2) {

    if (!int1) { return 1; }
    if (!int2) { return 1; }


    *int1 = *int1 ^ *int2; // int1 = XOR
    *int2 = *int1 ^ *int2; // int2 = int1
    *int1 = *int1 ^ *int2; // int1 = int2


    return 0;
}


