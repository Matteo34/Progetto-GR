#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib/generale.h"
#include "lib/count_min_sketch.h"
#define COLONNE 100
#define RIGHE 50
//include 

typedef struct {
    int *valore;        //c=colonne, p = profondità
    char **nome;
    int n;
} test_t;


test_t* new_test_t(int n);
void read_example_file(cmsketch_t* table);
test_t* read_risultati_file();

int main(){
    cmsketch_t* table = new_count_min_sketch(COLONNE, RIGHE);
    read_example_file(table);
    test_t* test = read_risultati_file();
    for(int i = 0 ; i< test->n; i++){
        printf(" nome : %s  valore : %d  stima : %d \n", test->nome[i],
                 test->valore[i], read_count_min_sketch(table, test->nome[i]));
        
        int * aux =colonna_count_min_sketch( table, test->nome[i]);
        //printf("TERZO\n"); 
        
        for(int j =0 ; j<table->c; j++){
                printf(" %d ", aux[j] );
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }
    print_table(table);

}

void read_example_file(cmsketch_t* table){
    char *aux = malloc(sizeof(char)*BUF_FGETS);
    char *s ;
    int n;
    FILE *ifp;
    CHECK_EQ(ifp=fopen("./Test/esempi.txt", "r"),NULL, "fopen");

    while(fgets(aux, BUF_FGETS, ifp)!=NULL){
        s = strtok(aux, "\n");
        add_min_count_sketch(table, aux);;
        int * aus =colonna_count_min_sketch( table, aux);
          
    }
}

test_t* read_risultati_file(){
    //apertura file
    test_t* test;
    char *aux;
    int n, i;
    FILE *ifp;
    CHECK_EQ(ifp=fopen("./Test/risultati.txt", "r"),NULL, "fopen");
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

    return test;

}


test_t* new_test_t(int n){
    test_t* test;
    test = malloc(sizeof(test_t));
    test->valore = malloc(sizeof(int)*n);
    test->nome = malloc(sizeof(char*)*n);
    test->n =n;
    for( int i = 0; i<n; i++){
        test->nome[i]=malloc(sizeof(char)*BUF_FGETS);
    }
    return test;
}


