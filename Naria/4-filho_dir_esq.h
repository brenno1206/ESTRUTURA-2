#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int valor;
    _no *filho;
    _no *irmao;
} noArvNaria, *ArvNaria;
