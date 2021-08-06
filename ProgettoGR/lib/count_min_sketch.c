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


//Crea una nuova struttura dati
//r = righe   c = colonne
cmsketch_t* new_count_min_sketch(u_int32_t r, u_int32_t c){
   cmsketch_t* table;
   table = malloc(sizeof(cmsketch_t));
   table->r = r;
   table->c = c;
   table->t = malloc( r*sizeof(u_int32_t*));

   for( int i = 0; i< r; i++){
       table->t[i] = calloc(c,sizeof(u_int32_t*));
   } 
   return table;
}

void free_count_min_sketch(cmsketch_t* table){

    for(int i = 0; i<table->r; i++){
        free(table->t[i]);
    }            
    free(table->t);
    free(table);
}

void add_min_count_sketch(cmsketch_t* table, char *str){
    u_int32_t a, b,hash;

    hash_function(str,table->r, &a, &b);
    for(int i=0; i<table->c; i++){
        hash = ((a*i + b) )% table->r;
        table->t[hash][i]++; 
    }    
}

unsigned int read_count_min_sketch(cmsketch_t * table, char *str){
    u_int32_t a, b, hash, min=UINT_MAX;

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
        cmsketch_t * sum = new_count_min_sketch(table1->r, table1->c);
        for(i=0; i<table1->r; i++){
            for(j=0; j<table1->c; j++){
                sum->t[i][j] = table1->t[i][j]+table2->t[i][j];
            }
        } 
        return sum;
    }else return NULL;
}

cmsketch_t* clone_count_min_sketch(cmsketch_t * table){
        int i,j;
        cmsketch_t * clone = new_count_min_sketch(table->r, table->c);
        for(i=0; i<table->r; i++){
            for(j=0; j<table->c; j++){
                clone->t[i][j] = table->t[i][j];
            }
        } 
        return clone;
}


unsigned int * colonna_count_min_sketch(cmsketch_t* table, char* str){
   u_int32_t a, b,hash;
   u_int32_t * aux = malloc(sizeof(u_int32_t)*table->c);
    hash_function(str,table->r, &a, &b);
    for(int i=0; i<table->c; i++){
        hash = ((a*i + b) )% table->r;
        aux[i]=table->t[hash][i]; 
    }
    return aux;
}