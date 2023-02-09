#include<stdio.h>
#include<string.h>

struct Cliente {

    char nome[100];
    int idade;

    Cliente() {
        strcpy(nome, "");
        idade = 0;
    }

    void imprimir() {
        printf("Nome: %s\nIdade: %d\n", nome, idade);
    }

};

int main() {

    Cliente c;

    c.imprimir();

    scanf("%s %d", c.nome, &c.idade);


    return 0;
}
