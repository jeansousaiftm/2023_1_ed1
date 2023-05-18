#include<stdio.h>
#include<string.h>

struct No {

    char valor[100];
    No *anterior, *proximo;

    No () {
        anterior = NULL;
        proximo = NULL;
    }

    No (char _valor[]) {
        strcpy(valor, _valor);
        anterior = NULL;
        proximo = NULL;
    }
};

struct ListaDE {

    No *cabeca, *cauda;
    int n;

    ListaDE () {
        cabeca = NULL;
        cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    void inserirFinal(char valor[]) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->anterior = cauda;
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }

    void metro(char i[], char f[]) {
        //printf("%s\n%s\n", i, f);
        No *aux1 = cabeca;
        while (strcmp(aux1->valor, i) != 0) {
            aux1 = aux1->proximo;
        }
        No *aux2 = cauda;
        while (strcmp(aux2->valor, f) != 0) {
            aux2 = aux2->anterior;
        }
        int x = 0;
        No *aux3 = aux1;
        while (aux3 != NULL && strcmp(aux3->valor, f) != 0) {
            aux3 = aux3->proximo;
            x++;
        }
        if (aux3 != NULL) {
            printf("direita %d\n", x);
            return;
        }

        aux3 = aux1;
        x = 0;
        while (aux3 != NULL && strcmp(aux3->valor, f) != 0) {
            aux3 = aux3->anterior;
            x++;
        }
        printf("esquerda %d\n", x);
    }

};

int main() {

    ListaDE l;
    l.inserirFinal("PALMEIRAS BARRA FUNDA");
    l.inserirFinal("MARECHAL DEODORO");
    l.inserirFinal("SANTA CECILIA");
    l.inserirFinal("REPUBLICA");
    l.inserirFinal("ANHANGABAU");
    l.inserirFinal("SE");
    l.inserirFinal("PEDRO II");
    l.inserirFinal("BRAS");
    l.inserirFinal("BRESSER MOOCA");
    l.inserirFinal("BELEM");
    l.inserirFinal("TATUAPE");
    l.inserirFinal("CARRAO");
    l.inserirFinal("PENHA");
    l.inserirFinal("VILA MATILDE");
    l.inserirFinal("GUILHERMINA ESPERANCA");
    l.inserirFinal("PATRIARCA");
    l.inserirFinal("ARTUR ALVIM");
    l.inserirFinal("CORINTHIANS ITAQUERA");

    char i[100], f[100];

    scanf("%[^\n]%*c", i);
    scanf("%[^\n]%*c", f);

    l.metro(i, f);

    return 0;
}
