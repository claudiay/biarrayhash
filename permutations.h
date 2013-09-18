#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bahash.h"


void show(char *array[], int size) {
    int i;
    for (i=0; size > i; i++)
        printf("%s, ", array[i]);

    printf("\n");
}

void swap (char **x, char **y) {
    char *tmp = *x;
    *x = *y;
    *y = tmp;
}

unsigned long perm_size(int size) {
    int permutations = 1;
    int x;

    for (x=1; x <= size; x++)
        permutations = permutations * x;

    printf("perm size: %d", permutations);
    return permutations;
}


dict *perms(char *array[], int size) {
    dict *table;
    int size_of_table = 100;
    int i;
    unsigned long count=0;
    unsigned long size_perm = perm_size(size);
    
    // Create hash table
    table = create_dict(size_of_table);
    
    // go through perms, only one way
    while (count < size_perm) {
        for(i=0; i < size-1; i++) {
            swap(&array[i], &array[i+1]);
            //add_string(table, array, size);
            //show(array, size);
            count++;
        }
        swap(&array[0], &array[1]);
        //add_string(table, array, size);
        //show(array, size);
        count++;
    }
     
    return table;
}

