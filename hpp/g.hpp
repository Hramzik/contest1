

#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>



typedef struct Segment {

    int l;
    int r;

} Segment; const size_t SEGMENT_SIZE = sizeof (Segment);


const size_t INT_SIZE = sizeof (int);


int mashup_work (void);

int merge_sort  (Segment* a, int n);
int merge       (Segment* a, int n, int middle);
int array_copy  (Segment* src, Segment* dst, int n);

int array_print (Segment* a, int len);





