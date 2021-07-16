#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/djb2.h"

int main(int argc, char* argv[]){
    if( argc == 0){ printf("Inserisci le parole da testare"); return 0;}

    int i;
    printf("Quanto vale argc : %d \n", argc); //controllo
    for(i=2 ; i<argc; i++){
        printf("Per la prima parola %s il risultato è : %lu \n", argv[i], hash_djb2(argv[i]));
    }
   
    return 1;    
    
}
