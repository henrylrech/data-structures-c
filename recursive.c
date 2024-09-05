#include <stdio.h>

void imprime(int v[], int i) {
    if (i < 5) {
        printf("%d\n", v[i]);
        imprime(v, i+1);
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    imprime(v, 0);
}