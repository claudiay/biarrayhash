#include <stdio.h>
#include <stdlib.h>
#include "bahash.h"

int main() {
    char cat[] = "cat\0";
    char dog[] = "dog,dog,ball\0";
    char r_dog[] = "ball,dog,dog\0";

    printf("Testing \"bahash.h\"...\n");

    printf("Creating table...\n");
    dict *my_table;
    int size_of_table = 10;
    my_table = create_dict(size_of_table);
    printf("Successfully created table!\n");

    printf("Checking add_string()...\n");
    add_string(my_table, dog);
    printf("Checking lookup_string()...\n");
    list *test_list;
    test_list = lookup_string(my_table, dog);
    if (strcmp(dog, test_list->string) != 0)
        printf("lookup_string failed!\n\t did not return string\n");
    if ((test_list = lookup_string(my_table, cat)) != NULL)
        printf("lookup_string() failed!\n\t did not return NULL\n");
    
    // test the reverse
    test_list = lookup_string(my_table, r_dog);
    if ((test_list = lookup_string(my_table, r_dog)) == NULL)
        printf("reverse lookup_string failed!\n\t did not return string\n");

    printf("Freeing up table...\n");
    free_dict(my_table);
    printf("Successfully freed table!\n");

    return 0;
}


