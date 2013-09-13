#include <stdio.h>
#include <stdlib.h>
#include "bahash.h"


int main() {
    char *cat[] = {"cat", "mouse"};
    char *dog[] = {"dog", "dog", "ball"};
    char *r_dog[] = {"ball", "dog", "dog"};

    printf("Testing \"bahash.h\"...\n");

    printf("Creating table...\n");
    dict *my_table;
    int size_of_table = 100;
    my_table = create_dict(size_of_table);
    printf("Successfully created table!\n");

    printf("Checking add_string()...\n");
    add_string(my_table, dog, 3);
    add_string(my_table, r_dog, 3);
    add_string(my_table, cat, 2);
    
    printf("Freeing up table...\n");
    free_dict(my_table);
    printf("Successfully freed table!\n");

    return 0;
}


