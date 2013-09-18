#include <stdio.h>
#include <stdlib.h>
#include "permutations.h"


int main() {
    dict *table;
    char *dog[] = {"dog", "stick", "ball", "cat", "mouse", "pickle", "carrot",
                    "mongoose", "mongoose", "mango", "baconcat", "pigs",
                    "kittens"};

    printf("Starting test...\n");
    table = perms(dog, 13);
    
    printf("Freeing table...\n");
    free_dict(table);
    printf("Testing done.\n");

    return 0;
}

