#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

void empilha(int valor) {
    Elemento *novo;
    novo = (Elemento*)malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
        return;
    }

    novo->prox = inicio;
    inicio = novo;
}

int desempilha() {
    if (inicio == NULL) {
        return 0;
    }
    int val = inicio->info;
    inicio = inicio->prox;
    return val;
}

void escreve() {
    Elemento *temp = inicio;
    printf("lista:\n");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    inicio = NULL;
    empilha(5);
    escreve();
    empilha(7);
    escreve();
    int val = desempilha();
    escreve();
    empilha(6);
    escreve();
}