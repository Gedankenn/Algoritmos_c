#include <stdio.h>
#include <stdlib.h>
typedef struct notag{
		int num;
		struct notag *prox;
}no;

typedef struct{
	no *inicio;
}pulos;

void Define(pulos *P){
	P->inicio=NULL;
}

void insere(pulos *P, int n){
	no *q, *x;
	x=P->inicio;
	q=malloc(sizeof(no));
	q->num=n;

	if(x==NULL){
		P->inicio=q;
	}
	else{
		while(x->prox->num!=P->inicio->num){
			x=x->prox;
		}
		x->prox=q;
	}
	q->prox=P->inicio;
}

int percorre(pulos *P, int n, int salto){
	no *q;
	int cont=0;
	int cont2=0;
	q=P->inicio;
	while(cont<n){
		cont2=0;
		while(cont2<salto){
			q=q->prox;
			cont2++;
		}
		cont++;
	}
	return q->num;
}

int main(void){
	int cont=1;
	pulos P;
	Define(&P);

	while(cont<10){
		insere(&P,cont);
		cont++;
	}

	int num=percorre(&P,1000,4);
	printf("%d\n",num );
	return 0;
}