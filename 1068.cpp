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



    char tmp[1010];

    while (scanf("%s", tmp) != EOF) {
        Pilha p;
        char resp[100];
        strcpy(resp, "correct");
        for (int i = 0; i < strlen(tmp); i++) {
            if (tmp[i] == '(') {
                p.inserir('(');
            } else if (tmp[i] == ')') {
                if (!p.remover()) {
                    strcpy(resp, "incorrect");
                }
            }
        }
        if (!p.vazia()) {
            strcpy(resp, "incorrect");
        }
        printf("%s\n", resp);
    }


    return 0;
}
