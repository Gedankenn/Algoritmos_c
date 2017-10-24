#include <stdio.h>
#include <stdlib.h>


//talvez nao precisa deessa parte
/*typedef struct noaresta{
	int edge;
	struct noaresta *prox_aresta;
}aresta;*/


typedef struct novertice{
	int vert;
	struct novertice *prox_vertice;
	struct novertice *prox_aresta;
	//aresta *prox_aresta;
}vertice;

typedef struct{
	vertice *inicio;
	int vertices;
	int arestas;
}grafo;

void define(grafo *G){
	G->inicio=NULL;
	G->vertices=0;
	G->arestas=0;
}

void insere_vertice(grafo *G, int V){
	vertice *q;
	q=malloc(sizeof(vertice));
	q->vert=V;
	q->prox_vertice=NULL;
	q->prox_aresta=NULL;
	if(G->inicio==NULL){
		G->inicio=q;
	}
	else{
		vertice *p;
		p=G->inicio;
		while(p->prox_vertice!=NULL && p->vert!=V){
			p=p->prox_vertice;
		}
		if(p->prox_vertice==NULL){
			p->prox_vertice=q;
		}
	}
	G->vertices++;
}

void insere_aresta(grafo *G, int V, int A){
	vertice *q, *p, *x;
	p=G->inicio;
	x=G->inicio;
	while(p->prox_vertice!=NULL && p->vert!=V){
		p=p->prox_vertice;
	}
	while(x->prox_vertice!=NULL && x->vert!=A){
		x=x->prox_vertice;
	}
	if(p->vert==V && x->vert==A){
		q=malloc(sizeof(vertice));
		q->vert=A;
		q->prox_aresta=NULL;
		while(p->prox_aresta!=NULL && p->vert!=A){
			p=p->prox_aresta;
		}
		if(p->prox_aresta==NULL && p->vert!=A){
			p->prox_aresta=q;
			G->arestas++;
		}
	}
	else{
		printf("Vertice ou Aresta invalido: \n");
	}
}

vertice* busca_vertice(grafo *G, int V){
	vertice *q;
	q=G->inicio;
	if(q->vert==V){
		return q;
	}
	else{
		while(q!=NULL){
			if(q->vert==V){
				return q;
			}
			q=q->prox_vertice;
		}
	}
	return NULL;
}

void remove_aresta(grafo *G, int V, int A){
	vertice *q, *p, *aux;
	p=busca_vertice(G,V);
	q=NULL;
	if(p!=NULL){
		q=p->prox_aresta;
	}
	aux=NULL;
	while(q!=NULL && q->vert!=A){
		aux=q;
		q=q->prox_aresta;
	}
	if(q!=NULL && q->vert==A){
		if(aux!=NULL){
			aux->prox_aresta=q->prox_aresta;
			free(q);
		}
		else{
			p->prox_aresta=q->prox_aresta;
			free(q);
		}
		G->arestas--;
	}
	else{
		printf("nao existe este vertice ou aresta: \n");
	}
}

void remove_vertice(grafo *G, int V){
	vertice *q, *p, *aux;
	q=busca_vertice(G,V);
	if(q!=NULL){
		p=q->prox_aresta;
		while(p!=NULL){
			remove_aresta(G,p->vert,V);
			p=p->prox_aresta;
		}
		q=G->inicio;
		if(q->vert==V){
			G->inicio=q->prox_vertice;
			free(q);
		}
		else{
			while(q->prox_vertice!=NULL && q->prox_vertice->vert!=V){
				q=q->prox_vertice;
			}
			if(q->prox_vertice->vert==V){
				aux=q->prox_vertice;
				q->prox_vertice=q->prox_vertice->prox_vertice;
				free(aux);
			}
		}
		G->vertices--;
	}
	else{
		printf("nao foi possivel remover: \n");
	}
}

void imprime_grafo(grafo *G){
	vertice *q, *p;
	q=G->inicio;
	while(q!=NULL){
		printf("|%d|-> ",q->vert );
		p=q->prox_aresta;
		while(p!=NULL){
			printf("%d, ",p->vert );
			p=p->prox_aresta;
		}
		printf("\n");
		q=q->prox_vertice;
	}
}

void enfila(grafo *L, int V){
	vertice *p;
	p=malloc(sizeof(vertice));
	p->vert=V;
	if(L->inicio==NULL){
		L->inicio=p;
	}
	else{
		vertice *q;
		q=L->inicio;
		while(q->prox_vertice!=NULL){
			q=q->prox_vertice;
		}
		q->prox_vertice=p;
	}
}

vertice* desenfila(grafo *L){
	vertice *q;
	q=L->inicio;
	L->inicio=q->prox_vertice;
	return q;
}

void busca_em_largura(grafo *G,int V, int *pai, int *d, int *cor){
	if(busca_vertice(G,V)!=NULL){
		vertice *q;
		grafo L;

		define(&L);
		//inicializa
		q=G->inicio;
		int cont=0;
		while(q!=NULL){
			pai[q->vert]=-1;
			d[q->vert]=0;
			cor[q->vert]=0;
			
			q=q->prox_vertice;
		}
		d[V]=0;
		cor[V]=1;

		define(&L);
		enfila(&L,V);

		vertice *u;
		vertice *aux;
		while(L.inicio!=NULL){
			u=desenfila(&L);

			aux=u->prox_aresta;

			while(aux!=NULL){
				if(cor[aux->vert]==0){
					cor[aux->vert]=1;
					d[aux->vert]=d[u->vert]+1;
					pai[aux->vert]=u->vert;
				}
				enfila(&L,aux->vert);
				aux=aux->prox_aresta;
			}
			cor[u->vert]=2;
		}
	}
	else{
		printf("vertice invalido\n");
	}
}

int main(void){
	grafo G;
	int menu=1;
	define(&G);

	while(menu!=0){
		printf("\n");
		printf("---------------------------------------------------\n");
		printf("1->visualiza grafo   |\n");
		printf("2->insere vertice    |\n");
		printf("3->insere aresta     |\n");
		printf("4->remove vertice    |\n");
		printf("5->remove aresta     |\n");
		printf("6->busca em largura  |\n");

		printf("0->      sair     |\n");
		printf("---------------------------------------------------\n");

		scanf("%d",&menu);

		if(menu==1){
			imprime_grafo(&G);
		}

		if(menu==2){
			int V;
			printf("ensira vertice que deseja(-1 para sair): \n");
			scanf("%d",&V);
			while(V !=-1){
				insere_vertice(&G, V);
				scanf(" %d",&V);
			}
		}

		if(menu==3){
			int V, A;
			printf("ensira aresta e vertice a que deseja('-1'para sair): \n");
			scanf("%d %d",&A,&V);
			while(V!=-1){
				insere_aresta(&G,V,A);
				insere_aresta(&G,A,V);
				scanf("%d %d",&A,&V);
			}
		}

		if(menu==4){
			int V;
			printf("ensira vertice que deseja remmover('-1'para sair): \n");
			scanf("%d",&V);
			while(V!=-1){
				remove_vertice(&G,V);
				scanf("%d",&V);
			}
		}

		if(menu==5){
			int V, A;
			printf("ensira aresta e vertice de que deseja remover('-1'para sair): \n");
			scanf("%d %d",&A, &V);
			while(V!=-1){
				remove_aresta(&G,V,A);
				remove_aresta(&G,A,V);
				scanf("%d %d",&A,&V);
			}
		}

		if(menu==6){
			int pai[G.vertices], d[G.vertices], cor[G.vertices];
			printf("ensira vertice que deseja fazer busca em largura: \n");
			int V;
			scanf("%d",&V);
			while(V!=-1){
				busca_em_largura(&G,V,pai,d,cor);
				int cont;
				for(cont=0;cont<G.vertices;cont++){
					printf("vertice: %d|pai: %d|distancia: %d|\n",cont,pai[cont],d[cont] );
				}
				scanf("%d",&V);
			}
		}
	}
}