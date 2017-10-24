#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	int quant;
	no* inicio;
}LD;

void define(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

int insere(LD *L, int num){
	no *q, *p;
	q=malloc(sizeof(no));
	if(L->quant==0){
		q->prox=L->inicio;	
		L->inicio=q;
		q->chave=num;
		L->quant++;
		return 1;
	}
	p=L->inicio;
	while(p->prox!=NULL){
		p=p->prox;
	}
	q->chave=num;
	q->prox=p->prox;
	p->prox=q;
	L->quant++;
	return 1;
}

int removefila(LD *L){
	no *q;
	q=L->inicio;
	L->inicio=q->prox;
	free(q);
	L->quant--;
	return 1;
}
	
	


int main(void){
	LD fila;
	no *q;
	int aux;

	define(&fila);
	aux=insere(&fila,3);
	aux=removefila(&fila);
	q=fila.inicio;
	printf("%d\n",q->chave);

return 0;
}	
