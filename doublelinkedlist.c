#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char *nome;
    float nota;
    struct aluno *ant;
    struct aluno *prox;
};
typedef struct aluno Aluno;

void insere_ordenado(Aluno **inicio, char *nome, float nota){
	Aluno *novo,*anterior,*aux=*inicio;
	novo = (Aluno*) malloc(sizeof(Aluno));
    novo->nome = nome;
	novo->nota = nota;
	novo->prox = NULL;
	novo->ant = NULL;

	if(*inicio==NULL) //insere o primeiro e único da lista
		*inicio = novo;
	else{
		if(nota<=(*inicio)->nota){ //insere na frente
			novo->prox=*inicio;
			(*inicio)->ant=novo;
			*inicio=novo;
		}
		else{
			while (aux!=NULL && aux->nota<nota ){
					anterior=aux;
					aux=aux->prox;
			}
			if(aux==NULL){
				anterior->prox=novo;
				novo->ant=anterior;
			}
			else{
				novo->prox=aux;
				novo->ant=aux->ant;
				(aux->ant)->prox=novo;
				aux->ant=novo;
			}			
		}
	}	
}

void remove_aluno(Aluno **inicio, char *nome) {
    Aluno *aux = *inicio;

    if(*inicio==NULL) //insere o primeiro e único da lista
		return;
	else {
		while (aux!=NULL){
			if (aux->nome == nome) {
                if (aux->prox != NULL) {
                    aux->prox->ant = aux->ant;
                }

                if (aux->ant != NULL) {
                    aux->ant->prox = aux->prox;
                }
                free(aux);
                printf("removido aluno %s\n", nome);
                return;
            }
			aux=aux->prox;
        }	
	}
}

void escreve(Aluno **inicio){
	Aluno *aux= *inicio;
	
	printf("Lista:\n");
	while(aux!=NULL){
		printf("%s %.1f - ",aux->nome, aux->nota);
		aux=aux->prox;
	}
    printf("\n");
}

void escreveAcima(Aluno **inicio){
	Aluno *aux= *inicio;
	
	printf("Acima:\n");
	while(aux!=NULL){
        if (aux->nota >= 7) {
            printf("%s %.1f - ",aux->nome, aux->nota);
        }
		aux=aux->prox;
	}
    printf("\n");
}

void escreveMedia(Aluno **inicio){
	Aluno *aux= *inicio;

    double media;
    int cont = 0;
	
	printf("Media:\n");
	while(aux!=NULL){
        media = media + aux->nota;
        cont++;
		aux=aux->prox;
	}

    printf("%.4f", media / cont);
    printf("\n");
}

int main() {
    Aluno *inicio = NULL;
    insere_ordenado(&inicio, "pedro", 2.2);
    escreve(&inicio);
    insere_ordenado(&inicio, "paulo", 7.1);
    escreve(&inicio);
    insere_ordenado(&inicio, "paula", 3.1);
    escreve(&inicio);
    insere_ordenado(&inicio, "paola", 10);
    escreve(&inicio);
    remove_aluno(&inicio, "paulo");
    escreve(&inicio);
    escreveAcima(&inicio);
    escreveMedia(&inicio);
}