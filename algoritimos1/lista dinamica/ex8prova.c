#include <stdio.h>
#include <stdlib.h>
#define MAX 13

typedef struct notag{
	char chave;
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

void empilha(LD *L, char ch){
	no *p;
	p=malloc(sizeof(no));
	p->chave=ch;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
}

char desempilha(LD *L){
	char chave;
	no *p;
	p=L->topo;
	chave=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
	return chave;
}

int main(void){
	int cont=0, id=1;
	char ch[20];
	LD lista;
	define(&lista);
	scanf("%s",ch);
	while(ch[cont]!='C'){
		empilha(&lista,ch[cont]);
		cont++;
	}
	cont++;
	while(ch[cont]!='\0'){
		if(desempilha(&lista)!=ch[cont])
			id=0;

		cont++;
	}

	if(id!=0){
		printf("as strings sao iguais\n");
	}
	else
		printf("nao sao\n");

	return 0;
}