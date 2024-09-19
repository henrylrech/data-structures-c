#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
{
    char *info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento *inicio;

void empilha(char vet[400])
{
    Elemento *novo;
    novo = (Elemento *)malloc(sizeof(Elemento));
    novo->info = vet;
    novo->prox = NULL;

    if (inicio == NULL)
    {
        inicio = novo;
        return;
    }

    novo->prox = inicio;
    inicio = novo;
}

void limpavetor(char vet[400], int pos)
{
    for (int i = 0; i <= pos; i++)
    {
        vet[i] = '\0';
    }
}

// returns "abc world hello"
void escreve_palavras_invertido(char *str)
{
    char vet[400];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            char *palavra = (char *)malloc((j + 1) * sizeof(char));
            strcpy(palavra, vet); 

            empilha(palavra);
            limpavetor(vet, j);
            j = 0;
            continue;
        }
        vet[j] = str[i];
        j++;
    }
    char *palavra = (char *)malloc((j + 1) * sizeof(char));
    strcpy(palavra, vet);

    empilha(palavra); 
    Elemento *aux = inicio;
    while (aux != NULL)
    {
        printf("%s ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    inicio = NULL;
    escreve_palavras_invertido("hello world abc");
}
