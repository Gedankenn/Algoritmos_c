#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void){
	int cont;
	LD lista1, lista2, lista3;
	no *x;
	DefineS(&lista1);
	DefineS(&lista2);

	cont=insere(&lista1,1,1);
	cont=insere(&lista1,5,1);
	cont=insere(&lista1,7,2);
	cont=insere(&lista1,3,3);
	cont=insere(&lista1,9,4);

	cont=insere(&lista2,1,1);
	cont=insere(&lista2,6,1);
	cont=insere(&lista2,5,2);
	cont=insere(&lista2,10,3);
	cont=insere(&lista2,7,4);
	cont=insere(&lista2,2,5);
	cont=insere(&lista2,3,6);
	cont=insere(&lista2,4,7);
	cont=insere(&lista2,9,8);

	lista3=merge(&lista1,&lista2);
	transformacircular(&lista1);


		x=lista1.inicio;
		do{
			printf("%d\n",x->chave);
			x=x->prox;
		}while(x!=lista1.inicio);


	return 0;
}