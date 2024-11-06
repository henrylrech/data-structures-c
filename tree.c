#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noA{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

void posOrdem(TNoA* a){
  if (a!= NULL){
      posOrdem(a->esq);
      posOrdem(a->dir);
      printf("%c\n",a->info);
  }
}

void central(TNoA* a){
  if (a!= NULL){
      central(a->esq);
      printf("%c\n",a->info);
      central(a->dir);
  }
}

void preordem(TNoA* a){
  if (a!= NULL){
      printf("%c\n",a->info);
      preordem(a->esq);
      preordem(a->dir);
  }
}


TNoA *criaNo(char ch) {
  TNoA *novo;
  novo = (TNoA *) malloc(sizeof(TNoA));
  novo->info = ch;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

void acha_nodo(TNoA* nodo, char ch, char* pos) {
  if (nodo == NULL) {
    return;
  }
  if (nodo->info == ch) {
    printf("achou %c: caminho->%s\n", ch, pos);
    return;
  }
  char posEsq[100], posDir[100];
  strcpy(posEsq, pos);
  strcpy(posDir, pos);
  
  strcat(posEsq, "->esq");
  strcat(posDir, "->dir");
  
  acha_nodo(nodo->esq, ch, posEsq);
  acha_nodo(nodo->dir, ch, posDir);
}

int main(void) {
  TNoA *raiz;
  raiz = criaNo('A');
  raiz->esq = criaNo('B');
  raiz->dir = criaNo('C');
  raiz->dir->esq = criaNo('D');
  raiz->dir->dir = criaNo('E');
  acha_nodo(raiz, 'A', "raiz");
acha_nodo(raiz, 'B', "raiz");
acha_nodo(raiz, 'C', "raiz");
acha_nodo(raiz, 'D', "raiz");
  acha_nodo(raiz, 'E', "raiz");
};
