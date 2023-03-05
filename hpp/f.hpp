

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
int preprocess  (int* a, size_t n, int* minleft, int* minright);
int speed       (int l, int r, int* minleft, int* minright);





