#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;

    Lista() {
        cabeca = cauda = NULL;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
    }

    void inserirFinal(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
    }

    void imprimir() {
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() {
        int t = 0;
        No *aux = cabeca;
        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }
        return t;
    }

};

int main() {

    Lista l;
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);
    l.imprimir();

    printf("%d\n", l.tamanho());

    return 0;
}
