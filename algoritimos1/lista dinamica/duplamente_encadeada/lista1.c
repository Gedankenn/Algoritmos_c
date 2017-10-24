# include<stdio.h>
#include<stdlib.h>

typedef struct notag{
	int chave;
	struct	notag *prox;
	struct	notag *ant;
}no;

typedef struct{
	no *inicio;
	no *fim;
	int quant;
}LD;

void Definir(LD *L){
	L->quant==0;
	L->inicio==NULL;
	L->fim==NULL;
}

int inserir(LD *L, int num){
	no *q, *p;
	p=L->inicio;
	if(L->quant==0){
		q=malloc(sizeof(no));
		q->chave=num;
		q->prox=NULL;
		q->ant=NULL;
		L->inicio=q;
		L->quant++;
		L->fim=q;
		return 1;
	}
	while(p->prox!=NULL){
	p=p->prox;
	}
	q=malloc(sizeof(no));
	q->chave=num;
	q->prox=NULL;
	p->prox=q;
	q->ant=p;
	L->fim=q;
	return 1;
}

int inserirposicao(LD *L, int num, int pos){
	int cont;
	no *q, *p;
	p=L->inicio;
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=num;
			q->ant=p;
			q->prox=p->prox;
			p->prox->ant=q;
			p->prox=q;
			L->quant++;
			return 1;
			}
		cont++;
		p=p->prox;
	}
return 0;
}

no* busca(LD *L, int num){
	no *q;
	q=L->inicio;
	while(q!=NULL){
		if(q->chave==num){
			return q;
		}
	q=q->prox;
	}
printf("nao encontrou o indigente\n");
return NULL;
}

int remover(LD *L, int num){
	no *p;
	p=busca(L, num);
	if(p->prox==NULL){
		L->fim=p->ant;
	}
	if(p->ant==NULL){
		L->inicio=p->prox;
	}
	p->ant->prox=p->prox;
	p->prox->ant=p->ant;
	L->quant--;
	return 1;
}		


int main(void){
	LD lista;
	no *p;
	int cont;
	cont=inserir(&lista, 4);
	cont=inserir(&lista, 2);
	cont=inserir(&lista, 5);
	cont=inserirposicao(&lista, 8, 2);
	cont=remover(&lista,8);
	p=lista.inicio;
		while(p!=NULL){
			printf("%d\n",p->chave);
			p=p->prox;
		}


return 0;
}
