#include<stdio.h>
#include<string.h>

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

    int tamanho() {
        return n;
    }

    bool remover() { // O(1)
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
            return true;
        }
        return false;
    }

};

int main() {

    int n;

    scanf("%d", &n);

    for (int j = 0; j < n; j++) {

        char tmp[1010];

        scanf("%s", tmp);
        Pilha p;
        int c = 0;
        for (int i = 0; i < strlen(tmp); i++) {
            if (tmp[i] == '<') {
                p.inserir('<');
            } else if (tmp[i] == '>') {
                if (p.remover()) {
                    c++;
                }
            }
        }
        printf("%d\n", c);

    }


    return 0;
}
