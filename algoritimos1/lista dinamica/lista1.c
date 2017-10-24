#include<stdio.h>
#include<stdlib.h>

typedef struct notag{
	int chave;
	struct notag *link;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;

void define(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

int inserePRIM(LD *L, int ch){
	no* p;
	p=malloc(sizeof(no));
	p->chave=ch;
	p->link=L->inicio;
	L->inicio=p;
	L->quant++;
	return 1;
}
int Busca(LD *L, int ch, no **p) {
    if (L->quant==0) return 0;
    else{
        *p = L->inicio;
        while (*p != NULL) {
            if ((*p)->chave==ch)
                return 1;
            else
                *p = (*p)->link;
        }
    }
    return 0;
}
void RemoverDepois(LD *L, no **q){
    no *p;
    p = (*q)->link;
    (*q)->link = p->link;
    free(p);
    L->quant--;
}
int insere(LD *L, int ch, int pos){
	int cont=0;
	no *q, *p;
	p=L->inicio;
/*	if(L->quant==0){
	p=malloc(sizeof(no));
	p->chave=ch;
	p->link=L->inicio;
	L->inicio=p;
	L->quant++;
	return 1;
	}*/
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=ch;
			q->link=p->link;
			p->link=q;
			L->quant++;
			return 1;
		}
		cont++;
		p=p->link;
	}
	return 0;
}

int removepos(LD *L, int pos){
	int cont=0;
	no *q, *p;
	p=L->inicio;
	while(p!=NULL){
		if(pos-1==cont){
			q=p->link;
			p->link=q->link;
			free(q);
			L->quant--;
			return 1;
		}
		cont++;
		p=p->link;
	}
	return 0;
}
int removechave(LD *L, int ch){
	no *p;
	p=L->inicio;
	while(p!=NULL){
	//printf("teste");
		if(p->link!=NULL && p->link->chave==ch){
			no *q=p->link;
			p->link=q->link;
			free(q);
			L->quant--;
			//return 1;
		} else {
			p=p->link;
		}
	}
	return 1;
}
int removeduplica(LD *L){
	no *p, *x;
	p=L->inicio;
	while(p!=NULL){
		x=p->link;
		while(x!=NULL){
			if(p->chave==x->chave){
				no *r;
				r=x->link;
				x->chave=x->link->chave;
				x->link=r->link;
				free(r);
			}
			else
				x=x->link;
		}
		p=p->link;
	}
	return 1;
}
			
	
int main(void){

	LD lista;
	int cont;
	no *x;

	define(&lista);
	cont=inserePRIM(&lista,4);
	if(cont==0) printf("insercao errada\n");

	//cont=busca(&lista,4,&q);
	if(cont==0) printf("busca nao encontrada\n");

	cont=insere(&lista,6,1);
	if(cont==0) printf("insere erro stupid coder\n");

	cont=insere(&lista,6,2);
	if(cont==0) printf("insere erro stupid coder\n");
	

	cont=insere(&lista,7,3);
	if(cont==0) printf("insere erro stupid coder\n");

	cont=insere(&lista,8,4);
	if(cont==0) printf("insere erro stupid coder\n");

	cont=insere(&lista,3,5);
	if(cont==0) printf("insere erro stupid coder\n");
	cont=insere(&lista,7,6);
	cont=insere(&lista,7,7);
	cont=insere(&lista,7,8);
	cont=insere(&lista,8,9);
	cont=insere(&lista,2,10);

	printf("lista inicio\n");
		x=lista.inicio;
		while(x!=NULL){
			printf("%d\n",x->chave);
			x=x->link;
		}
	
	//cont=removepos(&lista,2);
	//if(cont==0) printf("remove retornou erro\n");
	cont=removeduplica(&lista);
	printf("lista removida\n");
		x=lista.inicio;
		while(x!=NULL){	
			printf("%d\n",x->chave);
			x=x->link;
		}
	//cont=removechave(&lista,6);
	//if(cont==0) printf("removechave retornou erro\n");

	/*printf("lista removida2\n");
	x=lista.inicio;
	while(x!=NULL){
		printf("%d\n",x->chave);
		x=x->link;
	}
    */
return 0;
}
