#include <stdlib.h> 
#include <string.h>
#include <limits.h>
#include "count_min_sketch.h"
#include "generale.h"


//CANCELLARE
#include <stdio.h>
void print_table(cmsketch_t* table){
    printf("\n");
    for(int i = 0 ; i< table->r; i++){
        for(int j=0; j< table->c; j++){
            printf(" %-4d", table->t[i][j]);
        }
         printf("\n");
    }
    printf("\n");
        printf("\n");
}



void hash_function(const char* key, unsigned int depth, unsigned int *a, unsigned int *b );
//Crea una nuova struttura dati
//r = righe   c = colonne
cmsketch_t* new_count_min_sketch(int r, int c){
   cmsketch_t* table;
   table = malloc(sizeof(cmsketch_t));
   table->r = r;
   table->c = c;
   table->t = malloc( r*sizeof(unsigned int*));

   for( int i = 0; i< r; i++){
       table->t[i] = calloc(c,sizeof(unsigned int*));
   } 
   return table;
}

void free_count_min_sketch(cmsketch_t* table){

    for(int i = 0; i<table->c; i++){
        free(table->t[i]);
    }            
    free(table->t);
    free(table);
}

void add_min_count_sketch(cmsketch_t* table, char *str){
    unsigned int a, b,hash;

    hash_function(str,table->r, &a, &b);
    for(int i=0; i<table->c; i++){
        hash = ((a*i + b) )% table->r;
        table->t[hash][i]++; 
    }    
}

unsigned int read_count_min_sketch(cmsketch_t * table, char *str){
    unsigned int a, b, hash, min=UINT_MAX;

    hash_function(str, table->r, &a, &b);
    for(int i=0; i<table->c; i++){
        hash = ((a*i + b) )% table->r;
        if(table->t[hash][i] <min ) min =table->t[hash][i];
    }
    return min;
}
//Somma la seconda tabella nella Prima
cmsketch_t* sum_count_min_sketch(cmsketch_t * table1, cmsketch_t * table2){
    if(table1->c == table2->c && table1->r==table2->r){
        int i,j;
        cmsketch_t * sum = new_count_min_sketch(table1->c, table1->r);
        for(i=0; i<table1->c; i++){
            for(j=0; j<table1->c; j++){
                sum->t[i][j] = table1->t[i][j]+table2->t[i][j];
            }
        } 
        return sum;
    }else return NULL;
}

cmsketch_t* clone_count_min_sketch(cmsketch_t * table){
        int i,j;
        cmsketch_t * clone = new_count_min_sketch(table->c, table->r);
        for(i=0; i<table->c; i++){
            for(j=0; j<table->c; j++){
                clone->t[i][j] = table->t[i][j];
            }
        } 
        return clone;
}


unsigned int jenkins_hash(const char *b, size_t len)
{

    unsigned int h2 = 0;

    for (unsigned int i = 0; i < len; i++) {
	h2 += b[i];
	h2 += h2 << 10;
	h2 ^= h2 >> 6;
    }
    h2 += (h2 << 3);
    h2 ^= (h2 >> 11);
    h2 += (h2 << 15);

    return h2;
}

unsigned long hash_djb2(const char *str)
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

void hash_function(const char* key, unsigned int depth, unsigned int *a, unsigned int *b ){
    
       unsigned long a1 = hash_fnv_1a(key);
       unsigned long b1 = hash_djb2(key);
       *a = a1%depth;
       *b = b1 % depth;
        if(a == 0){
            *a = (jenkins_hash(key, strlen(key))) %depth;
        }        
}

unsigned int * colonna_count_min_sketch(cmsketch_t* table, char* str){
    unsigned int a, b,hash;
   unsigned int * aux = malloc(sizeof(unsigned int)*table->c);
    hash_function(str,table->r, &a, &b);
    for(int i=0; i<table->c; i++){
        hash = ((a*i + b) )% table->r;
        aux[i]=table->t[hash][i]; 
    }
    return aux;
}