#include <stdio.h>
#include <stdlib.h>

#define M 10

typedef struct _dadoHeap {
    char tarefa;
    int prioridade;
} dadoHeap;

typedef struct _heap {
    dadoHeap *v;
    int tamanho;
} Heap;

Heap *criarHeap() {
    Heap *h = malloc(sizeof(Heap));

    h->v = malloc((M + 1) * sizeof(dadoHeap));
    h->tamanho = 0;

    return h;
}


void inserir(Heap *h, char tarefa, int prioridade) {
    if (h->tamanho >= M) {
        printf("Heap cheia\n");
        return;
    }
    int i = 0;
    if(prioridade < h->v[i].prioridade) {
        
    }
    
}

void subir(Heap *h, int i) {
    
}


void descer(Heap *h, int i) {
    
}

void removerRaiz(Heap *h) {

}


int main() {
    Heap *h = criarHeap();

    

    return 0;
}
