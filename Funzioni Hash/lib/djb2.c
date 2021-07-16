#include "djb2.h"

unsigned long hash_djb2(unsigned char *str)
    {
        long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }