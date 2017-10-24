#include <stdio.h>
#include <stdlib.h>


typedef struct noaresta{
	char arestas;
	struct noaresta *prox_aresta;
}aresta;


typedef struct notag{
	char vertice;
	struct notag *prox;
	aresta *prox_aresta;

}no;

typedef struct{
	no *inicio;
	int vertices;
	int arestas;
}grafo;

void define(grafo *G){
	G->inicio=NULL;
	G->vertices=0;
	G->arestas=0;
}

void insere_vertice(grafo *G, char vert){
	no *q;
	q=malloc(sizeof(no));
	q->vertice=vert;
	q->prox=NULL;
	q->prox_aresta=NULL;
	G->vertices++;
	if(G->inicio==NULL){
		G->inicio=q;
	}
	else{
		no *p;
		p=G->inicio;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=q;
	}
}

void insere_aresta(grafo *G, char A, char V){
	no *p;
	aresta *q, *aux;
	q=malloc(sizeof(aresta));
	p=G->inicio;
	q->arestas=A;
	q->prox_aresta=NULL;
	while(p->vertice!=V){
		p=p->prox;
	}
	aux=p->prox_aresta;
	if(aux!=NULL){
		while(aux->prox_aresta!=NULL){
			aux=aux->prox_aresta;
		}
		aux->prox_aresta=q;
		G->arestas++;
	}
	else{
		p->prox_aresta=q;
	}
}

void vizualiza(grafo *G){
	no *p;
	aresta *q;
	p=G->inicio;
	while(p!=NULL){
		printf("%c ",p->vertice );
		if(p->prox_aresta!=NULL){
			q=p->prox_aresta;
			while(q!=NULL){
				printf("--->%c ",q->arestas );
				q=q->prox_aresta;
			}
		}
		printf("/\n");
		p=p->prox;
	}
}

void remove_vertice(grafo *G, char V){
	no *p, *aux;
	aresta *q, *aux2;
	p=G->inicio;
	if(p->vertice==V){
		G->inicio=p->prox;
		p=G->inicio;
	}
	if(p->prox_aresta->arestas==V){
		aux2=p->prox_aresta;
		p->prox_aresta=aux2->prox_aresta;
		free(aux2);
	}
	while(p->prox!=NULL){
		if(p->prox->vertice==V){
			aux=p->prox;
			p->prox=aux->prox;
			free(aux);
		}
		else{
			if(p->prox_aresta!=NULL){
				q=p->prox_aresta;
				if(q->arestas==V){
					aux2=p->prox_aresta;
					p->prox_aresta=aux2->prox_aresta;
					free(aux2);
				}
				else{
					while(q->prox_aresta!=NULL){
						if(q->prox_aresta->arestas==V){
							aux2=q->prox_aresta;
							q->prox_aresta=aux2->prox_aresta;
							free(aux2);
						}
						else{
							q=q->prox_aresta;
						}
					}
				}
			}
		p=p->prox;
		}
	}
	if(p!=NULL){
		q=p->prox_aresta;
		if(q->arestas==V){
			p->prox_aresta=p->prox_aresta->prox_aresta;
		}
		else{
			while(q->prox_aresta!=NULL){
				if(q->prox_aresta->arestas==V){

					aux2=q->prox_aresta;
					q->prox_aresta=aux2->prox_aresta;
					free(aux2);
				}
				else{
					q=q->prox_aresta;
				}
			}
		}
	}
}

void remove_aresta(grafo *G, char A, char V){
	no *q;
	aresta *p;
	q=G->inicio;
	while(q->vertice!=V){
		q=q->prox;
	}
	p=q->prox_aresta;
	if(q->vertice==V && p->arestas==A){
		q->prox_aresta=q->prox_aresta->prox_aresta;
	}
	else{
		while(p->prox_aresta->arestas!=A){
			p=p->prox_aresta;
		}
		if(q->vertice==V && p->prox_aresta->arestas==A){
			p->prox_aresta=p->prox_aresta->prox_aresta;
		}
	}
}


int main(void){
	grafo G;
	define(&G);

	insere_vertice(&G,'a');
	insere_vertice(&G, 'b');
	insere_vertice(&G, 'c');
	insere_vertice(&G, 'd');
	insere_vertice(&G, 'e');

	insere_aresta(&G,'b','a');
	insere_aresta(&G,'c','a');

	insere_aresta(&G,'a','b');
	insere_aresta(&G,'c','b');
	insere_aresta(&G,'d','b');

	insere_aresta(&G,'a','c');
	insere_aresta(&G,'b','c');
	insere_aresta(&G,'d','c');
	insere_aresta(&G,'e','c');

	insere_aresta(&G,'b','d');
	insere_aresta(&G,'c','d');
	insere_aresta(&G,'e','d');

	insere_aresta(&G,'c','e');
	insere_aresta(&G,'d','e');	

	vizualiza(&G);

	remove_vertice(&G, 'd');


	printf("\n\n");
	vizualiza(&G);
	printf("\n");
	remove_aresta(&G,'c','e');
	vizualiza(&G);

	return 0;
}