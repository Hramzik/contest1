

#include "../hpp/i.hpp"


int main (void) {

    int n = 0;
    int dumb_compiler = 666;
    dumb_compiler = scanf ("%d", &n);

    Array* a = array_ctor (n);

    for (int i = 0; i < n; i++) {

        dumb_compiler = scanf ("%lld", &a->elements [i]);
    }


    lsd_sort (a);


    array_print (a);


    array_dtor (a);


    return 0 * dumb_compiler;
}


int lsd_sort (Array* array) {

    if (!array) { return 1; }


    if (array->size <= 1) { return 0; }


    lsd_sort_by_all_digits (array);


    return 0;
}



int lsd_sort_by_all_digits (Array* array) {

    if (!array) { return 1; }


    size_t max_digit_num = get_max_digit_num (array);

    for (size_t i = 1; i <= max_digit_num; i++) {

        lsd_sort_by_nth_digit (array, i);
    }


    return 0;
}


int lsd_sort_by_nth_digit (Array* array, size_t n) {

    if (!array) { return 1; }


    size_t amount_of_digits [256] = {}; //a[i] = у скольки чисел есть цифра i
    for (size_t i = 0; i < 256; i++) { amount_of_digits [i] = 0; }


    for (int i = 0; i < array->size; i++) {

        size_t current_digit = digit (array->elements [i], n);
        amount_of_digits [current_digit] += 1;
    }


    size_t total = 0;

    for (size_t i = 0; i < 256; i++) { //заменяем на префиксные суммы; a[i] = у скольки чисел цифры меньше i 

        size_t temp = amount_of_digits [i];
        amount_of_digits [i] = total;
        total += temp;
    }


    lsd_fill_numbers (array, n, amount_of_digits);


    return 0;
}


int lsd_fill_numbers (Array* array, size_t n, size_t* prefix_sums) {

    if (!array)       { return 1; }
    if (!prefix_sums) { return 1; }


    Array* temp_array = array_ctor (array->size); //буфер

    for (int i = 0; i < array->size; i++) {

        size_t current_digit = digit (array->elements [i], n);
        temp_array->elements [prefix_sums [current_digit]] = array->elements [i];

        prefix_sums [current_digit] += 1; //записанная цифра типо меньше следующих, чтобы мы дальше писали норм
    }


    array_copy (temp_array, array);
    array_dtor (temp_array);


    return 0;
}


size_t digit (long long n, size_t k) {

    if (k == 1) {

        long long ans = n % 256;
        if (ans < 0) { ans = - ans; }

        return ans;
    }

    return digit (n / 256, k - 1);
}


size_t get_max_digit_num (Array* array) {

    if (!array) { return 1; }


    size_t max_digit_num = 0;

    for (int i = 0; i < array->size; i++) {

        size_t current_digit_num = get_digit_num (array->elements [i]);

        if (current_digit_num > max_digit_num) {
        
            max_digit_num = current_digit_num;
        }
    }


    return max_digit_num;
}


size_t get_digit_num (long long n) {

    if (n == 0) { return 1; } // вырожденный случай


    size_t k = 0;

    while (n != 0) {

        n /= 256;
        k += 1;
    }


    return k;
}




//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------






Array* array_ctor (int size) {

    Array* array = (Array*) calloc (ARRAY_SIZE, 1);
    assert (array);


    array->elements = (long long*) calloc (size * LL_SIZE, 1);
    assert (array->elements);

    array->size = size;


    array_to_zero (array);


    return array;
}


int array_print (Array* array) {



    for (int i = 0; i < array->size; i++) {

        printf ("%lld\n", array->elements [i]);
    }


    return 0;
}


int array_copy (Array* src, Array* dst) {

    if (!src) { return 1; }
    if (!dst) { return 1; }


    if (dst->size != src->size || dst->elements == NULL) {

        free (dst->elements);
        dst->elements = (long long*) calloc (src->size * LL_SIZE, 1);
        dst->size = src->size;
    }


    for (int i = 0; i < src->size; i++) {

        dst->elements [i] = src->elements [i];
    }


    return 0;
}


int array_to_zero (Array* array) {

    if (!array) { return 1; }


    for (int i = 0; i < array->size; i++) {

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

