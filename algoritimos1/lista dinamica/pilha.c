#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	no* topo;
	int quant;
}LD;

void define(LD *L){
	L->topo=NULL;
	L->quant=0;
}

int empilha(LD *L, int num){
	no *p;
	p=malloc(sizeof(no));
	p->chave=num;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
	return 1;
}

int desempilha(LD *L){
	int chave;
	no *p;
	p=L->topo;
	chave=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
	return chave;
}
	

int main(void){
	LD pilha;
	no *q;
	int aux;
	
	aux=empilha(&pilha,4);

	aux=desempilha(&pilha);
	printf("%d\n",aux);

return 0;
}	

