#include <stdio.h>
#include <stdlib.h>


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


int main(void){
	char frase[]="akila a baleia dos 7 mares .";
	ld pilha;
	int cont=0;
	char aux;

	define(&pilha);
	//scanf("%[^\n]",&frase);
	printf("%s\n",frase );

	while(frase[cont]!='.'){
		printf(" ");
		while(frase[cont]!=' '){
			empilha(&pilha,frase[cont]);
			cont++;
		}
		while(pilha.quant>0){
			aux=desempilha(&pilha);
			printf("%c",aux );
		}
		cont++;
	}

	return 0;
}