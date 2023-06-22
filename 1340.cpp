#include<stdio.h>
#include<queue>

using namespace std;

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
    int n, x, y;
    while (scanf("%d", &n) != EOF) {
        Fila f;
        Pilha p;
        priority_queue<int> pq;
        bool pilha = true, fila = true, filaPrioridade = true;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            if (x == 1) {
                f.inserir(y);
                p.inserir(y);
                pq.push(y);
            } else if (x == 2) {
                if (f.frente() != y) {
                    fila = false;
                }
                if (p.topoPilha() != y) {
                    pilha = false;
                }
                if (pq.top() != y) {
                    filaPrioridade = false;
                }
                f.remover();
                p.remover();
                pq.pop();
            }
        }
        if (pilha && !fila && !filaPrioridade) {
            printf("stack\n");
        } else if (!pilha && fila && !filaPrioridade) {
            printf("queue\n");
        } else if (!pilha && !fila && filaPrioridade) {
            printf("priority queue\n");
        } else if (!pilha && !fila && !filaPrioridade) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}
