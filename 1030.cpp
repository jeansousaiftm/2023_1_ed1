#include<stdio.h>

struct No {
    int valor;
    No *anterior, *proximo;
    No() {
        anterior = proximo = NULL;
    }
    No(int _valor) {
        valor = _valor;
        anterior = proximo = NULL;
    }
};

struct ListaCircular {
    No *cabeca, *cauda;
    int n;
    ListaCircular() {
        cabeca = cauda = NULL;
        n = 0;
    }
    bool vazia() {
        return cabeca == NULL;
    }
    int tamanho() {
        return n;
    }
    void inserirInicio(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = cauda = novo;
            cabeca->proximo = cauda;
            cauda->anterior = cabeca;
        } else {
            novo->proximo = cabeca;
            novo->anterior = cauda;
            cauda->proximo = novo;
            cabeca->anterior = novo;
            cabeca = novo;
        }
        n++;
    }
    void inserirFinal(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = cauda = novo;
            cabeca->proximo = cauda;
            cauda->anterior = cabeca;
        } else {
            novo->proximo = cabeca;
            novo->anterior = cauda;
            cauda->proximo = novo;
            cabeca->anterior = novo;
            cauda = novo;
        }
        n++;
    }
    void imprimir() {
        if (!vazia()) {
            No *aux = cabeca;
            do {
                printf("%d -> ", aux->valor);
                aux = aux->proximo;
            } while (aux != cabeca);
        }
        printf("\n");
    }
    void removerInicio() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = cauda = NULL;
            } else {
                No *aux = cabeca;
                cabeca = cabeca->proximo;
                cabeca->anterior = cauda;
                cauda->proximo = cabeca;
                delete(aux);
            }
            n--;
        }
    }
    void removerFinal() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = cauda = NULL;
            } else {
                No *aux = cauda;
                cauda = cauda->anterior;
                cabeca->anterior = cauda;
                cauda->proximo = cabeca;
                delete(aux);
            }
            n--;
        }
    }
    int josephus(int m) {
        No *aux = cabeca;
        while (tamanho() > 1) {
            for (int i = 0; i < m - 1; i++) {
                aux = aux->proximo;
            }
            No *aux_ant = aux->anterior;
            No *aux_prox = aux->proximo;
            aux_ant->proximo = aux_prox;
            aux_prox->anterior = aux_ant;
            delete(aux);
            n--;
            aux = aux_prox;
        }
        return aux->valor;
    }
};

int main() {
    int nc, n, m, i, j;
    scanf("%d", &nc);
    for (i = 1; i <= nc; i++) {
        ListaCircular lc;
        scanf("%d %d", &n, &m);
        for (j = 1; j <= n; j++) {
            lc.inserirFinal(j);
        }
        printf("Case %d: %d\n", i, lc.josephus(m));
    }
    return 0;
}
