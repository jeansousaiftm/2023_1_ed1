#include<stdio.h>

struct No {
    char valor;
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

    void inserir(char v) { // O(1)
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

    char topoPilha() {
        return topo->valor;
    }

    bool consegueDesempilhar(char a, char b, char c, char d) {
        No *aux = topo;
        if (aux->valor != a) return false;
        aux = aux->prox;
        if (aux->valor != b) return false;
        aux = aux->prox;
        if (aux->valor != c) return false;
        aux = aux->prox;
        if (aux->valor != d) return false;
        return true;
    }

};

int main() {
    Pilha p;
    int n, i, cont = 0;
    scanf("%d%*c", &n);
    //printf("%d\n", n);
    for (i = 0; i < n; i++) {
        char a, b, c, d;
        char tmp[100];
        if (p.vazia()) {
            p.inserir('F');
            p.inserir('A');
            p.inserir('C');
            p.inserir('E');
        }
        scanf("%c %c %c %c%*c", &a, &b, &c, &d);
        //printf("%c %c %c %c\n", a, b, c, d);

        if (p.consegueDesempilhar(a, b, c, d)) {
            cont++;
            p.remover();
            p.remover();
            p.remover();
            p.remover();
        } else {
            p.inserir(a);
            p.inserir(b);
            p.inserir(c);
            p.inserir(d);
        }
    }
    printf("%d\n", cont);
    return 0;
}

