

#include <stdbool.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


const size_t INT_SIZE  = sizeof (int);
const size_t BOOL_SIZE = sizeof (bool);


int  lumos_work (void);
int  lumos_find (int n, int* a, int k, int lmin, int lmax);
bool lumos_test (int n, int* a, int k, int l);
int  merge_sort (int* a, int n);
int  merge      (int* a, int n, int middle);
int  array_copy (int* src, int* dst, int n);



