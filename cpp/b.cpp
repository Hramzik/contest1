

#include "../hpp/b.hpp"


int main (void) {


    search_work ();


    return 0;
}


int search_work (void) {

    size_t n = 0; 
    scanf ("%zd", &n);


    int* a = (int*) calloc (n * INT_SIZE, 1);


    for (size_t i = 0; i < n; i++) {

        scanf ("%d", &a[i]);
    }


    size_t q = 0;
    scanf ("%zd", &q);
    bool* ans = (bool*) calloc (q * BOOL_SIZE, 1);


    int i1, i2, t = 0;


    for (size_t i = 0; i < q; i++) {

        scanf ("%d %d %d", &i1, &i2, &t);

        ans [i] = BinarySearch (&a[i1], &a[i2], t);
    }


    for (size_t i = 0; i < q; i++) {

        if (ans [i]) {

            printf ("YES\n");
            continue;
        }

        printf ("NO\n");
    }


    return 0;
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



    size_t len = end - begin;
    const int* mid = begin + (len / 2);


    if (target == *mid) {

        return true;
    }


    if (target < *mid) {

        return BinarySearch (begin, mid, target);
    }



    return BinarySearch (mid, end, target);
}

