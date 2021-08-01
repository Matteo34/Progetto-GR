#if !defined(GENERALE_H)
#define GENERALE_H

#define BUF_FGETS 60

#define CHECK_EQ(x, val,str)\
    if((x) == val){\
          perror(str); \
         fprintf(stderr,"Error at line %d of file %s\n", __LINE__, __FILE__);\
         exit(EXIT_FAILURE);\
}

//extern struct timespec diff(struct timespec start, struct timespec end);





#endif
