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

void permute(char *array[], int i, int n, int size, dict *table) {
    int j;
    
    if (i == n) {
        show(array, size);
        add_string(table, array, size);
    }
    
    else {
    
        for (j = i; j <= n; j++) {
            swap(&array[i], &array[j]);
            permute(array, i+1, n, size, table);
            swap(&array[i], &array[j]);
        }
    }
}

dict *perms(char *array[], int size) {
    dict *table;
    int size_of_table = 100;
    
    // Create hash table
    table = create_dict(size_of_table);
    
    // go through perms
    permute(array, 0, size-1, size, table);
     
    return table;
}

