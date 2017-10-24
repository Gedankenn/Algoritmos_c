#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;

typedef struct{
	no* topo;
	int quant;
}PILHA;


void DefineS(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

void DefineP(PILHA *L){
	L->quant=0;
	L->topo=NULL;
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


void empilha(PILHA *L, int chave){
	no *p;
	p=malloc(sizeof(no));
	p->chave=chave;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
}

void desempilha(PILHA *L){
	int chave;
	no *p;
	p=L->topo;
	chave=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
}

int removelista(LD *L){
	no *q;
	int num;
	q=L->inicio;
	num=q->chave;
	L->quant--;
	L->inicio=q->prox;
	free(q);
	return num;
}

int main(void){
	int num;

	LD par, impar;
	PILHA alcalina;


	DefineS(&par);
	DefineS(&impar);
	DefineP(&alcalina);

	scanf("%d",&num);
	while(num!=0){
		if(num%2==0){
			inserefinal(&par,num);
		}
		else{
			inserefinal(&impar,num);
		}
		scanf("%d",&num);
	}

	while(impar.quant>0 || par.quant>0){
		if(impar.quant>0){
			num=removelista(&impar);
			if(num>0){
				empilha(&alcalina,num);
			}
			else
				desempilha(&alcalina);
		}
		if(par.quant>0){
			num=removelista(&par);
			if(num>0){
				empilha(&alcalina,num);
			}
			else
				desempilha(&alcalina);
		}
	}

	no *q;
	q=alcalina.topo;
	while(q!=NULL){
		printf("%d\n",q->chave);
		q=q->prox;
	}


	return 0;
}