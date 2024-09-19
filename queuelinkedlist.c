#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

// insere o primeiro
void enfileira(int valor) {
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

// remove o ultimo
int desenfileira() {
    Elemento *ant=inicio;
    Elemento *aux=inicio;
    if (inicio == NULL) {
        return 0;
    }

    if (inicio->prox == NULL) {
        int val = inicio->info;
        inicio = NULL;
        return val;
    }

    while (aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }

    int val = aux->info;
    ant->prox = NULL;
    free(aux);
    printf("desenfileirado %d\n", val);
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
    enfileira(5);
    escreve();
    enfileira(8);
    escreve();
    enfileira(7);
    escreve();
    int val = desenfileira();
    escreve();
    enfileira(6);
    escreve();
}