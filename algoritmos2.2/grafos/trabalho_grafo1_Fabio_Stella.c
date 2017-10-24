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
		G->vertices++;
	}
	else{
		vertice *p;
		p=G->inicio;
		while(p->prox_vertice!=NULL && p->vert!=V){
			p=p->prox_vertice;
		}
		if(p->prox_vertice==NULL && p->vert!=V){
			p->prox_vertice=q;
			G->vertices++;
		}
		else{
			printf("vertice ja existente \n");
		}
	}
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
		else{
			printf("aresta ja existente\n");
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
	//verifica se é nulo
	if(p!=NULL){
		q=p->prox_aresta;
	}
	aux=NULL;
	//procura pela aresta que deseja remover
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
	vertice *q, *p;
	p=busca_vertice(G,V);
	//verifica se nao eh nulo o vertice
	if(p!=NULL){
		q=p->prox_aresta;
		//remove tas as arestas que esse vertice é aresta
		while(q!=NULL){
			remove_aresta(G,q->vert,V);
			remove_aresta(G,V,q->vert);
			q=p->prox_aresta;

		}
		//procura pelo vertice em caso de ser o primeiro vertice da lista
		q=G->inicio;
		if(q->vert==V){
			G->inicio=q->prox_vertice;
			free(q);
		}
		//se nao for o primeiro vertice. percorre a lista ateh achar o vertice
		else{
			while(q->prox_vertice!=NULL && q->prox_vertice->vert!=V){
				q=q->prox_vertice;
			}
			if(q->prox_vertice->vert==V){
				q->prox_vertice=p->prox_vertice;
				free(p);
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

int main(void){
	grafo G;
	int menu=1;
	define(&G);

//insere vertices
	insere_vertice(&G,1);
	insere_vertice(&G,2);
	insere_vertice(&G,3);
	insere_vertice(&G,4);
	insere_vertice(&G,5);
	insere_vertice(&G,6);
	insere_vertice(&G,7);
	insere_vertice(&G,8);
	insere_vertice(&G,9);

	//insere arestas
	insere_aresta(&G,1,2);
	insere_aresta(&G,1,6);
	insere_aresta(&G,2,1);
	insere_aresta(&G,2,4);
	insere_aresta(&G,2,3);
	insere_aresta(&G,3,2);
	insere_aresta(&G,3,5);
	insere_aresta(&G,4,6);
	insere_aresta(&G,4,2);
	insere_aresta(&G,4,5);
	insere_aresta(&G,4,7);
	insere_aresta(&G,5,3);
	insere_aresta(&G,5,4);
	insere_aresta(&G,6,1);
	insere_aresta(&G,6,4);
	insere_aresta(&G,7,4);
	insere_aresta(&G,7,9);
	insere_aresta(&G,7,8);
	insere_aresta(&G,8,7);
	insere_aresta(&G,9,7);


	while(menu!=0){
		printf("\n");
		printf("---------------------------------------------------\n");
		printf("1->visualiza grafo         |\n");
		printf("2->insere vertice          |\n");
		printf("3->insere aresta           |\n");
		printf("4->remove vertice          |\n");
		printf("5->remove aresta           |\n");
		

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
			printf("ensira aresta , vertice que deseja('-1'para sair): \n");
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
	}
	return 0;
}