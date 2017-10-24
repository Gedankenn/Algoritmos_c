#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	struct notag *direita;
	struct notag *esquerda;
	int val;
}no;

typedef struct{
	no *inicio;
}arvore;

void define(arvore *A){
	A->inicio=NULL;
}



no* busca(no *q, int u){
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

void cria_arvore(arvore *A,int n, int dir, int qer){
	no *q;
	q=malloc(sizeof(no));
	if(A->inicio==NULL){
		q->val=n;
		q->direita=NULL;
		q->esquerda=NULL;
		A->inicio=q;
	}
	else{
		no *pdir=busca(A->inicio,dir);
		no *pqer=busca(A->inicio,qer);
		q->val = n;
		q->direita=pdir;
		q->esquerda=pqer;
		A->inicio=q;
	}
}

void imprime(no *A){
	if(A!=NULL){
		printf("%d\n",A->val );
		//printf("<\n");
		imprime(A->esquerda);
		//printf(">  \n");
		imprime(A->direita);
	}
}

no* desloca_arvore(no *A){
	if(A!=NULL){
		desloca_arvore(A->esquerda);
		desloca_arvore(A->direita);
		free(A);
	}
	return NULL;
}

void rotacao_direita(no *p){
	no *q, *aux;
	q=p->esquerda;
	aux = q->direita;
	q->direita=p;
	p->esquerda=aux;
}

void rotacao_esquerda(no *p){
	no *q, *aux;
	q=p->direita;
	aux=q->esquerda;
	q->esquerda=p;
	p->direita=aux;
}

int main(void){
	arvore A;
	no *q;
	define(&A);

	cria_arvore(&A,5,0,0);
	cria_arvore(&A,7,5,0);
	cria_arvore(&A,9,0,7);
	imprime(A.inicio);

	q=busca(A.inicio,7);
	printf("\n\n%d\n\n",q->val );
	rotacao_esquerda(q);
	imprime(A.inicio);




	return 0;
}