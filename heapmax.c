#include <stdio.h>
#include <stdlib.h>

#define M 10

typedef struct _dado {
    char tarefa;
    int prioridade;
} dado;

typedef struct _heap {
    dado *v[M +1];
    int qtd;
} heap;

heap *criarHeap() {
    
    heap *h = malloc(sizeof(heap));
    h->qtd = 0;
    for(int i = 0; i <= M; i++) {
        h->v[i] = NULL;
    }
    return h;
}

void subir(heap *h, int idx) {
    if (idx == 0) return;
    int idx_pai = (idx -1) / 2;
    if(h->v[idx]->prioridade > h->v[idx_pai]->prioridade) {
        dado *d = h->v[idx_pai];
        h->v[idx_pai] = h->v[idx];
        h->v[idx] = d;
        subir(h, idx_pai);
    }
}

void inserir(heap *h, char tarefa, int prioridade) {
    if(h->qtd < M) {
        dado *d = malloc(sizeof(dado));
        d->tarefa = tarefa;
        d->prioridade = prioridade;
        h->v[h->qtd] = d;
        h->qtd++;
        subir(h, h->qtd-1);
    }
}

void descer(heap *h, int idx) {
    int idx_dir = (2*idx) + 2;
    int idx_esq = (2*idx) + 1;
    int idx_troca = -1;
    
    if(idx_esq >= h->qtd) return;
    
    if(idx_dir >= h->qtd) {
        if(h->v[idx_esq]->prioridade > h->v[idx]->prioridade) {
            idx_troca = idx_esq;
        }
    } else { 
        if(h->v[idx_esq]->prioridade > h->v[idx_dir]->prioridade) {
            idx_troca = idx_esq;
        } else {
            idx_troca = idx_dir;
        }
        if(h->v[idx]->prioridade >= h->v[idx_troca]->prioridade) {
            return;
        }
    }

    if(idx_troca != -1) {
        dado *d = h->v[idx];
        h->v[idx] = h->v[idx_troca];
        h->v[idx_troca] = d;
        descer(h, idx_troca);
    }
}

void remover_raiz(heap *h) {
    dado *d = h->v[0];
    free(d);
    h->qtd--;
    
    h->v[0] = h->v[h->qtd];
    h->v[h->qtd] = NULL;
    
    descer(h,0);
}

void print_heap_recursivo(heap *h, int indice, int nivel) {
    // Agora checamos se o índice passou da quantidade de elementos inseridos
    if (h == NULL || indice >= h->qtd || h->v[indice] == NULL) {
        return;
    }
    
    // Direito em base-0: (2 * indice) + 2
    print_heap_recursivo(h, 2 * indice + 2, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("       ");
    }
    printf("[%c: %d]\n", h->v[indice]->tarefa, h->v[indice]->prioridade);

    // Esquerdo em base-0: (2 * indice) + 1
    print_heap_recursivo(h, 2 * indice + 1, nivel + 1);
}

void print_heap(heap *h) {
    if (h == NULL || h->qtd == 0) {
        printf("A heap esta vazia.\n");
        return;
    }
    
    printf("--- Estrutura da Heap ---\n");
    // Agora passamos 0 como raiz inicial, e não mais 1
    print_heap_recursivo(h, 0, 0); 
    printf("-------------------------\n");
}

int main() {
    heap *h = criarHeap();
    inserir(h, 'A', 10);
    inserir(h, 'B', 20);
    inserir(h, 'C', 15);
    inserir(h, 'D', 30);
    inserir(h, 'E', 55);
    inserir(h, 'F', 12);
    inserir(h, 'G', 32);
    inserir(h, 'H', 321);
    inserir(h, 'I', 23);
    inserir(h, 'J', 5);
    
    print_heap(h);
    
    remover_raiz(h);
    
    print_heap(h);
    
    return 0;
}
