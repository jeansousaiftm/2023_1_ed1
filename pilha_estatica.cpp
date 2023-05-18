#include<stdio.h>
#define MAX 5

struct Pilha {

    int v[MAX];
    int c;

    Pilha() {
        c = 0;
    }

    bool vazia() {
        return c == 0;
    }

    bool cheia() {
        return c >= MAX;
    }

    int tamanho() {
        return c;
    }

    void inserir(int x) {
        if (cheia()) {
            printf("Pilha cheia\n");
            return;
        }
        v[c++] = x;
    }

    void remover() {
        if (vazia()) {
            printf("Pilha vazia\n");
            return;
        }
        c--;
    }

    int topo() {
        if (vazia()) {
            printf("Pilha vazia\n");
            return NULL;
        }
        return v[c - 1];
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

    printf("%d\n", p.topo());

    p.remover();
    p.remover();
    p.remover();

    printf("%d\n", p.topo());

    p.remover();
    p.remover();
    p.remover();

    printf("%d\n", p.topo());

    return 0;
}
