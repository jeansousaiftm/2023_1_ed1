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
};

int main() {
    ListaCircular lc;
    lc.imprimir();
    lc.inserirInicio(1);
    lc.inserirInicio(2);
    lc.inserirInicio(3);
    lc.inserirFinal(4);
    lc.inserirFinal(5);
    lc.inserirFinal(6);
    lc.imprimir();
    return 0;
}
