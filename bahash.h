#include <stdlib.h>
#include <string.h>


typedef struct list {
    char *string;
    struct list *next;
} list;

typedef struct dict {
    int size;       // size of the hash table
    list **table;   // table elements
} dict;

dict *create_dict(int size) {
    dict *new_table;
    int i;
    
    if(size<1) return NULL; // invalid size for table

    if ((new_table = malloc(sizeof(dict))) == NULL) return NULL;
    if ((new_table->table = malloc(sizeof(list *) * size)) == NULL) return NULL;
    
    // initalize the elements of the table
    for (i=0; i < size; i++)
        new_table->table[i] = NULL;

    new_table->size = size;

    return new_table;
}

unsigned int hash(dict *htable, char *str) {
    unsigned int hashval = 5381;
    int c;

    while ((c = *str++))
        hashval = ((hashval << 5) + hashval) + c;

    return hashval % htable->size;
}


list *lookup_string(dict *htable, char *str) {
    list *d_list;
    unsigned int hashval = hash(htable, str);

    for (d_list=htable->table[hashval]; d_list != NULL; d_list=d_list->next)
        if (strcmp(str, d_list->string) == 0)
            return d_list;

    return NULL;
}


int add_string(dict *htable, char *array[], int size) {
    list *current_list;
    int i=1;

    // malloc space for str and list
    char *str = (char*) malloc(sizeof(char) * 300);
    if (str == NULL) return 1;
    list *new_list = malloc(sizeof(list));
    if (new_list == NULL) return 1;

    
    // change array into string 
    str = strdup(array[0]);

    for (i=1; size>i; i++) {
        strcat(str, ",");
        strcat(str, array[i]);
    }
    
    //lookup
    current_list = lookup_string(htable, str);
    if (current_list != NULL) {
        free(str);
        free(new_list);
        return 2;
    }
    
    // not found, insert into list
    unsigned int hashval = hash(htable, str);
    new_list->string = strdup(str);
    new_list->next = htable->table[hashval];
    htable->table[hashval] = new_list;

    return 0;
}

void free_dict(dict *htable) {
    int i;
    list *d_list, *temp;

    if (htable == NULL) return;

    // free memory for every item in the table, including the strings
    for (i=0; i<htable->size; i++) {
        d_list = htable->table[i];
        while(d_list != NULL) {
            temp = d_list;
            d_list = d_list->next;
            free(temp->string);
            free(temp);
        }
    }

    free(htable->table);
    free(htable);
}

