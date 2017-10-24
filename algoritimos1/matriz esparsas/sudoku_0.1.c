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

void sudoku(ME *M,int linha, int coluna){
	no *q, *auxlinha, *auxcoluna, *valorinserir;
	int i=1, j=1, valores[27], cont=0, cont2=0;
	q=M->inicio;

	
	while(i<=linha){
		q=q->proxlinha;
		auxcoluna=q->proxcoluna;
		auxlinha=q->proxcoluna;

		for(cont=0;cont<27;cont++){
			valores[cont]=0;
		}
		cont=0;
		cont2=1;
		while(auxcoluna!=NULL){
			valores[cont]=auxcoluna->valor;
			cont++;
			auxcoluna=auxcoluna->proxcoluna;			
		}
		while(j<=coluna){
			while(auxlinha!=NULL){
				valores[cont]=auxlinha->valor;
				auxlinha=auxlinha->proxlinha;
				cont++;
			}
			if((j+2)%3==0 && (i+2)%3==0){
				no *y, *u;
				u=buscaparametro(M,i,j);
				y=buscaparametro(M,i,j);
				while(y->linha<(i+3) && y!=NULL){
					while(u->coluna<(j+3) && u!=NULL){
						valores[cont]=u->valor;
						cont++;
						u=u->proxcoluna;
					}
					y=y->proxlinha;
				}
			}
			valorinserir=buscaparametro(M,i,j);
			if(valorinserir == NULL){
				cont2=1;
				while(cont2 == valores[0] || cont2==valores[1] || cont2==valores[2]	|| cont2==valores[3] || cont2==valores[4] || cont2==valores[5] || cont2==valores[6] || cont2==valores[7] || cont2==valores[8] || cont2==valores[9] || cont2==valores[10] || cont2==valores[11] || cont2==valores[12] || cont2==valores[13] || cont2==valores[14] || cont2==valores[15] || cont2==valores[16] || cont2==valores[16] || cont2==valores[17] || cont2==valores[18] || cont2==valores[19] || cont2==valores[20] || cont2==valores[21] || cont2==valores[22] || cont2==valores[23] || cont2==valores[24] || cont2==valores[25] || cont2==valores[26]){
					cont2++;
				}
				inserir(M,i,j,cont2);
				valores[cont]=cont2;
			}
			j++;
		}
		i++;
	}
}

int main(void){
	ME matriz;

	define(&matriz,3,3);

	inserir(&matriz,1,1,5);
	inserir(&matriz,1,2,3);
	inserir(&matriz,2,1,6);
	inserir(&matriz,3,2,9);
	inserir(&matriz,3,3,8);

	printmatriz(&matriz,3,3);


	return 0;
}