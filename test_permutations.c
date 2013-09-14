#include <stdio.h>
#include <stdlib.h>
#include "permutations.h"


int main() {
    dict *table;
    char *dog[] = {"dog", "dog", "ball"};

    
    table = perms(dog, 3);
    
    printf("Freeing table...\n");
    free_dict(table);
    printf("Testing done.\n");

    return 0;
}

