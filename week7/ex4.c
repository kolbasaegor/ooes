#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void * my_realloc(void * ptr, size_t size)
{
    void *new;

    if (!ptr) {
        new = malloc(size);
        if (!new) { return NULL; }
    } else {
        if (malloc_usable_size(ptr) < size) {
            new = malloc(size);
            if (!new) { return NULL; }

            memcpy(new, ptr, malloc_usable_size(ptr));

            free(ptr);
        } else {
            new = ptr;
        }
    }

    return new;
}

int main(){
    
 
    return 0;
}

