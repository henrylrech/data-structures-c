#include <stdio.h>

void ListaCartas(int cartas[9]) {
    for (int i=0; i<9; i++) {
        if (cartas[i] != 0) {
            printf("%d ", cartas[i]);
        }
    }
    printf("\n");
} 

void ListaCartasInvertida(int cartas[9]) {
    for (int i=8; i>=0; i--) {
        if (cartas[i] != 0) {
            printf("%d ", cartas[i]);
        }
    }
    printf("\n");
}

void RecebeCarta(int cartas[9], int nova) {
    if (cartas[8] != 0) {
        printf("voce possui 9 cartas e nao pode pegar mais\n");
        return;
    }

    if (nova < 1 || nova > 13) {
        printf("valor de carta nova invalido, deve estar entre 1 e 13\n");
        return;
    }

    int indice;
    for (int i=0; i<9; i++) {
        if (nova < cartas[i] || cartas[i] == 0) {
            indice = i;
            for (int j=9; j>i; j--) {
                cartas[j] = cartas[j-1];
            }
            break;
        }
    }
    cartas[indice] = nova;
}

int main() {
    //nao considerando naipes-
    int cartas[9] = {1,2,3,4,5,6,7,8};
    ListaCartas(cartas);
    RecebeCarta(cartas, 13);
    ListaCartas(cartas);
    RecebeCarta(cartas, 3);
    ListaCartas(cartas);
    RecebeCarta(cartas, 1);
    ListaCartasInvertida(cartas);
}
