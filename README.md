# Progetto-GR
Implementazione di un **Count-Min-Sketch** da aggiungere alla libreria nDPI
***
## FILE
Nella cartella principale sono presenti il MakeFile e l'Algoritmo per eseguire il test.
Sono presenti altre due directories, lib e test. La **directory lib** contiene il codice delle funzioni che
implementano la struttura dati Count-Min-Sketch e le relative funzioni di hash.
La **directory Test** contiene i file di Test, suddivisi in tre coppie di due file, esempio che contiene tutti gli esempi da
caricare nel Count-Min-Sketch e il file risultati che contiene il numero di volte che determinate stringhe sono state inserite.

## FUNZIONI count_min_sketch.c 
  
  typedef struct {
    int c, r;        //c=colonne, p = profondità
    unsigned int * * t;
  } cmsketch_t;
  
  La struttura dati è implementata con due interi che indicano le colonne e la profondità, e da 
  una matrice di interi come contatore.
  
  #### funzioni
  
  
  
  
  
