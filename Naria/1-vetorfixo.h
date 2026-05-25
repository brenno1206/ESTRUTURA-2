#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct _NoArvNaria {
    int chave;
    struct _NoArvNaria *filhos[];
} NoArvNaria, *ArvNaria;