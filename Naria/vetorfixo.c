#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct NoArvNaria {
    int info;
    struct NoArvNaria *filhos[M];
} TArvNaria, *ArvNaria;



ArvNaria criarArv(int valor) {
    ArvNaria arv = (ArvNaria) malloc(sizeof(TArvNaria));

    if (arv != NULL) {
        arv->info = valor;
        for(int i = 0; i < M; i++) {
            arv->filhos[i] = NULL;
        }
    }

    return arv;
}


ArvNaria inserir(ArvNaria arv, int num) {
    if (arv == NULL) return NULL;

    int j = 0;

    while (j < M && arv->filhos[j] != NULL) {
        j++;
    }

    if (j < M) {
        ArvNaria novo_no = criarArv(num);
        arv->filhos[j] = novo_no;
        return novo_no;
    }

    return NULL;
}


int pertence(ArvNaria arv, int num) {
    if (arv == NULL) return 0;

    if (arv->info == num) return 1;

    for (int i = 0; i < M; i++) {
        if (pertence(arv->filhos[i], num)) {
            return 1;
        }
    }

    return 0;
}

// Nao escrever daqui pra baixo 
void imprimirArvore(ArvNaria arv, int nivel) {
    if (arv == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("- ");
    }

    printf("%d\n", arv->info);

    for (int i = 0; i < M; i++) {
        imprimirArvore(arv->filhos[i], nivel + 1);
    }
}


int main() {

    ArvNaria arvore = criarArv(0);

    printf("Arvore criada\n");

    ArvNaria f1 = inserir(arvore, 1);
    ArvNaria f2 = inserir(arvore, 2);
    ArvNaria f3 = inserir(arvore, 3);
    ArvNaria f4 = inserir(arvore, 4);
    
    ArvNaria f11 = inserir(f1, 5);
    ArvNaria f12 = inserir(f11, 6);
    ArvNaria f13 = inserir(f1, 7);
    ArvNaria f14 = inserir(f1, 8);

    printf("\nPertence 3? %d\n", pertence(arvore, 3));
    printf("Pertence 99? %d\n", pertence(arvore, 99));
    
    printf("\nImprimindo arvore:\n");
    imprimirArvore(arvore, 0);

    return 0;
}
