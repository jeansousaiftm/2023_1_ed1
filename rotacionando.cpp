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
    int n, x, i, c = 0;
    Fila a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        a.inserir(x);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        b.inserir(x);
    }
    while (!a.vazia() && !b.vazia()) {
        if (a.frente() == b.frente()) {
            a.remover();
            b.remover();
            c++;
        } else {
            a.inserir(a.frente());
            a.remover();
            c++;
        }
    }
    printf("%d\n", c);
    return 0;
}
