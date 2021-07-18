#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/hash_function.h"

int main(int argc, char* argv[]){
    if( argc == 0){ printf("Inserisci le parole da testare"); return 0;}

    unsigned long a,i, b;

    printf("Quanto vale argc : %d \n", argc); //controllo
    for(i=2 ; i<argc; i++){
        a = hash_djb2(argv[i]);
        b= hash_fnv_1a(argv[i]);
        printf("Per la prima parola %s il risultato è : %lu djb2  %lu fnv1a \n", argv[i], a, b);

        printf("valori delle celle scelte : %ld \n", (a*i + b) % 53 );    
    }
   
    return 1;    
    
}
 