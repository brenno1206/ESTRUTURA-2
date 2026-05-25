#include <stdio.h>
#include <stdlib.h>

typedef struct _NoArvNaria NoArvNaria;

typedef struct _lista {
    NoArvNaria *no_filho;
    struct _lista *proximo;
} Lista;

struct _NoArvNaria {
    int chave;
    int qtd_filhos;
    Lista *filhos;
};