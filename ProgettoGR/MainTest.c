#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib/generale.h"
#include "lib/count_min_sketch.h"
#define RIGHE 101
#define COLONNE 47
#define SMALLR 5
#define SMALLC 3
#define SMALLES "./Test/small_es.txt"
#define SMALLRIS "./Test/small_ris.txt"
#define ES1 "./Test/esempi.txt"
#define RIS1 "./Test/risultati.txt"
#define ES2 "./Test/altro_es.txt"
#define RIS2 "./Test/altro_ris.txt"
//include 

typedef struct {
    int *valore;        //c=colonne, p = profondità
    char **nome;
    int n;
} test_t;

void check_value(test_t *test, cmsketch_t * table );
void free_test(test_t *test);
test_t* new_test_t(int n);
void read_example_file(cmsketch_t* table, char* esempi);
test_t* read_risultati_file(char* risultati);

int main(){
    //small
    cmsketch_t* small_table = new_count_min_sketch(SMALLR, SMALLC);
    read_example_file(small_table, SMALLES);
    test_t* small_test = read_risultati_file(SMALLRIS);
    print_table(small_table);
    //printf("***************************small_table*******************************************************************************************************\n");
    check_value(small_test, small_table);

    //prima lettura 
    cmsketch_t* table = new_count_min_sketch(RIGHE, COLONNE);
    read_example_file(table, ES1);
    test_t* test = read_risultati_file(RIS1);
   
    print_table(table);
    //printf("***************************table1*******************************************************************************************************\n");
    //check_value(test, table);


    //seconda lettura
        //seconda lettura
    cmsketch_t* table2 = new_count_min_sketch(RIGHE, COLONNE);
    read_example_file(table2, ES2);
    test_t* test2 = read_risultati_file(RIS2);
    printf("\n");
    printf("\n");
    printf("\n");
    print_table(table2);
   // printf("***************************table2*******************************************************************************************************\n");
    //check_value(test2, table2);

    cmsketch_t* table3;
    if((table3 = sum_count_min_sketch(table, table2))!=NULL){
          print_table(table3);
    }
    free_count_min_sketch(table2);
    table2 = clone_count_min_sketch(table3);
    print_table(table2);
    
    
    
    //******free****************************************************************
    free_count_min_sketch(table);
    free_count_min_sketch(table2);
    free_count_min_sketch(table3);
    free_count_min_sketch(small_table);
    free_test(test);
    free_test(test2);
    free_test(small_test);
    


}
//Legge un File di esempio e riempe una Count Min Sketch 
void read_example_file(cmsketch_t* table, char* esempi){
    char *aux = malloc(sizeof(char)*BUF_FGETS);
    char *s ;
    int n;
    FILE *ifp;
    CHECK_EQ(ifp=fopen(esempi, "r"),NULL, "fopen");

    while(fgets(aux, BUF_FGETS, ifp)!=NULL){
        s = strtok(aux, "\n");
        add_min_count_sketch(table, aux);
          
    }
    free(aux);
    fclose(ifp);
}


//Legge un file di risultato
test_t* read_risultati_file( char* risultati){
    //apertura file
    test_t* test;
    char *aux;
    int n, i;
    FILE *ifp;
    CHECK_EQ(ifp=fopen(risultati, "r"),NULL, "fopen");
    //leggere una riga
    char *s= malloc(sizeof(char)*BUF_FGETS);
    CHECK_EQ(fgets(s, BUF_FGETS, ifp),NULL, "fgets");  
    n= atoi(s);
    test= new_test_t(n);


    for(i=0 ; i<test->n ; i++){
        CHECK_EQ(fgets(s, BUF_FGETS, ifp),NULL, "fgets");
        CHECK_EQ((aux=strtok(s, ":")),NULL, "strtok");
        test->nome[i]= strcpy(calloc(BUF_FGETS, sizeof(char)), aux);
        CHECK_EQ((aux=strtok(NULL, ":")),NULL, "strtok");
        test->valore[i]= atoi(aux);
    }  
    free(s);
    fclose(ifp);

    return test;

}


test_t* new_test_t(int n){
    test_t* test;
    test = malloc(sizeof(test_t));
    test->valore = malloc(sizeof(int)*n);
    test->nome = malloc(sizeof(char*)*n);
    test->n =n;
    /*for( int i = 0; i<n; i++){
        test->nome[i]=malloc(sizeof(char)*BUF_FGETS);
    }*/
    return test;
}
void free_test(test_t *test){
    for( int i = 0; i<test->n; i++){
        free(test->nome[i]);
    }
    free(test->valore);
    free(test->nome);
    free(test);

}
//controlla che i valori della riga della tabella non siano minori alla stima
void check_value(test_t *test, cmsketch_t * table ){

    
    for(int i = 0 ; i< test->n; i++){
        //printf(" nome : %s  valore : %d  stima : %d \n", test->nome[i],
        //         test->valore[i], read_count_min_sketch(table, test->nome[i]));
        
        int * aux =riga_count_min_sketch( table, test->nome[i]);
        //printf("TERZO\n"); 
        
        for(int j =0 ; j<table->c; j++){
                if(test->valore[i]>aux[j]) printf("errore  %s \n", test->nome[i]);
        }
        free(aux);
    }

}

