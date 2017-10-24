#include <stdio.h>
#include<stdlib.h>

typedef struct  notag{
	int chave;
	struct notag *link;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;

void define(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

int insere(LD *L, int ch, int pos){
	int cont=0;
	no *q, *p;
	if(L->quant==0){
	p=malloc(sizeof(no));
	p->chave=ch;
	p->link=L->inicio;
	L->inicio=p;
	L->quant++;
	return 1;
	}
	p=L->inicio;
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=ch;
			q->link=p->link;
			p->link=q;
			L->quant++;
			return 1;
		}
		cont++;
		p=p->link;
	}
	return 0;
}
int apontafinal(LD *L){
	no *q;
	q=L->inicio;
	while(q->link!=NULL){
	q=q->link;
	}
	q->link=L->inicio;
	return 1;
}


int main(void){
	LD lista, *list, lista2;
	int cont;
	no q, *x;

	define(&lista);
	cont=insere(&lista,6,0);
	cont=insere(&lista,7,1);
	cont=insere(&lista,3,2);
	cont=insere(&lista,4,3);
	lista2.inicio=lista.inicio;
	cont=apontafinal(&lista2);

		x=lista.inicio;
	while(x!=NULL){
		printf("%d\n",x->chave);
		x=x->link;
	}
return 0;
}

