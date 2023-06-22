#include<stdio.h>
#include<string.h>
#define MAX 1000001

struct No {
    int valor;
    No *prox;
};

struct Pilha {

    No *topo;
    int n, m;

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
            m = v;
        } else {
            novo->prox = topo;
            topo = novo;
            if (v < m) m = v;
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
                if (aux->valor == m) {
                    No *aux2 = aux->prox;
                    m = aux2->valor;
                    aux2 = aux2->prox;
                    while (aux2 != NULL) {
                        if (aux2->valor < m) {
                            m = aux2->valor;
                        }
                        aux2 = aux2->prox;
                    }
                }
                topo = topo->prox;
                delete(aux);
            }
            n--;
        } else {
            printf("EMPTY\n");
        }
    }

    int topoPilha() {
        if (vazia()) {
            return NULL;
        }
        return topo->valor;
    }

    void minimo() {
        if (vazia()) {
            printf("EMPTY\n");
            return;
        }
        printf("%d\n", m);
    }

};


struct PilhaEstatica {

    int v[MAX];
    int c, m;

    PilhaEstatica() {
        c = 0;
    }

    bool vazia() {
        return c == 0;
    }

    void inserir(int x) {
        if (vazia()) {
            m = x;
        }
        v[c++] = x;
        if (x < m) m = x;
    }

    void remover() {
        if (vazia()) {
            printf("EMPTY\n");
            return;
        }
        printf("%d\n", v[c]);
        if (v[c] == m) {
            m = v[0];
            for (int i = 1; i < c; i++) {
                if (v[i] < m) m = v[i];
            }
        }
        c--;
    }

    void minimo() {
        if (vazia()) {
            printf("EMPTY\n");
            return;
        }
        printf("%d\n", m);
    }

};

int main() {
    int n, x;
    scanf("%d", &n);
    Pilha p;
    for (int i = 0; i < n; i++) {
        char tmp[10];
        scanf("%s", tmp);
        if (strcmp(tmp, "PUSH") == 0) {
            scanf("%d", &x);
            p.inserir(x);
        } else if (strcmp(tmp, "POP") == 0) {
            p.remover();
        } else if (strcmp(tmp, "MIN") == 0) {
            p.minimo();
        }
    }

    return 0;
}

