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

int testa_diagonal(ME *M,int linha, int coluna){
	no *q, *p;
	int i=1,j=1, aux=1;
	q=M->inicio;
	q=q->proxlinha;
	p=q->proxcoluna;
	while(q->linha<linha){
		while(p!=NULL){
			if(p->linha!=aux || p->coluna!=aux)
				return 0;
			else
				p=p->proxcoluna;
		}
		if(q->proxlinha!=NULL){
			aux++;
			q=q->proxlinha;
			p=q->proxcoluna;
		}
	}
	return 1;
	
}

int main(void){
	ME matriz, matriz2, matriz3, matriz4;
	int aux;
	no *q;
	define(&matriz,2,2);
	define(&matriz2,3,3);
	define(&matriz3,4,4);
	define(&matriz4,3,3);

	inserir(&matriz,1,1,2);
	inserir(&matriz,2,2,2);

	inserir(&matriz2,1,1,2);
	inserir(&matriz2,2,2,5);
	inserir(&matriz2,1,2,3);
	inserir(&matriz2,3,3,2);


	inserir(&matriz3,1,1,1);
	inserir(&matriz3,3,2,2);

	inserir(&matriz4,1,1,1);
	inserir(&matriz4,1,2,2);
	inserir(&matriz4,1,3,3);

	printmatriz(&matriz,2,2);
	printf("\n");
	printmatriz(&matriz2,3,3);
	printf("\n");
	printmatriz(&matriz3,4,4);
	printf("\n");
	printmatriz(&matriz4,3,3);


	/*aux=testa_diagonal(&matriz,2,2);
	printf("\n%d\n",aux);
	aux=testa_diagonal(&matriz2,3,3);
	printf("\n%d\n",aux );
	aux=testa_diagonal(&matriz3,4,4);
	printf("\n%d\n",aux);
	printf("\n");
*/
	return 0;
}