#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	int linha;
	int coluna;
	int valor;
	struct notag *proxlinha;
	struct notag *proxcoluna;
}no;

typedef struct{
	no *inicio;
	int tamlinha;
	int tamcoluna;
}ME;

void define(ME *M, int linha, int coluna){
	no *aux;
	aux = malloc(sizeof(no));
	aux->linha=0;
	aux->coluna=0;
	aux->valor=0;
	aux->proxlinha=NULL;
	aux->proxcoluna=NULL;
	M->inicio = aux;
	M->tamlinha=linha;
	M->tamcoluna=coluna;

	int auxlinha=1, auxcoluna=1;
	no *p, *q;
	q=M->inicio;

	while(auxlinha<=linha){
		p=malloc(sizeof(no));
		p->linha=auxlinha;
		p->coluna=0;
		p->valor=0;
		auxlinha++;
		p->proxcoluna=NULL;
		p->proxlinha=NULL;
		q->proxlinha=p;
		q=q->proxlinha;
	}
	q=M->inicio;
	while(auxcoluna<=coluna){
		p=malloc(sizeof(no));
		p->coluna=auxcoluna;
		p->linha=0;
		p->valor=0;
		p->proxlinha=NULL;
		p->proxcoluna=NULL;
		auxcoluna++;
		q->proxcoluna=p;
		q=q->proxcoluna;
	}


}

void inserir(ME *M, int linha, int coluna, int num){
	no *q, *p, *x;
	p=M->inicio;
	x=M->inicio;

	while(p->coluna < coluna){
		p=p->proxcoluna;
	}
	while(p->linha < linha && p->proxlinha!=NULL){
		p=p->proxlinha;
	}
	while(x->linha < linha){
		x=x->proxlinha;
	}
	while(x->coluna < coluna && x->proxcoluna!=NULL){
		x=x->proxcoluna;
	}
	if(p->linha==linha && x->coluna==coluna){
		p->valor=num;
	}
	else{
		q=malloc(sizeof(no));
		q->valor=num;
		q->linha=linha;
		q->coluna=coluna;
		q->proxlinha=p->proxlinha;
		p->proxlinha=q;
		q->proxcoluna=x->proxcoluna;
		x->proxcoluna=q;
	}
}

no* busca(ME *M, int num){
	no *q, *p;

	q=M->inicio;
	p=M->inicio;
	while(q!=NULL){
		while(p!=NULL){
			if(p->valor==num){
				return p;
			}
			p=p->proxcoluna;
		}
		q=q->proxlinha;
		p=q;
	}
	return NULL;
}

no* buscaparametro(ME *M, int linha, int coluna){
	no *p, *x;
	p=M->inicio;
	x=M->inicio;

	while(p->coluna < coluna){
		p=p->proxcoluna;
	}
	while(p->linha < linha && p->proxlinha!=NULL){
		p=p->proxlinha;
	}
	while(x->linha < linha){
		x=x->proxlinha;
	}
	while(x->coluna < coluna && x->proxcoluna!=NULL){
		x=x->proxcoluna;
	}
	if(p->linha==linha && x->coluna==coluna){
		return p;
	}	
	return NULL;
}
void printmatriz(ME *M,int linha, int coluna){
	no *q, *p;
	int i=1,j=1;
	q=M->inicio;
	q=q->proxlinha;
	p=q->proxcoluna;
	for(i=1;i<=linha;i++){
		for(j=1;j<=coluna;j++){
			if(p!=NULL){
				if(p->coluna==j && p->linha == i){
					printf("%d ",p->valor);
					p=p->proxcoluna;
				}
				else
					printf("0 ");
			}
			else
				printf("0 ");
		}
		printf("\n");
		if(q->proxlinha!=NULL){
			q=q->proxlinha;
			p=q->proxcoluna;
		}
	}
}

void remover(ME *M, int linha, int coluna){
	no *p, *x, *q;
	p=M->inicio;
	x=M->inicio;

	while(p->coluna < coluna){
		p=p->proxcoluna;
	}
	while(p->proxlinha->linha < linha && p->proxlinha!=NULL){
		p=p->proxlinha;
	}
	while(x->linha < linha){
		x=x->proxlinha;
	}
	while(x->proxcoluna->coluna < coluna && x->proxcoluna!=NULL){
		x=x->proxcoluna;
	}
	if(p->proxlinha->linha==linha && x->proxcoluna->coluna==coluna){
		q=p->proxlinha;
		p->proxlinha=q->proxlinha;
		x->proxcoluna=q->proxcoluna;
		free(q);
	}
	else{
		printf("\nvalor nao pertencente a matriz\n");
	}
}

void somamatriz(ME *M, ME *M2, ME *M3){
	
	
		no *l1, *l2, *q, *c, *c2;

		l1=M->inicio;
		l2=M2->inicio;
		l1=l1->proxlinha;
		c=l1->proxcoluna;
		l2=l2->proxlinha;
		c2=l2->proxcoluna;
		
		while(l1!=NULL){
			if(c!=NULL){
				inserir(M3,c->linha,c->coluna,c->valor);
				c=c->proxcoluna;
			}
			else{
				l1=l1->proxlinha;
				if(l1!=NULL)
				c=l1->proxcoluna;
			}
		}
		
		while(l2!=NULL){
			if(c2!=NULL){
				q=buscaparametro(M3,c2->linha,c2->coluna);
				if(q!=NULL){
					q->valor=(c2->valor)+(q->valor);
				}
				else{
					inserir(M3,c2->linha,c2->coluna,c2->valor);
				}
				c2=c2->proxcoluna;
			}
			else{
				l2=l2->proxlinha;
				if(l2!=NULL)
					c2=l2->proxcoluna;
			}
		}
	}

void multiplicaSenhor(ME *M, ME *M2, ME *M3){
	no *l1, *l2, *q, *c1, *c2;
	int x;
	l1=M->inicio;
	l2=M2->inicio;
	l1=l1->proxlinha;
	c1=l1->proxcoluna;
	l2=l2->proxlinha;
	c2=l2->proxcoluna;

	while(l1!=NULL && l2!=NULL){
		if(c1!=NULL && c2!=NULL){
			if(c1->linha==c2->linha && c1->coluna==c2->coluna){
				x=(c1->valor) * (c2->valor);
				inserir(M3,c1->linha,c2->coluna,x);
				c1=c1->proxcoluna;
				c2=c2->proxcoluna;
			}
			else{
				if(c1->coluna<c2->coluna){
					c1=c1->proxcoluna;
				}
				else
					c2=c2->proxcoluna;
			}
		}
		else{
			l1=l1->proxlinha;
			if(l1!=NULL)
			c1=l1->proxcoluna;
			l2=l2->proxlinha;
			if(l2!=NULL)
			c2=l2->proxcoluna;
		}
	}
}

int main(void){
	ME matriz, matriz2, matriz3, matriz4;
	no *q;
	define(&matriz,3,3);
	define(&matriz2,3,3);
	define(&matriz3,3,3);
	define(&matriz4,3,3);

	inserir(&matriz,2,2,5);
	inserir(&matriz,3,3,8);
	inserir(&matriz2,1,1,3);
	inserir(&matriz2,2,2,3);

	printmatriz(&matriz,3,3);
	printf("\n");
	printmatriz(&matriz2,3,3);

	somamatriz(&matriz,&matriz2,&matriz3);
	printf("\n");
	//q=buscaparametro(&matriz2,1,1);
	//printf("%d ",q->valor);
	printmatriz(&matriz3,3,3);
	printf("\n");
	multiplicaSenhor(&matriz,&matriz2,&matriz4);
	printmatriz(&matriz4,3,3);
	return 0;
}