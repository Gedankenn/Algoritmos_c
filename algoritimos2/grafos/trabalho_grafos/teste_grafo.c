#include <stdio.h>
#include <stdlib.h>

//STRCUT GRAFO
typedef struct noaresta{
	int arestas;
	int custo;
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

int buscamaior(grafo *G){
	no *q;
	int maior=0;

	q=G->inicio;
	while(q!=NULL){
		if(q->vertice>maior){
			maior=q->vertice;
		}
		q=q->prox;
	}
	return maior;
}
int pertence(grafo *Q, int v){
	no *q;
	q=Q->inicio;
	while(q!=NULL){
		if(q->vertice==v){
			return 1;
		}
		q=q->prox;
	}
	return 0;
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

void insere_aresta(grafo *G, int A, int V, int Val){
	no *p, *x;
	aresta *q, *aux, *aux2;
	q=malloc(sizeof(aresta));
	p=G->inicio;
	q->arestas=A;
	q->custo=Val;
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

void remove_vertice(grafo *G, int V){
	no *p, *aux;
	aresta *q, *aux2;
	p=G->inicio;
	if(p->vertice==V){
		G->inicio=p->prox;
		
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

void enfila(grafo *L, int V){
	no *q, *p;
	q=malloc(sizeof(no));
	q->vertice=V;
	q->prox=NULL;
	if(L->inicio==NULL){
		L->inicio=q;
	}
	else{
		p=L->inicio;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=q;
	}
}

int desenfila(grafo *L){
	no *q;
	int aux;
	q=L->inicio;
	aux=q->vertice;
	L->inicio=q->prox;
	free(q);
	return aux;
}

no* buscavertice(grafo *G, int V){
	no *q;
	q=G->inicio;
	if(q->vertice==V){
		return q;
	}
	else{
		while(q!=NULL){
			if(q->vertice==V){
				return q;
			}
			q=q->prox;
		}
	}
	return NULL;
}

void buscalargura(grafo *G, int s, int *d, int *pai){
	//branco=0 cinza=1 preto=2 e nulo=-1
	no *q;
	aresta *p;
	int cor[G->vertices], u, v;
	grafo L;
	q=G->inicio;
	while(q!=NULL){
		cor[q->vertice]=0;
		d[q->vertice]=-1;
		pai[q->vertice]=-1;
		q=q->prox;
	}
	cor[s]=1;
	d[s]=0;
	L.inicio=NULL;
	enfila(&L,s);
	while(L.inicio!=NULL){
		u=desenfila(&L);
		q=buscavertice(G,u);
		p=q->prox_aresta;
		while(p!=NULL){
			if(cor[p->arestas]==0){
				cor[p->arestas]=1;
				d[p->arestas]=d[u]+1;
				pai[p->arestas]=u;
				enfila(&L,p->arestas);
			}
			p=p->prox_aresta;
		}
		cor[u]=2;
	}
		//return d;
}
void visita(grafo *G, int u, int *d, int *f, int *pai, int *cor, int *tempo){
	aresta *p;
	no *q;
	cor[u]=1;
	*tempo=*tempo+1;
	d[u]=*tempo;

	q=buscavertice(G,u);
	p=q->prox_aresta;
	while(p!=NULL){
		if(cor[p->arestas]==0){
			pai[p->arestas]=q->vertice;
			u=p->arestas;
			visita(G,u,d,f,pai,cor,tempo);
		}
		p=p->prox_aresta;
	}
	cor[q->vertice]=2;
	*tempo=*tempo+1;
	f[q->vertice]=*tempo;
}


void buscaemprofundidade(grafo *G, int *d, int *f, int *pai){
	int cor[G->vertices], u, tempo;
	no *q;
	aresta *p;
	q=G->inicio;
	while(q!=NULL){
		cor[q->vertice]=0;
		pai[q->vertice]=-1;
		q=q->prox;
	}
	tempo=0;
	q=G->inicio;
	while(q!=NULL){
		if(cor[q->vertice]==0){
			u=q->vertice;
			visita(G,u,d,f,pai,cor,&tempo);
		}
		q=q->prox;
	}
}

int grauVertice(grafo *G, int V){
	no *q;
	aresta *p;
	q=buscavertice(G,V);
	if(q!=NULL){
		p=q->prox_aresta;
		int grau=0;
		while(p!=NULL){
			p=p->prox_aresta;
			grau++;
		}
		return grau;
	}
	return -1;
}

void verificaConexo(grafo *G){
	no *q;
	int distancia[G->vertices], pai[G->vertices], i=0;
	q=G->inicio;
	buscalargura(G,q->vertice,distancia,pai);
	while(q!=NULL){
		if(distancia[q->vertice]==-1){
			printf("grafo e desconexo\n");
			q=NULL;
			i=1;
		}
		else{
			q=q->prox;
		}
	}
	if(i==0){
		printf("grafo eh conexo\n");
	}
}

int buscaminimo(grafo *Q, int *peso){
	no *q, *aux;
	q=Q->inicio;
	int custo, v;

	custo=1;

	if(Q->inicio==NULL){
		return -1;
	}

	else if(q->prox==NULL){
		Q->inicio=NULL;
		return q->vertice;
	}
	else{
		while(q->prox->prox!=NULL){
			if(custo>peso[q->vertice]){
				custo=peso[q->vertice];
				aux=q;
			}
			q=q->prox;
		}
		if(custo>peso[q->prox->vertice]){
			v=q->prox->vertice;
			q->prox=q->prox->prox;
			return v;
		}
		else{
			v=aux->vertice;
			aux->vertice=aux->prox->vertice;
			aux->prox=aux->prox->prox;
			return v;
		}
	}
}

//avore geradora minima PRIM
void algoritimo_prim(grafo *G, int *d, int *pai, int *key){
	no *q;
	aresta *p;
	grafo Q;

	define(&Q);
	int maior, r;
	maior=buscamaior(G);
	int weight[maior][maior];
	//cria matriz de peso
	q=G->inicio;
	r=q->vertice;
	while(q!=NULL){
		if(q->prox_aresta!=NULL){
			p=q->prox_aresta;
			while(p!=NULL){
				weight[q->vertice][p->arestas]=p->custo;
				p=p->prox_aresta;
			}
		}
		q=q->prox;
	}
	// termina criar matriz

	q=G->inicio;
	while(q!=NULL){
		key[q->vertice]=9999;
		pai[q->vertice]=-1;
		enfila(&Q, q->vertice);
		q=q->prox;
	}
	key[r]=0;

	int u=buscaminimo(&Q, key);
	q=NULL;
	if(u!=-1){
		q=buscavertice(G,u);
	}

	while(q!=NULL){
		p=q->prox_aresta;
		while(p!=NULL){
			if(pertence(&Q,p->arestas)==1 && weight[q->vertice][p->arestas]<key[p->arestas]){
				pai[p->arestas]=q->vertice;
				key[p->arestas]=weight[q->vertice][p->arestas];
			}
			p=p->prox_aresta;
		}
		u=buscaminimo(&Q, key);
		q=NULL;
		if(u!=-1){
			q=buscavertice(G,u);
		}

	}

}


void dijkstra(grafo *G, int s, int *distancia, int *pai){
	no *q;
	aresta *p;
	grafo Q;

	define(&Q);
	int maior, r;
	maior=buscamaior(G);
	int weight[maior][maior];
	//cria matriz de peso
	q=G->inicio;
	r=q->vertice;
	while(q!=NULL){
		if(q->prox_aresta!=NULL){
			p=q->prox_aresta;
			while(p!=NULL){
				weight[q->vertice][p->arestas]=p->custo;
				p=p->prox_aresta;
			}
		}
		q=q->prox;
	}
	// termina criar matriz
	q=G->inicio;
	while(q!=NULL){
		distancia[q->vertice]=9999;
		pai[q->vertice]=-1;
		enfila(&Q, q->vertice);
		q=q->prox;
	}
	distancia[s]=0;

	int u=buscaminimo(&Q, distancia);
	q=NULL;
	if(u!=-1){
		q=buscavertice(G,u);
	}
	while(q!=NULL){
		p=q->prox_aresta;
		while(p!=NULL){
			if(distancia[p->arestas] > weight[q->vertice][p->arestas]+distancia[q->vertice]){
				pai[p->arestas]=q->vertice;
				distancia[p->arestas]=weight[q->vertice][p->arestas]+distancia[q->vertice];
			}
			p=p->prox_aresta;
		}
		u=buscaminimo(&Q, distancia);
		q=NULL;
		if(u!=-1){
			q=buscavertice(G,u);
		}

	}

}


int main(void){
	grafo G, lista;
	define(&G);
	define(&lista);

	char entrada='N'; 
	int data, data2;
	while(entrada!='@'){
		//interface
		printf("inserir vertice: (V)\n");
		printf("inserir aresta: (A)\n");
		printf("insere aresta ordenada: (o)\n");
		printf("visualizar grafo: (G)\n");
		printf("remover vertice: (R)\n");
		printf("remover aresta: (r)\n");
		printf("busca em largura: (l)\n");
		printf("busca em profundidade: (p)\n");
		printf("retorna Grau da porra tudo: (g)\n");
		printf("diz se grafo e conexo: (c)\n");
		printf("transforma em matriz de  adjacencia: (m)\n");
		printf("algoritmo de prim: (i)\n");
		printf("algoritmo djikistra: (d)\n");
		printf("ensira -1 para sair de qualquer opcao:\n");
		printf("sair: (@)\n");
		scanf(" %c",&entrada);
		//logica do programa
		if(entrada=='V'){
			printf("ensira vertice que deseja: \n");
			scanf("%d",&data);
			while(data!=-1){
				insere_vertice(&G,data);
				scanf("%d",&data);
			}
		}
		else if(entrada=='A'){
			printf("ensira a aresta, vertice e o custo que deseja ligar:\n");
			int custo;
			scanf("%d %d %d",&data,&data2,&custo);
			while(data!=-1){
				insere_aresta(&G,data,data2,custo);
				insere_aresta(&G,data2,data,custo);
				scanf("%d %d %d",&data,&data2,&custo);
			}
		}
		else if(entrada=='G'){
			vizualiza(&G);
		}
		else if(entrada=='R'){
			printf("ensira o vertice que deseja remover\n");
			scanf("%d",&data);
			while(data!=-1){
				remove_vertice(&G,data);
				scanf("%d",&data);
			}
		}
		else if(entrada=='O'){
			printf("ensira a aresta, vertice e o custo que deseja ligar-orientado:\n");
			int custo;
			scanf("%d %d %d",&data,&data2,&custo);
			while(data!=-1){
				insere_aresta(&G,data,data2,custo);
				scanf("%d %d %d",&data,&data2,&custo);
			}
		}
		else if(entrada=='r'){
			printf("ensira aresta e o vertice que deseja remover\n");
			scanf(" %d %d",&data,&data2);
			while(data!=-1){
				remove_aresta(&G,data,data2);
				remove_aresta(&G,data2,data);
				scanf(" %d %d",&data,&data2);
			}
		}
		else if(entrada=='l'){
			int distancia[buscamaior(&G)], pai[buscamaior(&G)];
			printf("ensira o vertice que deseja fazer busca\n");
			scanf(" %d",&data);
			while(data!=-1){
				if(pertence(&G,data)==1){
					buscalargura(&G,data,distancia,pai);
					no *q;
					q=G.inicio;
					while(q!=NULL){
						printf("%d dista %d do vertice %d\n",q->vertice,distancia[q->vertice],data);
						q=q->prox;
					}
				}
				scanf(" %d",&data);
			}
		}
		else if(entrada=='p'){
			int distancia[buscamaior(&G)], pai[buscamaior(&G)], f[buscamaior(&G)], data;
			no *q;
			while(data!=-1){
				q=G.inicio;
				buscaemprofundidade(&G,distancia,f,pai);
				while(q!=NULL){
					printf("%d dista %d com tempo %d\n",q->vertice,distancia[q->vertice],f[q->vertice] );
					q=q->prox;
				}
				scanf("%d",&data);
			}
			free(q);
		}
		else if(entrada=='g'){
			scanf("%d",&data);
			while(data!=-1){
				printf("o grau eh de %d\n",grauVertice(&G,data));
				scanf("%d",&data);
			}
		}
		else if(entrada=='c'){
			verificaConexo(&G);
		}
		else if(entrada=='m'){
			no *q;
			q=G.inicio;
			int maior=0, i, j;
			while(q!=NULL){
				if(q->vertice>maior){
					maior=q->vertice;
				}
				q=q->prox;
			}
			//gera a matriz
			int matriz[maior+1][maior+1];
			//inicializa a matriz
			for(i=0;i<maior+1;i++){
				for(j=0;j<maior+1;j++){
					matriz[i][j]=0;
				}
			}
			q=G.inicio;
			while(q!=NULL){
				matriz[q->vertice][0]=q->vertice;
				matriz[0][q->vertice]=q->vertice;
				q=q->prox;
			}
			// transforma o grafo em uma matriz
			aresta *p;
			i=0;
			j=0;
			q=G.inicio;
			while(q!=NULL){
				p=q->prox_aresta;
				while(p!=NULL){
					matriz[q->vertice][p->arestas]=p->custo;
					p=p->prox_aresta;
				}
				q=q->prox;
			}
			for(i=0;i<maior+1;i++){
				for(j=0;j<maior+1;j++){
					printf("|%d| ", matriz[i][j] );
				}
				printf("\n");
			}
		}
		//prim
		else if(entrada=='i'){
			int distancia[buscamaior(&G)], pai[buscamaior(&G)], key[buscamaior(&G)];
			no *q;
			q=G.inicio;
			algoritimo_prim(&G,distancia,pai,key);
			while(q!=NULL){
				printf("%d --- %d\n",pai[q->vertice],key[q->vertice] );
				q=q->prox;
			}
			

		}
		//djikistra
		else if(entrada =='d'){
			int distancia[buscamaior(&G)], pai[buscamaior(&G)];
			no *q;
			q=G.inicio;
			dijkstra(&G,q->vertice,distancia,pai);
			while(q!=NULL){
				printf("%d ---- %d\n",distancia[q->vertice],pai[q->vertice] );
				q=q->prox;
			}
		}
		printf("---------------------------------------------------------------------------\n");
		//scanf(" %c",&entrada);
	}

	return 0;
}