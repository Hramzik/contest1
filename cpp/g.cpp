

#include "../hpp/g.hpp"


int main (void) {


    mashup_work ();


    return 0;
}


int mashup_work (void) {

    int bastard_compiler = 69420;
    int n = 0;
    bastard_compiler = scanf ("%d", &n);


    Segment* a   = (Segment*) calloc (n * SEGMENT_SIZE, 1);
    Segment* ans = (Segment*) calloc (n * SEGMENT_SIZE, 1);
    for (int i = 0; i < n; i++) {

        bastard_compiler = scanf ("%d %d", &a[i].l, &a[i].r);
    }


    merge_sort (a, n);


    int cur_l = a [0].l;
    int cur_r = a [0].r;
    int i = 1;
    int ans_len = 0;
    while (i < n) {

        if (a[i].l <= cur_r) {

            if (a[i].r > cur_r) {

                cur_r = a[i].r;
            }

            i += 1;
            continue;
        }

        ans [ans_len].l = cur_l;
        ans [ans_len].r = cur_r;
        ans_len += 1;

        cur_l = a[i].l;
        cur_r = a[i].r;
        i += 1;
    }


    ans [ans_len].l = cur_l; ans [ans_len].r = cur_r; ans_len += 1;


    printf ("%d\n", ans_len);
    array_print (ans, ans_len);


    return bastard_compiler; // never happens
}


int merge_sort (Segment* a, int n) {

    assert (a);


    if (n <= 1) { return 0; }



    int middle = n / 2; //index


    merge_sort (a, middle);
    merge_sort (a + middle, n - middle);


    merge (a, n, middle);


    return 0;
}


int merge (Segment* a, int n, int middle) {

    assert (a);


    Segment* temp = (Segment*) calloc (n * SEGMENT_SIZE, 1);


    int i1          = 0;
    int i2          = middle;
    int write_index = 0;

    while (i1 < middle && i2 < n) { //основная часть

        if (a [i1].l <= a [i2].l) {

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


int array_copy (Segment* src, Segment* dst, int n) {

    assert (src);
    assert (dst);


    for (int i = 0; i < n; i++) {

        dst [i] = src [i];
    }


    return 0;
}


int array_print (Segment* a, int len) {

    assert (a);


    for (int i = 0; i < len; i++) {

        printf ("%d %d\n", a[i].l, a[i].r);
    }


    return 0;
}