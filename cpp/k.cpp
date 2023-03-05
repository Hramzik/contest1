

#include "../hpp/k.hpp"


int main (void) {

    int n = 0;
    int dumb_compiler = 666;
    dumb_compiler = scanf ("%d", &n);

    Array* a = array_ctor (n);

    for (int i = 0; i < n; i++) {

        dumb_compiler = scanf ("%d", &a->elements [i]);
    }


    Sort_info info = {}; info.print = false; info.reversed = false; info.partition = MIDDLE;
    quick_sort (a, &info);


    array_print (a);


    return 0 * dumb_compiler;
}


Return_code quick_sort (Array* array, Sort_info* info) {

    if (!array) { return BAD_ARGS; }


    if (array->size <= 1) { return SUCCESS; }



    int pivot = pick_pivot (array, info); // value

    size_t middle_pos = partition (array, pivot);


    Array array1 = { array->elements,              middle_pos };
    Array array2 = { array->elements + middle_pos, array->size - middle_pos };

    Sort_info new_info = { info->reversed, false, info->partition };


    quick_sort (&array1, &new_info);
    quick_sort (&array2, &new_info);


    if (info->print) { array_print (array); }


    return SUCCESS;
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


int pick_pivot (Array* array, Sort_info* info) {

    if (!array) { return 0; }


    switch (info->partition) {

        case MIDDLE:      return pick_middle (array);
        case RANDOM:      return pick_random (array);
        case MEDIAN_OF_3: return pick_median_of_3 (array);

        default: return 0;
    }


    return 0;
}


int pick_middle (Array* array) {

    if (!array) { return 0; }


    return array->elements [array->size / 2];
}


int pick_random (Array* array) {

    if (!array) { return 0; }


    return array->elements [rand () % array->size];
}


int pick_median_of_3 (Array* array) {

    if (!array) { return 0; }


    size_t i1 = 0;
    size_t i2 = array->size / 2;
    size_t i3 = array->size - 1;

    int v1 = array->elements [i1];
    int v2 = array->elements [i2];
    int v3 = array->elements [i3];


    int ans = 0;

    if      ((v1 <= v2 && v2 <= v3) || (v3 <= v2 && v2 <= v1)) { ans = v2; }
    else if ((v2 <= v1 && v1 <= v3) || (v3 <= v1 && v1 <= v2)) { ans = v1; }
    else                                                       { ans = v3; }


    return ans;
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


Array* array_generate (size_t size) {

    Array* array = array_ctor (size);


    array_randomize (array);


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


Return_code array_copy (Array* src, Array* dst) {

    if (!src) { return BAD_ARGS; }
    if (!dst) { return BAD_ARGS; }


    if (dst->size != src->size || dst->elements == NULL) {

        free (dst->elements);
        dst->elements = (int*) calloc (src->size * INT_SIZE, 1);
        dst->size = src->size;
    }


    for (size_t i = 0; i < src->size; i++) {

        dst->elements [i] = src->elements [i];
    }


    return SUCCESS;
}


Return_code array_randomize (Array* array) {

    if (!array) { return BAD_ARGS; }


    srand ((unsigned int) time (NULL));

    for (size_t i = 0; i < array->size; i++) {

        if (rand () % 2) {

            array->elements [i] = rand ();
            continue;
        }

        array->elements [i] = -1 * rand ();
    }


    return SUCCESS;
}


Return_code array_to_zero (Array* array) {

    if (!array) { return BAD_ARGS; }


    for (size_t i = 0; i < array->size; i++) {

        array->elements [i] = 0;
    }


    return SUCCESS;
}


Return_code array_reverse (Array* array) {

    if (!array) { return BAD_ARGS; }


    Array* temp = array_ctor (array->size);

    for (size_t i = 0; i < array->size; i++) {

        temp->elements [i] = array->elements [array->size - 1 - i];
    }


    array_copy (temp, array);
    array_dtor (temp);


    return SUCCESS;
}


Return_code array_print (Array* array) {



    for (size_t i = 0; i < array->size; i++) {

        printf ("%d\n", array->elements [i]);
    }


    return SUCCESS;
}


Return_code array_dtor (Array* array) {

    if (!array) { return BAD_ARGS; }


    free (array->elements);
    free (array);


    return SUCCESS;
}


Return_code swap_int (int* int1, int* int2) {

    if (!int1) { return BAD_ARGS; }
    if (!int2) { return BAD_ARGS; }


    *int1 = *int1 xor *int2; // int1 = XOR
    *int2 = *int1 xor *int2; // int2 = int1
    *int1 = *int1 xor *int2; // int1 = int2


    return SUCCESS;
}


