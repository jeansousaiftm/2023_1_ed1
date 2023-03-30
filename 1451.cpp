#include<stdio.h>
#include<string.h>

struct No {

    char valor;
    No *proximo;

    No () {
        proximo = NULL;
    }

    No (char _valor) {
        valor = _valor;
        proximo = NULL;
    }
};

struct ListaDE {

    No *cabeca, *cauda, *cursor;
    int n;

    ListaDE () {
        cabeca = NULL;
        cauda = NULL;
        cursor = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    void inserirInicio(char valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->proximo = cabeca;
            cabeca = novo;
        }
        cursor = cabeca;
        n++;
    }

    void inserirFinal(char valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }

    void inserirCursor(char valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->proximo = cursor->proximo;
            cursor->proximo = novo;
        }
        cursor = novo;
        if (cursor->proximo == NULL) cauda = cursor;
        n++;
    }

    int tamanho() {
        return n;
    }

    void imprimir() {
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%c", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }

};

int main() {

    char tmp[100001];
    while (scanf("%s", tmp) != EOF) {
        ListaDE l;
        int chave = 1; // 1= final 2= inicio 3= cursor
        for (int i = 0; tmp[i] != '\0'; i++) {
            if (tmp[i] == '[') {
                chave = 2;
            } else if (tmp[i] == ']') {
                chave = 1;
            } else {
                if (chave == 1) {
                    l.inserirFinal(tmp[i]);
                } else if (chave == 2) {
                    l.inserirInicio(tmp[i]);
                    chave = 3;
                } else if (chave == 3) {
                    l.inserirCursor(tmp[i]);
                }
            }
        }
        l.imprimir();
    }
    return 0;
}

