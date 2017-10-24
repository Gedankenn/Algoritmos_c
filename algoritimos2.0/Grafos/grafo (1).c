#include <stdio.h>
#include <stdlib.h>


//talvez nao precisa deessa parte
/*typedef struct noaresta{
	int edge;
	struct noaresta *prox_aresta;
}aresta;*/


typedef struct novertice{
	int vert;
	int custo;
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

void insere_aresta(grafo *G, int V, int A, int C){
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
		q->custo=C;
		q->prox_aresta=NULL;
		while(p->prox_aresta!=NULL && p->vert!=A){
			p=p->prox_aresta;
		}
		if(p->prox_aresta==NULL){
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
	vertice *q, *p;
	p=busca_vertice(G,V);
	if(q!=NULL){
		q=p->prox_aresta;
		while(q!=NULL){
			remove_aresta(G,q->vert,V);
			remove_aresta(G,V,q->vert);
			q=p->prox_aresta;

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

void enfila(grafo *L, int V){
	vertice *p;
	p=malloc(sizeof(vertice));
	p->vert=V;
	p->prox_vertice=NULL;
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

			aux=busca_vertice(G,u->vert);
			aux=aux->prox_aresta;

			while(aux!=NULL){
				if(cor[aux->vert]==0){
					cor[aux->vert]=1;
					d[aux->vert]=d[u->vert]+1;
					pai[aux->vert]=u->vert;
					enfila(&L,aux->vert);
				}
				aux=aux->prox_aresta;
			}
			cor[u->vert]=2;
		}
	}
	else{
		printf("vertice invalido\n");
	}
}

void visita_profundidade(vertice *q, int *pai, int *d, int *f, int *cor, int *tempo){
	cor[q->vert]=1;
	*tempo=*tempo+1;
	d[q->vert]=*tempo;

	vertice *a;
	a=q->prox_aresta;
	while(a!=NULL){
		if(cor[a->vert]==0){
			pai[a->vert]=q->vert;
			visita_profundidade(a,pai,d,f,cor,tempo);
		}
		a=a->prox_aresta;
	}
	cor[q->vert]=2;
	*tempo=*tempo+1;
	f[q->vert]=*tempo;
}

void busca_em_profundidade(grafo *G, int *pai, int *d, int *f, int *cor){
	int tempo=0;
	vertice *q;

	q=G->inicio;

	while(q!=NULL){
		cor[q->vert]=0;
		pai[q->vert]=-1;
		q=q->prox_vertice;
	}

	q=G->inicio;
	while(q!=NULL){
		if(cor[q->vert]==0){
			visita_profundidade(q,pai,d,f,cor, &tempo);
		}
		q=q->prox_vertice;
	}

}

void matriz_de_ajdacencia(grafo *G){
	vertice *q, *a;
	int matriz[G->vertices+1][G->vertices+1];
	int i,j;
	i=0;
	j=0;
	
	//gera matriz
	q=G->inicio;
	while(i<=G->vertices){
		j=0;
		while(j<=G->vertices){
			matriz[i][j]=0;
			j++;
		}
		matriz[i][0]=q->vert;
		matriz[0][i]=q->vert;
		if(i>0){
			q=q->prox_vertice;
		}
		i++;
	}
	matriz[0][0]=0;

	//faz atribuicoes a matriz
	i=1;
	j=0;
	q=G->inicio;
	a=q->prox_aresta;
	while(i<=G->vertices){
		j=0;
		while(j<=G->vertices){
			if(a!=NULL){
				if(matriz[0][j]==a->vert){
					matriz[i][j]=a->custo;
					a=a->prox_aresta;
				}
			}
			j++;
		}
		if(q->prox_vertice!=NULL){
			q=q->prox_vertice;
			a=q->prox_aresta;
		}
		i++;
	}



	
	//printa
	i=0;
	j=0;
	while(i<=G->vertices){
		j=0;
		while(j<=G->vertices){
			printf("|%d| ",matriz[i][j] );
			j++;
		}
		i++;
		printf("\n");
	}

}
int busca_minimo(grafo *Q, int *d){
	vertice *q, *aux;
	q=Q->inicio;
	int min=9999999;
	int v=-1;

	if(Q->inicio==NULL){
		return -1;
	}
	if(q->prox_vertice==NULL){
		Q->inicio=NULL;
		return q->vert;
	}
	while(q->prox_vertice->prox_vertice!=NULL){
		if(d[q->vert]<min){
			v=q->vert;
			aux=q;
			min=d[q->vert];
		}
		q=q->prox_vertice;
	}
	if(d[q->prox_vertice->vert]<min){
		aux=q->prox_vertice;
		v=q->prox_vertice->vert;
		q->prox_vertice=NULL;
		free(aux);
		return v;
	}
	else{
		aux->vert=aux->prox_vertice->vert;
		q=aux->prox_vertice;
		aux->prox_vertice=aux->prox_vertice->prox_vertice;
		free(q);
	}
	return v;

}
int pertence(grafo *Q, int v){
	vertice *q;
	q=Q->inicio;
	while(q!=NULL){
		if(q->vert==v){
			return 1;
		}
		q=q->prox_vertice;
	}
	return -1;
}

void prim(grafo *G, int *pai, int *d, int v){
	vertice *q, *a;
	grafo Q;
	define(&Q);

	q=G->inicio;
	while(q!=NULL){
		d[q->vert]=9999999;
		pai[q->vert]=-1;
		enfila(&Q,q->vert);
		q=q->prox_vertice;
	}
	//escolhe um vertice para iniciar a arvore
	d[v]=0;

	q=busca_vertice(G,v);
	while(q!=NULL){
		a=q->prox_aresta;

		while(a!=NULL){
			if(pertence(&Q,a->vert)==1 && a->custo<d[a->vert]){
				pai[a->vert]=a->vert;
				d[a->vert]=a->custo;
			}
			a=a->prox_aresta;
		}
		q=busca_vertice(G,busca_minimo(&Q,d));
	}

}

void dijkstra(grafo *G, int *pai, int *d, int v){
	vertice *q, *a;
	grafo Q;

	define(&Q);
	a=busca_vertice(G,v);
	if(a!=NULL){
		q=G->inicio;
		if(q!=NULL){
			while(q!=NULL){
				pai[q->vert]=-1;
				d[q->vert]=99999999;
				enfila(&Q,q->vert);
				q=q->prox_vertice;
			}
			d[v]=0;
			q=busca_vertice(G,v);
			while(q!=NULL){
				a=q->prox_aresta;
				while(a!=NULL){
					if(d[a->vert]>d[q->vert]+a->custo){
						d[a->vert]=d[q->vert]+a->custo;
						pai[a->vert]=q->vert;
					}
					a=a->prox_aresta;
				}
				q=busca_vertice(G,busca_minimo(&Q,d));
			}
		}
	}

}

int main(void){
	grafo G;
	int menu=1;
	define(&G);

	insere_vertice(&G,1);
	insere_vertice(&G,2);
	insere_vertice(&G,3);
	insere_vertice(&G,4);
	insere_vertice(&G,5);
	insere_vertice(&G,6);
	insere_vertice(&G,7);
	insere_vertice(&G,8);
	insere_vertice(&G,9);
	insere_vertice(&G,10);

//                   A V C
	insere_aresta(&G,2,1,7);
	insere_aresta(&G,4,1,9);
	insere_aresta(&G,5,1,10);
	insere_aresta(&G,6,1,8);
	insere_aresta(&G,8,1,9);
	insere_aresta(&G,10,1,8);
	//vertice 2
	insere_aresta(&G,1,2,7);
	insere_aresta(&G,3,2,4);
	insere_aresta(&G,4,2,5);
	insere_aresta(&G,10,2,9);
	insere_aresta(&G,9,2,9);
	//3
	insere_aresta(&G,2,3,4);
	insere_aresta(&G,5,3,4);
	insere_aresta(&G,4,3,1);
	//4
	insere_aresta(&G,1,4,9);
	insere_aresta(&G,5,4,3);
	insere_aresta(&G,3,4,1);
	insere_aresta(&G,2,4,5);
	//5
	insere_aresta(&G,3,5,4);
	insere_aresta(&G,4,5,3);
	insere_aresta(&G,1,5,10);
	insere_aresta(&G,6,5,18);
	//6
	insere_aresta(&G,1,6,8);
	insere_aresta(&G,8,6,9);
	insere_aresta(&G,7,6,9);
	insere_aresta(&G,5,6,18);
	//7
	insere_aresta(&G,6,7,9);
	insere_aresta(&G,8,7,3);
	insere_aresta(&G,9,7,6);
	//8
	insere_aresta(&G,7,8,3);
	insere_aresta(&G,6,8,9);
	insere_aresta(&G,1,8,9);
	insere_aresta(&G,10,8,2);
	insere_aresta(&G,9,8,4);
	//9
	insere_aresta(&G,10,9,2);
	insere_aresta(&G,8,9,4);
	insere_aresta(&G,7,9,6);
	insere_aresta(&G,2,9,9);
	//10
	insere_aresta(&G,1,10,8);
	insere_aresta(&G,2,10,9);
	insere_aresta(&G,9,10,2);
	insere_aresta(&G,8,10,2);

	while(menu!=0){
		printf("\n");
		printf("---------------------------------------------------\n");
		printf("1->visualiza grafo         |\n");
		printf("2->insere vertice          |\n");
		printf("3->insere aresta           |\n");
		printf("4->remove vertice          |\n");
		printf("5->remove aresta           |\n");
		printf("6->busca em largura        |\n");
		printf("7->busca em profundidade   |\n");
		printf("8->matriz de adjacencia    |\n");
		printf("9->algoritmo de prim       |\n");
		printf("10->algoritmo de dijkstra  |\n");

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
			int V, A, C;
			printf("ensira aresta , vertice e custo a que deseja('-1'para sair): \n");
			scanf("%d %d",&A,&V,&C);
			while(V!=-1){
				insere_aresta(&G,V,A,C);
				insere_aresta(&G,A,V,C);
				scanf("%d %d",&A,&V,&C);
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
				for(cont=1;cont<=G.vertices;cont++){
					printf("vertice: %d|pai: %d|distancia: %d|\n",cont,pai[cont],d[cont] );
				}
				scanf("%d",&V);
			}
		}
		if(menu==7){
			int pai[G.vertices], d[G.vertices], cor[G.vertices], f[G.vertices];
			printf("----------busca em profundidade-------\n");
			busca_em_profundidade(&G,pai,d,f,cor);
			vertice *q;
			q=G.inicio;

			printf("pai | distancia | tempo final|\n");
			while(q!=NULL){
				printf("%d       %d          %d      \n",pai[q->vert],d[q->vert],f[q->vert]);
				q=q->prox_vertice;
			}

		}

		if(menu==8){
			matriz_de_ajdacencia(&G);
		}

		if(menu==9){
			int pai[G.vertices], d[G.vertices];
			int v;
			printf("escolha o vertice que deseja iniciar a arvore(-1 para sair): \n");
			scanf("%d",&v);
			int cont=0;
			vertice *q;
			while(v!=-1){
				prim(&G,pai,d,v);
				q=G.inicio;
				while(q!=NULL){
					printf("pai[%d]=%d | distancia[%d]=%d\n",q->vert,pai[q->vert],q->vert,d[q->vert] );
					q=q->prox_vertice;
				}
				scanf("%d",&v);
			}
		}

		if(menu==10){
			int pai[G.vertices], d[G.vertices];
			int v;
			printf("escolha o vertice que deseja iniciar o caminho minimo(-1 para sair): \n");
			scanf("%d",&v);
			int cont=0;
			vertice *q;
			while(v!=-1){
				dijkstra(&G,pai,d,v);
				q=G.inicio;
				while(q!=NULL){
					printf("pai[%d]=%d | distancia[%d]=%d\n",q->vert,pai[q->vert],q->vert,d[q->vert] );
					q=q->prox_vertice;
				}
				scanf("%d",&v);
			}	
		}


	}
}