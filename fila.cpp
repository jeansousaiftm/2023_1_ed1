#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Fila {
    No *cabeca, *cauda;
    int n;

    Fila() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserir(int v) { // O(1)
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

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
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

    int frente() {
        if (vazia()) {
            return NULL;
        }
        return cabeca->valor;
    }

};

int main() {

    Fila f;

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);
    f.inserir(40);
    f.inserir(50);
    f.inserir(60);

    printf("%d\n", f.frente());

    f.remover();
    f.remover();
    f.remover();

    printf("%d\n", f.frente());

    f.remover();
    f.remover();
    f.remover();

    printf("%d\n", f.frente());

    return 0;
}
