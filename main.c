#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct NoArvNaria {
    int info;
    struct NoArvNaria *filhos[M];
} TArvNaria, *ArvNaria;


ArvNaria *inicArvNaria(){
    ArvNaria *arv = (ArvNaria *) malloc(sizeof(ArvNaria));
    for(int i = 0; i < M; i++) {
        arv->filhos[i] = NULL;
    }
    return arv;
}

ArvNaria *criaArvNaria() {}

ArvNaria *inserir(ArvNaria *arv, int num) {
    
    int j = 0;
    for(ArvNaria i = (*arv)->filhos[j]; i != NULL && j < 5; i = (*arv)->filhos[j]) {
        j++;
    }
    if((*arv)->filhos[j] == NULL) {
        ArvNaria *novo_no = criarArv();
        (*novo_no)->info = num;
        (*arv)->filhos[j] = (*novo_no);
        return novo_no;
    }
    return NULL;
}

ArvNaria *subarvores(ArvNaria *arv) {
    return (*arv)->filhos;
}

int main()
{
    
    return 0;
}
