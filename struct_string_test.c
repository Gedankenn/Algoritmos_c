#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct notag{
	char *nome;
	struct notag *prox;
}no;

typedef struct{
	no *inicio;
}nomes;

void Define(nomes *N){
	N->inicio=NULL;
}

void insere_nome(nomes *N, char *c){
	no *q;
	q=malloc(sizeof(no));
	q->nome=malloc(10*sizeof(char));
	int cont=0;
	q=N->inicio;
	printf("teste\n");
	if(q==NULL){
		strcpy(q->nome,c);
		N->inicio=q;
		q->prox=NULL;
	}
	else{
		while(q->prox!=NULL){
			q=q->prox;
		}
		no *x;
		x=malloc(sizeof(no));
		while(c[cont]!=' '){
			x->nome[cont]=c[cont];
			cont++;
		}
		q->prox=x;
		x->prox=NULL;
	}
	printf("teste2\n");
}

int main(void){
	nomes lista;
	char c[]="fabio";

	Define(&lista);

	insere_nome(&lista,c);

	printf("%s\n",lista.inicio->nome );

	return 0;
}