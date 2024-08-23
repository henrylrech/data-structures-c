#include <stdio.h>

struct PessoaStruct
{
    int number;
    char name[50];
};
typedef struct PessoaStruct Pessoa;

void InverteLista(Pessoa* ptrpessoas, int size) {
    Pessoa temp;
    for (int i = 0; i < size/2; i++) {
        temp = ptrpessoas[i];
        ptrpessoas[i] = ptrpessoas[size-1-i];
        ptrpessoas[size-1-i] = temp;
    }
}

void InsereUltimaPos(Pessoa* ptrpessoas, Pessoa new, int* size) {
    ptrpessoas[*size] = new;
    *size = *size + 1;
}

void InserePrimeiraPos(Pessoa* ptrpessoas, Pessoa new, int* size) {
    for (int i=*size; i>=0; i--) {
        if (i == 0) {
            ptrpessoas[0] = new;
        } else {
            ptrpessoas[i] = ptrpessoas[i-1];
        }
    }
    *size = *size + 1;
}

int main()
{
    Pessoa pessoas[10] = {
        {1, "nome"},
        {1, "invertido"}
    };
    printf("%d %s\n", pessoas[0].number, pessoas[0].name);

    int size = 2;
    InverteLista(pessoas, size);
    printf("%d %s\n", pessoas[0].number, pessoas[0].name);

    Pessoa p = {1, "ultimapos"};
    InsereUltimaPos(pessoas, p, &size);
    printf("%d %s\n", pessoas[2].number, pessoas[2].name);

    Pessoa p2 = {1, "primeirapos"};
    InserePrimeiraPos(pessoas, p2, &size);
    printf("%d %s\n", pessoas[0].number, pessoas[0].name);

    printf("\n");
    for (int i=0; i<size; i++) {
        printf("%d %s\n", pessoas[i].number, pessoas[i].name);
    }
}