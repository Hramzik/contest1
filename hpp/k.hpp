

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


enum Return_code {

    SUCCESS = 0,
    BAD_ARGS,
};


enum Qsort_partition {

    MIDDLE,
    RANDOM,
    MEDIAN_OF_3,
};


typedef struct Array {

    int* elements;
    size_t size;

} Array; const size_t ARRAY_SIZE = sizeof (Array);

typedef struct Sort_info {

    bool reversed;
    bool print;

    Qsort_partition partition;

} Sort_info; const size_t SORT_INFO_SIZE = sizeof (Sort_info);


const size_t INT_SIZE = sizeof (int);


Array*      array_ctor      (size_t size);
Array*      array_generate  (size_t size);
Array*      array_dup       (Array* array);
Return_code array_copy      (Array* src, Array* dst);
Return_code array_randomize (Array* array);
Return_code array_to_zero   (Array* array);
Return_code array_reverse   (Array* array);
Return_code array_print     (Array* array);
Return_code array_dtor      (Array* array);

Return_code swap_int (int* int1, int* int2);


Return_code quick_sort       (Array* array, Sort_info* info);
size_t      partition        (Array* array, int pivot);
int         pick_pivot       (Array* array, Sort_info* info);
int         pick_middle      (Array* array);
int         pick_random      (Array* array);
int         pick_median_of_3 (Array* array);

