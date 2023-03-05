

#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>




const size_t INT_SIZE = sizeof (int);


int nimbus_work (void);
int preprocess  (int* a, int n, int* minleft, int* minright);
int speed       (int l, int r, int* minleft, int* minright);





//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------












int main (void) {


    nimbus_work ();


    return 0;
}


int nimbus_work (void) {

    int bastard_compiler = 69420;
    int n = 0;
    bastard_compiler = scanf ("%d", &n);


    int* a        = (int*) calloc (n * INT_SIZE, 1);
    int* minleft  = (int*) calloc (n * INT_SIZE, 1);
    int* minright = (int*) calloc (n * INT_SIZE, 1);
    for (int i = 0; i < n; i++) {

        bastard_compiler = scanf ("%d", &a[i]);
    }


//--------------------------------------------------
    preprocess (a, n, minleft, minright);
//--------------------------------------------------


    int l, r = 0;
    int q = 0;
    int ans  = 0;
    bastard_compiler = scanf ("%d", &q);


    for (int i = 0; i < q; i++) {

        bastard_compiler = scanf ("%d %d", &l, &r);

        ans = speed (l, r, minleft, minright);

        printf ("%d\n", ans);
    }


    return bastard_compiler; // never happens
}


int preprocess (int* a, int n, int* minleft, int* minright) {

    assert (a);
    assert (minleft);
    assert (minright);


    minleft [0] = a [0];
    for (int i = 1; i < n; i++) {

        if (a [i] < minleft [i - 1]) {

            minleft [i] = a[i];
            continue;
        }

        minleft [i] = minleft [i - 1];
    }


    minright [n - 1] = a [n - 1];
    for (int i = n - 2;/*i >= 0*/; i--) {

        if (a [i] < minright [i + 1]) { minright [i] = a[i]; }
        else                          { minright [i] = minright [i + 1]; }

        if (i == 0) break;
    }


    return 0;
}


int speed (int l, int r, int* minleft, int* minright) {

    assert (minleft);
    assert (minright);


    int speed1 = minleft  [l - 1]; // printf ("speed1 = %d\n", speed1);
    int speed2 = minright [r - 1]; // printf ("speed2 = %d\n", speed2);


    int ans = (speed1 < speed2) ? (speed1):(speed2);


    return ans;
}


