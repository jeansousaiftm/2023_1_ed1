#include<stdio.h>
#include<string.h>
#define MAX 10

struct Pilha {

    char v[MAX];
    int c;

    Pilha() {
        c = 0;
    }

    bool vazia() {
        return c == 0;
    }

    bool cheia() {
        return c >= MAX;
    }

    int tamanho() {
        return c;
    }

    void inserir(char x) {
        if (cheia()) {
            return;
        }
        v[c++] = x;
    }

    void remover() {
        if (vazia()) {
            return;
        }
        c--;
    }

    char topo() {
        if (vazia()) {
            return NULL;
        }
        return v[c - 1];
    }

};

int main() {
    char tmp[100];
    scanf("%[^\n]", tmp);
    Pilha p;
    int r = 1;
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '{') {
            if (p.vazia()) {
                p.inserir(tmp[i]);
            } else {
                r = 0;
                break;
            }
        } else if (tmp[i] == '[') {
            if (p.topo() == '{') {
                p.inserir(tmp[i]);
            } else {
                r = 0;
                break;
            }
        } else if (tmp[i] == '(') {
            if (p.topo() == '[') {
                p.inserir(tmp[i]);
            } else {
                r = 0;
                break;
            }
        } else if (tmp[i] == ')') {
            if (p.topo() == '(') {
                p.remover();
            } else {
                r = 0;
                break;
            }
        } else if (tmp[i] == ']') {
            if (p.topo() == '[') {
                p.remover();
            } else {
                r = 0;
                break;
            }
        } else if (tmp[i] == '}') {
            if (p.topo() == '{') {
                p.remover();
            } else {
                r = 0;
                break;
            }
        }
    }
    if (!p.vazia()) r = 0;
    printf("%d\n", r);
    return 0;
}
