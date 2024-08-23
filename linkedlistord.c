#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

void insere_ordenado(int valor) {
    Elemento *novo, *aux=inicio, *ant=inicio;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    if (aux == NULL) { //inicio nulo
        inicio = novo;
        return;
    }

    if (aux->prox == NULL) { //segunda pos nulo
        if (aux->info < valor) {
            inicio->prox = novo;
        } else {
            inicio = novo;
            inicio->prox = ant;
        }
        return;
    }

    while (aux != NULL && aux->info < valor){
        ant = aux;
        aux = aux->prox;
    }

    if (ant == inicio && aux == inicio) { //primeira pos
        inicio = novo;
        inicio->prox = aux;
        return;
    }

    if (ant == inicio && aux != inicio) { //segunda pos
        inicio->prox = novo;
        novo->prox = aux;
        return;
    }

    if (ant->prox == NULL) { // no fim
        aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        return;
    }

    ant->prox = novo; //no meio
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
    //acho que da pra simplicar mas funcionou então deixei assim :p
    insere_ordenado(3);
    insere_ordenado(7);
    insere_ordenado(5);
    insere_ordenado(9);
    insere_ordenado(6);
    insere_ordenado(12);
    insere_ordenado(3);
    insere_ordenado(1);
    insere_ordenado(6);
    escreve_lista();
}