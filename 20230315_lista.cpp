#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
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
        n++;
    }

    void inserirFinal(int v) { // O(1)
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
        n++;
    }

    void imprimir() { // O(n)
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    /*int tamanho() { // O(n)
        int t = 0;
        No *aux = cabeca;
        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }
        return t;
    }*/

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }

    void removerN(int x) {
        for (int i = 0; i < x; i++) {
            removerFinal();
        }
    }

    void removerSegundo() {
        if (tamanho() == 2) {
            removerFinal();
        } else if (tamanho() > 2) {
            No *aux = cabeca->prox;
            cabeca->prox = aux->prox;
            delete(aux);
            n--;
        }
    }

    void inserirTamanho() {
        inserirFinal(tamanho());
    }

    void inserirN(int x) {
        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }
    }

    void inserirPenultima(int x) {
        if (tamanho() > 1) {
            No *penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            No *novo = new No();
            novo->valor = x;
            novo->prox = cauda;
            penultimo->prox = novo;
        }
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
    l.removerInicio();
    l.removerInicio();
    l.removerInicio();
    l.imprimir();

    //printf("%d\n", l.tamanho());

    return 0;
}
