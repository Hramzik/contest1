

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
int array_copy      (Array* src, Array* dst);
int array_to_zero   (Array* array);
int array_dtor      (Array* array);


int merge_sort (Array* array, long long* inv);
int merge      (Array* array, size_t middle, long long* inv);



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


    long long ans = 0;
    merge_sort (a, &ans);


    printf ("%lld\n", ans);


    return 0 * dumb_compiler;
}



int merge_sort (Array* array, long long* inv) {

    if (!array) { return 1; }


    if (array->size <= 1) { return 0; }



    size_t middle = array->size / 2; //index


    Array Array1 = { array->elements,          middle };
    Array Array2 = { array->elements + middle, array->size - middle };


    merge_sort (&Array1, inv);
    merge_sort (&Array2, inv);


    merge (array, middle, inv);


    return 0;
}


int merge (Array* array, size_t middle, long long* inv) {

    if (!array) { return 1; }


    Array* temp = array_ctor (array->size);


    size_t i1          = 0;
    size_t i2          = middle;
    size_t write_index = 0;
    long long inverses = 0;

    while (i1 < middle && i2 < array->size) { //основная часть

        if (array->elements [i1] <= array->elements [i2]) {

            temp->elements [write_index] = array->elements [i1];
            write_index += 1;
            i1 += 1;
            continue;
        }

        inverses +=  middle - i1;
        temp->elements [write_index] = array->elements [i2];
        write_index += 1;
        i2 += 1;
        continue;
    }



    while (i1 < middle) { //выполнится только одно из двух прицеплений

        temp->elements [write_index] = array->elements [i1];
        write_index += 1;
        i1 += 1;
    }

    while (i2 < array->size) { //выполнится только одно из двух прицеплений

        temp->elements [write_index] = array->elements [i2];
        write_index += 1;
        i2 += 1;
    }


    array_copy (temp, array);


    *inv += inverses;


    return 0;
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





int array_dtor (Array* array) {

    if (!array) { return 1; }


    free (array->elements);
    free (array);


    return 0;
}

