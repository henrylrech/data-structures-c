#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento; // [info, *prox] -> n tem como ir direto no num 100, porem da pra crescer individualmente

Elemento *inicio;

void insere_primeiro(int valor) {
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    if (inicio != NULL) {
        novo->prox = inicio;
    }
    inicio = novo;
}

void insere_ultimo(int valor) {
    Elemento *novo, *aux=inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    if (aux==NULL) {
        inicio = novo;
        return;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

void insere_meio(int valor) {
    Elemento *novo, *aux=inicio, *ant=inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    while (aux != NULL && aux->info < valor){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = novo;
    novo->prox = aux;
}

void escreve_lista() {
    Elemento *temp = inicio;
    printf("lista:\n");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->prox;
    }
}



int main () {
    inicio = NULL;
    insere_primeiro(5);
    insere_ultimo(9);
    insere_meio(7);
    insere_meio(7);
    escreve_lista();
}
       