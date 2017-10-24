#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 4

typedef struct notag{
	int x, y;
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

void insere(LD *L, int a, int b){
	no *q, *p;
	q=L->inicio;
	if(L->inicio==NULL){
		p=malloc(sizeof(no));
		p->x=a;
		p->y=b;
		L->inicio=p;
		L->quant++;
		p->prox=L->inicio;
	}
	else{
		while(q->prox!=L->inicio){
			q=q->prox;
		}
		p=malloc(sizeof(no));
		p->x=a;
		p->y=b;
		q->prox=p;
		p->prox=L->inicio;
		L->quant++;
	}
}

float perimetro(LD *L){
	no *q, *p;
	float d=0;;//distancia

	q=L->inicio;
	while(q->prox!=L->inicio){
		p=q->prox;
		d=d+sqrt((p->x - q->x)*(p->x - q->x)+(p->y-q->y)*(p->y-q->y));
		q=q->prox;
	}
	p=q->prox;
	d=d+sqrt((p->x - q->x)*(p->x - q->x)+(p->y-q->y)*(p->y-q->y));

	return d;
}

int main(void){
	LD lista;
	float x, y, d;
	int aux=0;
	define(&lista);
	while(aux!=MAX){
		scanf("%f %f",&x,&y);
		insere(&lista,x,y);
		aux++;
	}
	d=perimetro(&lista);
	printf("o perimetro %f",d);

	return 0;
}