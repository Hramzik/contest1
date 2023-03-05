

#include <stdbool.h>
#include <locale.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


const int INT_SIZE  = sizeof (int);
const int BOOL_SIZE = sizeof (bool);


int  search_work  (void);
bool BinarySearch (const int* begin, const int* end, int target);



//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------



int main (void) {


    search_work ();


    return 0;
}


int search_work (void) {

    int bastard_compiler = 666;


    int n = 0;
    bastard_compiler = scanf ("%d", &n);


    int* a = (int*) calloc (n * INT_SIZE, 1);


    for (int i = 0; i < n; i++) {

        bastard_compiler = scanf ("%d", &a[i]);
    }


    int q = 0;
    bastard_compiler = scanf ("%d", &q);
    bool* ans = (bool*) calloc (q * BOOL_SIZE, 1);


    int i1, i2, t = 0;


    for (int i = 0; i < q; i++) {

        bastard_compiler = scanf ("%d %d %d", &i1, &i2, &t);

        ans [i] = BinarySearch (&a[i1], &a[i2], t);
    }


    for (int i = 0; i < q; i++) {

        if (ans [i]) {

            printf ("YES\n");
            continue;
        }

        printf ("NO\n");
    }


    return bastard_compiler;
}


bool BinarySearch (const int* begin, const int* end, int target) {

    assert (begin);
    assert (end);


    if (begin + 1 == end) {

        if (*begin == target) {

            return true;
        }

        return false;
    }



    int len = end - begin;
    const int* mid = begin + (len / 2);


    if (target == *mid) {

        return true;
    }


    if (target < *mid) {

        return BinarySearch (begin, mid, target);
    }



    return BinarySearch (mid, end, target);
}

