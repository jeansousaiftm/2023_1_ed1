#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Pilha {

    No *topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (topo == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = topo;
                topo = NULL;
                delete(aux);
            } else {
                No *aux = topo;
                topo = topo->prox;
                delete(aux);
            }
            n--;
        }
    }

    int topoPilha() {
        if (vazia()) {
            return NULL;
        }
        return topo->valor;
    }

};

int main() {

    Pilha p;

    p.inserir(10);
    p.inserir(20);
    p.inserir(30);
    p.inserir(40);
    p.inserir(50);
    p.inserir(60);

    printf("%d\n", p.topoPilha());

    p.remover();
    p.remover();
    p.remover();

    printf("%d\n", p.topoPilha());

    p.remover();
    p.remover();
    p.remover();

    printf("%d\n", p.topoPilha());


    return 0;
}
