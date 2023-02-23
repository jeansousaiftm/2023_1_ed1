#include<stdio.h>

struct No {
    int x;
    No *proximo;
};

struct Data {
    int dia, mes, ano, idade;
};

// Passagem de parâmetro por valor
// I.e. uma cópia da struct é criada na memória
void imprimir(Data d) {
    printf("PV %02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

// Passagem de parâmetro por referência
// I.e. usamos a mesma posição de memória da struct
// na função principal
void imprimir(Data *d) {
    printf("PR %02d/%02d/%04d\n", d->dia, d->mes, d->ano);
}

// Vetores sempre são passados por referência
void imprimirVetor(int v[], int n) {

}

int main() {

    int a;

    scanf("%d", &a);
    printf("%d\n", a);

    int *p = &a;

    printf("%d\n", *p);
    Data d;
    d.dia = 23;
    d.mes = 2;
    d.ano = 2023;
    imprimir(d);
    imprimir(&d);

    int v[10];
    imprimirVetor(v, 10); // <- v indica o endereço de memória

    return 0;
}
