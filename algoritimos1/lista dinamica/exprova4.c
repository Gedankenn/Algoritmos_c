#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int main(void){
	int cont;
	LD lista1, lista2;
	no *x, *q;
	DefineS(&lista1);
	DefineS(&lista2);

	cont=insere(&lista1,3,1);
	cont=insere(&lista1,6,1);
	cont=insere(&lista1,5,2);
	cont=insere(&lista1,10,3);
	cont=insere(&lista1,7,4);
	cont=insere(&lista1,2,5);
	cont=insere(&lista1,3,6);
	cont=insere(&lista1,4,7);
	cont=insere(&lista1,9,8);


	transformacircular(&lista1);
	x=lista1.inicio;
	do{
		printf("%d- ",x->chave);
		x=x->prox;
	}while(x!=lista1.inicio);
	printf("\n");

	SeparaCircular(&lista1,&lista2);
	transformacircular(&lista2);

	x=lista1.inicio;
	q=lista2.inicio;
	do{
		printf("%d ",x->chave);
		x=x->prox;
	}while(x!=lista1.inicio);
	printf("\n");
	do{
		printf("%d ",q->chave);
		q=q->prox;
	}while(q!=lista2.inicio);


	return 0;
}