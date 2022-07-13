#include <stdio.h>
#include <stdlib.h>

typedef struct no{
		int elemento;
		struct no *prox;
} no;

void insere_inicio(no **topo, int ele){
	no *novo;
	novo = malloc(sizeof(no));
	novo -> elemento = ele;
	if(*topo == NULL){
		novo -> prox = NULL;
		*topo = novo;
	} else{
		novo -> prox = *topo;
		*topo = novo;
	}
}

no *retiraInicio(no *topo){
		if(topo -> prox == NULL){
		  printf("Lista ja esta vazia\n");
			return NULL;
	 }else{
		  no *aux = topo -> prox;
		  topo -> prox = aux -> prox;
			return aux;
		}
}

void imprimir(no *topo){
	no *aux;
	aux = topo;
	if(aux == NULL){
	} else{
			do {
				printf("%d\n", aux-> elemento );
				aux = aux -> prox;
			} while(aux != NULL);
	}
}

int main(){
	no *topo = NULL;

	insere_inicio(&topo, 1);
	insere_inicio(&topo, 2);
	insere_inicio(&topo, 3);
	insere_inicio(&topo, 4);
	insere_inicio(&topo, 5);

	imprimir(topo);

	topo = retiraInicio(topo);
	topo = retiraInicio(topo);


	imprimir(topo);

	return 0;
}
