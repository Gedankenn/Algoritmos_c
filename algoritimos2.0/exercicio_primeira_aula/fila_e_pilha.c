#include <stdio.h>

typedef struct notag{
	char chave;
	struct notag *prox;
}no;

typedef struct{
	no* topo;
	int quant;
}ld;

void define(ld *L){
	L->topo=NULL;
	L->quant=0;
}

void empilha(ld *L, char c){
	no *p;
	p=malloc(sizeof(no));
	p->chave=c;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
}

char desempilha(ld *L){
	char c;
	no *p;
	p=L->topo;
	c=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
	return c;
}

void insere_fila(ld *L, char num){
	no *q, *p;
	q=malloc(sizeof(no));
	if(L->quant==0){
		q->prox=L->topo;
		L->topo=q;
		q->chave=num;
		L->quant++;
	}
	else{
		p=L->topo;
		while(p->prox!=NULL){
			p=p->prox;
		}
		q->chave=num;
		q->prox=p->prox;
		p->prox=q;
		L->quant++;
	}
}

int main(void){
	
	return 0;
}