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

int gasto(int posicao){
	int grana;
	grana=posicao + (posicao-1);
	return grana;
}

void inserefinal(LD *L, int ch){
	no *q, *p;
	q=L->inicio;
	if(q==NULL){
		p=malloc(sizeof(no));
		p->chave=ch;
		p->prox=NULL;
		L->inicio=p;
		L->quant++;
	}
	else{
		while(q->prox!=NULL){
			q=q->prox;
		}
		p=malloc(sizeof(no));
		q->prox=p;
		p->chave=ch;
		L->quant++;
		p->prox=NULL;
	}
}

void removefila(LD *L){
	no *q;
	q=L->inicio;
	L->inicio=q->prox;
	free(q);
	L->quant--;
}

int main(void){
	int posicao, media=0, aux;
	no *p;
	LD lista;

	define(&lista);

	for(posicao=0;posicao<10;posicao++){
		aux=gasto(posicao);
		media=media+aux;
	}
	printf("%d",media);
	media=media/posicao;
	printf("a media e de: %d\n",media);

}