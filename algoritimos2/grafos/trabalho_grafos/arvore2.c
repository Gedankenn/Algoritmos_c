#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	struct arv *direita;
	struct arv *esquerda;
	int val;
}Arv;


void define(void){
	return NULL;
}



Arv* busca(Arv *q, int u){
	if(q!=NULL){
		if(q->val==u)
			return q;
		else if(busca(q->esquerda,u))
			return q->esquerda;
		else
			return (busca(q->direita,u));
	}
	else
		return NULL;
}

void cria_arvore(Arv *A,int n, int dir, int qer){
	Arv *q;
	q=malloc(sizeof(Arv));
	Arv *pdir=busca(A,dir);
	Arv *pqer=busca(A,qer);
	q->val=n;
	q->direita=pdir;
	q->esquerda=pqer;
	
}

void imprime(Arv *A){
	if(A!=NULL){
		printf("%d\n",A->val );
		imprime(A->esquerda);
		imprime(A->direita);
	}
}

void desloca_arvore(Arv *A){
	if(A!=NULL){
		desloca_arvore(A->esquerda);
		desloca_arvore(A->direita);
		free(A);
	}
}

void rotacao_direita(Arv *p){
	Arv *q, *aux;
	q=p->esquerda;
	aux = q->direita;
	q->direita=p;
	p->esquerda=aux;
}

void rotacao_esquerda(Arv *p){
	Arv *q, *aux;
	q=p->direita;
	aux=q->esquerda;
	q->esquerda=p;
	p->direita=aux;
}

int main(void){
	Arv A;
	Arv *q;
	define(&A);

	cria_arvore(&A,5,0,0);
	cria_arvore(&A,7,5,0);
	imprime(&A);




	return 0;
}