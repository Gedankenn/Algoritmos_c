#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct notagz{
	char chave[50];
	struct notagz *prox;
}noz;

typedef struct{
	noz* inicio;
	int quant;
}LDZ;

void define(LDZ *L){
	L->inicio=NULL;
	L->quant=0;
}

void inserechar(LDZ *L){
	noz *q, *p;
	q=L->inicio;
	if(L->inicio==NULL){
		p=malloc(sizeof(noz));
		L->inicio=p;
		scanf("%[^\n]",p->chave);
		getchar();
		L->quant++;
		p->prox=L->inicio;
	}
	else{
		while(q->prox!=L->inicio){
			q=q->prox;
		}
		p=malloc(sizeof(noz));
		q->prox=p;
		scanf("%[^\n]",p->chave);
		getchar();
		p->prox=L->inicio;
		L->quant++;
	}

}
LDZ sorteiaarrombado(LDZ *L, int num){
	noz *q, *p;
	q=L->inicio;
	int cont, cont2;
	for(cont=0;cont<MAX-1;cont++){
		q=L->inicio;
		/*if(num>=L->quant){
			num=num-((num/L->quant)*L->quant);
		}*/
		cont2=num;
		while(cont2>1){
			q=q->prox;
			cont2--;
		}
		if(q->prox==L->inicio){
			p=q->prox;
			q->prox=p->prox;
			free(p);
			L->quant--;
			L->inicio=q;
		}
		else{
			p=q->prox;
			q->prox=p->prox;
			free(p);
			L->quant--;
		}
	}
	return *L;
}

int main(void){
	LDZ lista, lista2;
	noz *p;
	int cont, num;
	define(&lista);
	define(&lista2);
	srand((unsigned)time(NULL));

	num=rand()%(15);
	
	printf("%d",num);
	for(cont=0;cont<MAX;cont++){
		inserechar(&lista);
	}
	lista2=sorteiaarrombado(&lista,num);
	p=lista2.inicio;
	printf("o sorteado foi\n%s\n",p->chave);
	

	return 0;
}