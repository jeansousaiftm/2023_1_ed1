#include<stdio.h>
#include<string.h>

struct Produto {
    char nome[100];
    int qtde;
    double vu, vt;
    Produto() {
        strcpy(nome, "");
        qtde = 0;
        vu = 0;
        vt = 0;
    }
    void ler() {
        scanf("%s %d %lf", nome, &qtde, &vu);
        calcularVT();
    }
    void imprimir() {
        printf("%s %d x %.2lf = %.2lf\n", nome, qtde, vu, vt);
    }
    void calcularVT() {
        vt = qtde * vu;
    }
};

struct Venda {
    char cliente[100];
    Produto itens[10];
    int qtdeItens;
    double vt;
    Venda() {
        strcpy(cliente, "");
        qtdeItens = 0;
        vt = 0;
    }
    void ler() {
        scanf("%s %d", cliente, &qtdeItens);
        for (int i = 0; i < qtdeItens; i++) {
            itens[i].ler();
        }
        calcularVT();
    }
    void imprimir() {
        printf("%s R$%.2lf\n", cliente, vt);
        for (int i = 0; i < qtdeItens; i++) {
            itens[i].imprimir();
        }
    }
    void calcularVT() {
        vt = 0;
        for (int i = 0; i < qtdeItens; i++) {
            vt += itens[i].vt;
        }
    }
};

int main() {
    Venda v;
    v.ler();
    v.imprimir();
    return 0;
}
