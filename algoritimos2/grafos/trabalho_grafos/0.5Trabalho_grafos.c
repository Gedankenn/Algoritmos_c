#include <stdio.h>
#include <stdlib.h>


typedef struct noaresta{
	int arestas;
	struct noaresta *prox_aresta;
}aresta;


typedef struct notag{
	int vertice;
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

void insere_vertice(grafo *G, int vert){
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

void insere_aresta(grafo *G, int A, int V){
	no *p, *x;
	aresta *q, *aux, *aux2;
	q=malloc(sizeof(aresta));
	p=G->inicio;
	q->arestas=A;
	q->prox_aresta=NULL;
	while(p->vertice!=V && p->prox!=NULL){
		p=p->prox;
	}
	x=G->inicio;
	while(x->vertice!=A && x->prox!=NULL){
		x=x->prox;
	}
	
	if(p->vertice==V && x->vertice==A){
		aux=p->prox_aresta;
		if(aux!=NULL){
			while(aux->prox_aresta!=NULL && aux->arestas!=A){
				aux=aux->prox_aresta;
			}
			if(aux->prox_aresta==NULL && aux->arestas!=A){
				aux->prox_aresta=q;
				G->arestas++;
			}
		}
		else{
			p->prox_aresta=q;
		}
	}
}

void vizualiza(grafo *G){
	no *p;
	aresta *q;
	p=G->inicio;
	while(p!=NULL){
		printf("%d ",p->vertice );
		if(p->prox_aresta!=NULL){
			q=p->prox_aresta;
			while(q!=NULL){
				printf("--->%d ",q->arestas );
				q=q->prox_aresta;
			}
		}
		printf("/\n");
		p=p->prox;
	}
}

void remove_vertice(grafo *G, int V){
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

void remove_aresta(grafo *G, int A, int V){
	no *q;
	aresta *p;
	q=G->inicio;
	while(q->vertice!=V && q->prox!=NULL){
		q=q->prox;
	}
	if(q->prox_aresta!=NULL){	
		p=q->prox_aresta;
		if(q->vertice==V && p->arestas==A){
			q->prox_aresta=q->prox_aresta->prox_aresta;
		}
		else{
			while(p->prox_aresta!=NULL && p->prox_aresta->arestas!=A ){
				p=p->prox_aresta;
			}
			if(p->prox_aresta!=NULL){
				if(q->vertice==V && p->prox_aresta->arestas==A){
					p->prox_aresta=p->prox_aresta->prox_aresta;
				}
			}
		}
	}
}


int main(void){
	grafo G;
	define(&G);

	char entrada='N'; 
	int data, data2;
	while(entrada!='@'){
		//interface
		printf("inserir vertice: (V)\n");
		printf("inserir aresta: (A)\n");
		printf("visualizar grafo: (G)\n");
		printf("remover vertice: (R)\n");
		printf("remover aresta: (r)\n");
		printf("sair: (@)\n");
		scanf(" %c",&entrada);
		//logica do programa
		if(entrada=='V'){
			printf("ensira -1 para sair da entrada de vertices\n");
			printf("ensira vertice que deseja: \n");
			scanf("%d",&data);
			while(data!=-1){
				insere_vertice(&G,data);
				scanf("%d",&data);
			}
		}
		else if(entrada=='A'){
			printf("ensira -1 para sair da entrada de arestas\n");
			printf("ensira a aresta e o vertice que deseja ligar:\n");
			scanf("%d %d",&data,&data2);
			while(data!=-1){
				insere_aresta(&G,data,data2);
				insere_aresta(&G,data2,data);
				scanf("%d %d",&data,&data2);
			}
		}
		else if(entrada=='G'){
			vizualiza(&G);
		}
		else if(entrada=='R'){
			printf("ensira -1 para sair da remocao de vertice\n");
			printf("ensira o vertice que deseja remover\n");
			scanf("%d",&data);
			while(data!=-1){
				remove_vertice(&G,data);
				scanf("%d",&data);
			}
		}
		else if(entrada=='r'){
			printf("ensira -1 para sair da remocao de arestas\n");
			printf("ensira aresta e o vertice que deseja remover\n");
			scanf(" %d %d",&data,&data2);
			while(data!=-1){
				remove_aresta(&G,data,data2);
				remove_aresta(&G,data2,data);
				scanf(" %d %d",&data,&data2);
			}
		}
		printf("---------------------------------------------------------------------------\n");
		//scanf(" %c",&entrada);
	}



	return 0;
}