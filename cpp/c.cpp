

#include "../hpp/c.hpp"


int main (void) {


    lumos_work ();


    return 0;
}


int lumos_work (void) {

    int n = 0;
    int k = 0;
    scanf ("%d %d", &n, &k);


    int* a = (int*) calloc (n * INT_SIZE, 1);


    for (int i = 0; i < n; i++) {

        scanf ("%d", &a[i]);
    }


    merge_sort (a, n);

    for (int i = 0; i < n; i++) {

        printf ("%d ", a[i]);
    }
    printf ("\n");



    int lmin = 0;
    int lmax = a [n - 1] - a [0];


    int ans = lumos_find (n, a, k, lmin, lmax);


    printf ("%d\n", ans);


    return 0;
}


int lumos_find (int n, int* a, int k, int lmin, int lmax) {

    assert (a);


    if (lmin >= lmax) {

        return lmax;
    }



    int  lmid = (int) (((long long) lmin + (long long) lmax) / 2); //НА ЭТО ПЕРЕПОЛНЕНИЕ Я ПОТРАТИЛ 2 ЧАСА
    bool lmidtest = lumos_test (n, a, k, lmid);


    if (lmidtest) {

        return lumos_find (n, a, k, lmin, lmid);
    }


    return lumos_find (n, a, k, lmid + 1, lmax);
}


bool lumos_test (int n, int* a, int k, int l) {

    assert (a);


    int i = 0;

    while (i < n && k > 0) {

        k -= 1;
        int curmax = a [i] + l;

        while (i < n && a [i] <= curmax) {

            i += 1;
        }
    }

    if (i == n) { printf ("good = %d\n", l); return true; }


    printf ("bad = %d\n", l);
    return false;
}


int merge_sort (int* a, int n) {

    assert (a);


    if (n <= 1) { return 0; }



    int middle = n / 2; //index


    merge_sort (a, middle);
    merge_sort (a + middle, n - middle);


    merge (a, n, middle);


    return 0;
}


int merge (int* a, int n, int middle) {

    assert (a);


    int* temp = (int*) calloc (n * INT_SIZE, 1);


    int i1          = 0;
    int i2          = middle;
    int write_index = 0;

    while (i1 < middle && i2 < n) { //основная часть

        if (a [i1] <= a [i2]) {

            temp [write_index] = a [i1];
            write_index += 1;
            i1 += 1;
            continue;
        }

        temp [write_index] = a [i2];
        write_index += 1;
        i2 += 1;
        continue;
    }



    while (i1 < middle) { //выполнится только одно из двух прицеплений

        temp [write_index] = a [i1];
        write_index += 1;
        i1 += 1;
    }

    while (i2 < n) { //выполнится только одно из двух прицеплений

        temp [write_index] = a [i2];
        write_index += 1;
        i2 += 1;
    }


    array_copy (temp, a, n);


    free (temp);


    return 0;
}


int array_copy (int* src, int* dst, int n) {

    assert (src);
    assert (dst);


    for (int i = 0; i < n; i++) {

        dst [i] = src [i];
    }


    return 0;
}

