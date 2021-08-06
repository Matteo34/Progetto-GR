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
    u_int32_t c, r;     
    u_int32_t ** t;
  } cmsketch_t;
  
  La struttura dati è implementata con due interi che indicano le colonne e la profondità, e da 
  una matrice di interi come contatore.
  
  **funzioni** :
   * **cmsketch_t * new_count_min_sketch(int c, int r)** crea una struttura dati con c colonne e r righe
   *  **void free_count_min_sketch(cmsketch_t * table)** dealloca la memoria utilizzata
   *  **void add_min_count_sketch(cmsketch_t * table, char * str)** aggiunge al contatore una istanza di *str
   *  **unsigned int read_count_min_sketch(cmsketch_t * table, char * str)** legge il valore corrispondete a *str
   *  **cmsketch_t * sum_count_min_sketch(cmsketch_t * table1, cmsketch_t * table2)** ritorna una nuova struttura dati, che a come valore la somma delle due struttura passate come parametri
   *  **cmsketch_t * clone_count_min_sketch(cmsketch_t * table)** ritorna una nuova struttura dati, che è una copia del parametro passato
   *  **unsigned int * colonna_count_min_sketch(cmsketch_t * table, char * str)** ritorna un array che contiene i valori associaati alla stringa str nella struttura dati
   
## MAKEFILE
 Utilizzare il comando **make** per la compilazione.
 I comandi **make cleanall** e **make test** permettono rispettivamente di eliminare tutti i file prodotti dalla compilazione e di eseguire il Test.
 
 ## TEST
 Il test può essere eseguito con il comando **make test**.
 Consiste nella lettura di 6 file, 3 contenenti gli esempi da aggiungere nella struttura dati e altri 3 contenenti il numero di volte alcune parole compaino nel    file di esempi.
 
  
  
  
