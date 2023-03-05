

#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


typedef struct Array {

    long long* elements;
    int size;

} Array; const size_t ARRAY_SIZE = sizeof (Array);


const size_t LL_SIZE = sizeof (long long);


Array* array_ctor    (int size);
int    array_print   (Array* array);
int    array_copy    (Array* src, Array* dst);
int    array_to_zero (Array* array);
int    array_dtor    (Array* array);


int    lsd_sort               (Array* array);
size_t lsd_split              (Array* array);
int    lsd_sort_by_all_digits (Array* array);
int    lsd_sort_by_nth_digit  (Array* array, size_t n);
int    lsd_fill_numbers       (Array* array, size_t n, size_t* prefix_sums);
size_t get_max_digit_num      (Array* array);
size_t digit                  (long long n, size_t k);
size_t get_digit_num          (long long n);

