#include <stdlib.h>
#include <string.h>
#include "bahash.h"


void show(char *array[], int size) {
    int i;
    for (i=0; size < i; i++) {
        printf("%s, ", array[i]);
    }
    printf("\n");
}


dict *perms(char *array[], int size) {
    dict *table;
    int size_of_table = 100;
    int i = size;

    // Create hash table
    table = create_dict(size_of_table);
    

    //add perm to dict
    //add_string(table, array, size);

    return table;
}




