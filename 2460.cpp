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
    int n, m, i, x, v[100001];
    Fila f;
    for (i = 0; i <= 100000; i++) v[i] = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        f.inserir(x);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        v[x]++;
    }
    bool imprimiu = false;
    while (!f.vazia()) {
        x = f.frente();
        if (v[x] == 0) {
            if (imprimiu) printf(" ");
            printf("%d", x);
            imprimiu = true;
        }
        f.remover();
    }
    printf("\n");
    return 0;
}
