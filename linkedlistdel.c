#include <stdio.h>
#include <stdlib.h>
struct elemento
{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

void print_list()
{
    Elemento *temp = inicio;
    printf("list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->prox;
    }
    printf("\n");
}

void insert_first(int valor)
{
    Elemento *novo;
    novo = (Elemento *)malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = NULL;

    if (inicio != NULL)
    {
        novo->prox = inicio;
    }
    inicio = novo;
}

void remove_element(int num)
{
    Elemento *aux = inicio, *ant = inicio;
    while (aux != NULL && aux->info != num)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        ant->prox = aux->prox;
        free(aux);
    } else {
        printf("remove_element: %d not found on list\n", num);
    }
}

int main()
{
    inicio = NULL;
    insert_first(1);
    print_list();
    insert_first(3);
    print_list();
    insert_first(2);
    print_list();
    remove_element(3);
    print_list();
    remove_element(5);
    print_list();
}