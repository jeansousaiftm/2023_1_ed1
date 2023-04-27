#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = NULL;
        cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    bool existe(int valor) {
        No *aux = cabeca;
        while (aux != NULL) {
            if (aux->valor == valor) {
                return true;
            }
            aux = aux->prox;
        }
        return false;
    }

    void remover(int valor) {
        if (existe(valor)) {
            No *aux = cabeca;
            if (aux != NULL) {
                if (aux->valor == valor) {
                    aux = aux->prox;
                    removerInicio();
                }
                No *aux2 = aux->prox;
                while (aux2 != NULL) {
                    if (aux2->valor == valor) {
                        aux->prox = aux2->prox;
                        delete(aux2);
                        n--;
                    }
                    aux = aux->prox;
                    aux2 = aux->prox;
                }
            }
        }
    }

    void inserir(int valor) {
        if (!existe(valor)) {
            inserirFinal(valor);
        }
    }

};

int main() {
    return 0;
}
