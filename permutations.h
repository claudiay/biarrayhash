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

void shown(int array[], int size) {
    int i;
    for (i=0; size > i; i++)
        printf("%d, ", array[i]);

    printf("\n");
}


dict *perms(char *array[], int size) {
    dict *table;
    char *new_array[size];
    int size_of_table = 100;
    int n = size;
    int i, j, a, p;
    int indices[size];      //[0, 1, 2]
    int new_indices[size];  //tmp array for rearranging 
    int cycles[size];       //[3, 2, 1]
    register int tmp;

    // create cycles/indices
    for (i=0; size > i; i++)
        indices[i] = i;
    
    j=0;
    for (i=size; i > 0; i--) {
        cycles[j] = i;
        j++;
    }


    // Create hash table
    table = create_dict(size_of_table);
    
    // go through perms
    show(array, size);
    add_string(table, array, size);

    while (n > 0) {
up:
        for(i=size-1; i>-1; i--) {
           cycles[i] = cycles[i] - 1;
           if (cycles[i] == 0) {
               
               // indices[i:] = indices[i+1:] + indices[i:i+1]
               for (a=0; a < i; a++)
                   new_indices[a] = indices[a];
               p = a;
               for (a=i+1; a < size - 1; a++) {
                   new_indices[p] = indices[a];
                   p++;
               }
               new_indices[p] = indices[i];
               for (a=0; a < size; a++)
                   indices[a] = new_indices[a];

               cycles[i] = n - i;
           }
           else {
               j = cycles[i];
               
               tmp = indices[i];
               indices[i] = indices[size-j+1];
               indices[size-j+1] = tmp;

               //yield tuple(pool[i] for i in indices)
               for (a=0; a < size; a++) {
                   p = indices[a];
                   new_array[a] = array[p];
               }
               show(new_array, size);
               add_string(table, new_array, size);
               
               goto up;
           }
       }
    }

    return table;
}




