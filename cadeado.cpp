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
    int cadeado(int s1, int s2, int s3) {

        int x1 = 0, x2 = 0, r = 0;
        No *aux1 = cabeca, *aux2 = cabeca;
        while (aux1->valor != s1) {
            aux1 = aux1->proximo;
            x1++;
        }
        while (aux2->valor != s1) {
            aux2 = aux2->anterior;
            x2++;
        }
        //r += (x1 < x2) ? x1 : x2;
        r += (x1 > x2) ? x1 : x2;

        x1 = 0;
        x2 = 0;
        while (aux1->valor != s2) {
            aux1 = aux1->proximo;
            x1++;
        }
        while (aux2->valor != s2) {
            aux2 = aux2->anterior;
            x2++;
        }
        //r += (x1 < x2) ? x1 : x2;
        r += (x1 > x2) ? x1 : x2;

        x1 = 0;
        x2 = 0;
        while (aux1->valor != s3) {
            aux1 = aux1->proximo;
            x1++;
        }
        while (aux2->valor != s3) {
            aux2 = aux2->anterior;
            x2++;
        }
        //r += (x1 < x2) ? x1 : x2;
        r += (x1 > x2) ? x1 : x2;

        return r;
    }
};

int main() {
    ListaCircular lc;
    for (int i = 0; i < 10; i++) {
        lc.inserirFinal(i);
    }
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);
    printf("%d\n", lc.cadeado(s1, s2, s3));
    return 0;
}
