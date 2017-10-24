#include<stdio.h>
#include<stdlib.h>

typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;

void define(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

LD merge(LD *L, LD *L2){
	no *p, *q, *maior;
	LD L3;
	if(L->quant>=L2->quant){
		maior=L->inicio;
		p=L2->inicio;
	}
	else{
		maior=L2->inicio;
		p=L->inicio;
	}
	q=malloc(sizeof(no));
	L3.inicio=q;
	L3.quant=0;
	while(maior!=NULL){
		q->chave=maior->chave;
		q->prox=malloc(sizeof(no));
		q=q->prox;
		maior=maior->prox;
		if(p!=NULL){
			q->chave=p->chave;
			p=p->prox;
			q->prox=malloc(sizeof(no));
			q=q->prox;
		}
	}
	q=NULL;
	return L3;
}
int insere(LD *L, int ch, int pos){
	int cont=0;
	no *q, *p;
	p=L->inicio;
	if(L->quant==0){
	q=malloc(sizeof(no));
	q->chave=ch;
	q->prox=NULL;
	L->inicio=q;
	L->quant++;
	return 1;
	}
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=ch;
			q->prox=p->prox;
			p->prox=q;
			L->quant++;
			return 1;
		}
		cont++;
		p=p->prox;
	}
	return 0;
}
void transformacircular(LD *L){
	no *q;
	q=L->inicio;
	while(q->prox!=NULL){
		q=q->prox;
	}
	q->prox=L->inicio;
}


int main(void){
	int cont;
	LD lista1, lista2, lista3;
	no *x;
	define(&lista1);
	define(&lista2);

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
		while(x!=NULL){	
			printf("%d\n",x->chave);
			x=x->prox;
		}


	return 0;
}