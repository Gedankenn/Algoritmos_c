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

void encontra(ME *M, int *maior, int *menor){
	no *p, *q;
	p=M->inicio;
	p=p->proxlinha;
	*maior=-999999;
	*menor=999999;
	int cont=0;
	q=p->proxcoluna;
	do{
		do{
			if(*maior<q->valor)
				*maior=q->valor;

			if(*menor>q->valor)
				*menor=q->valor;

		q=q->proxcoluna;
		//printf("%d\n",cont++ );
		}while(q!=NULL);
		p=p->proxlinha;
		if(p!=NULL)
			q=p->proxcoluna;
		
	}while(p!=NULL);
}

int main(void){
	ME matriz;
	no *q;
	int maior, menor;

	define(&matriz,3,3);

	inserir(&matriz,1,1,5);
	inserir(&matriz,1,2,3);
	inserir(&matriz,1,3,8);
	inserir(&matriz,2,1,1);
	inserir(&matriz,2,2,4);
	inserir(&matriz,2,3,6);
	inserir(&matriz,3,1,5);
	inserir(&matriz,3,2,9);
	inserir(&matriz,3,3,15);

	printmatriz(&matriz,3,3);

	encontra(&matriz,&maior,&menor);
	printf("%d  ||  %d\n",maior,menor);


	return 0;
}