#include <string.h>
#include "hash_function.h"

unsigned long hash_djb2(unsigned char *str)
    {
        long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

 unsigned long  hash_fnv_1a(const char* key) {
    
    int i, len = strlen(key);
    unsigned long h = 14695981039346656073ULL; // FNV_OFFSET 64 bit
    for (i = 0; i < len; ++i){
            h = h ^ (unsigned char) key[i];
            h = h * 1099511628211ULL; // FNV_PRIME 64 bit
    }
    return h;
}
