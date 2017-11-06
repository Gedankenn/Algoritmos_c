#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	char nome[50];
	int horas[24];
	int total;
	int mes;
	struct pessoa *prox;
}pe;

typedef struct{
	int quant;
	pe* inicio;
}grupo;

void define(grupo *G){
	G->quant=0;
	G->inicio=NULL;
}
void definepe(pe *q){
	int cont=0;
	while(cont<24){
		q->horas[cont]=0;
		cont++;
	}
	q->total=0;
	q->mes=0;
}

void copia(char *n, pe *p2){
	int cont=0;
	while(n[cont]!='\0'){
		p2->nome[cont]=n[cont];
		cont++;
	}
	p2->nome[cont]='\0';
}

void insere(grupo *G, char *n, int h){
	pe *q;
	q=malloc(sizeof(pe));
	definepe(q);
	copia(n,q);
	G->quant++;
	q->horas[h]++;
	q->total++;
	q->prox=NULL;
	if(G->inicio==NULL){
		G->inicio=q;
	}
	else{
		pe *p;
		p=G->inicio;
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=q;
	}
}

int compara(char *n, pe *q){
	int cont=0;
	while(q->nome[cont]!='\0'){
		if(q->nome[cont]!=n[cont]){
			return 1;
		}
		cont++;
	}
	return 0;
}

int main(void){
	int cont;
	int aux;
	grupo G;
	pe *q;
	define(&G);
	q=G.inicio;
	FILE *data;
	char let;
	int dia,mes,ano,hora,minuto;
	int cont2;
	char fdp[50];
	int mescp, anocp, diacp;

	data=fopen("historico.txt","r");
	fscanf(data, "%*[^\n]\n", NULL);
	fscanf(data, "%*[^\n]\n", NULL);
	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp);
	//fscanf(data, "%*[^\n]\n", NULL);

	cont=0;
	cont2=0;
	mescp=mes;
	diacp=dia;
	anocp=ano;

	rewind(data);
	fscanf(data, "%*[^\n]\n", NULL);
	int aux2=0;
	while(fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp)!=EOF){
		fscanf(data, "%*[^\n]\n", NULL);
		cont=0;
		aux=0;
		//aux2=0;
		while(fdp[cont]!=':' && fdp[cont]!='\0'){
			cont++;
		}
		if((int)fdp[cont-1]<58){
			aux=1;
		}
		if(aux!=1){
			fdp[cont]='\0';
			cont=0;
			//fscanf(data, "%*[^\n]\n", NULL);
			//cont=0;

			if(mes==mescp){
				cont++;
				if(G.inicio==NULL){
					insere(&G,fdp,hora);
				}
				else{
					q=G.inicio;
					aux=compara(fdp,q);
					while(aux==1){
						q=q->prox;
						if(q==NULL){
							aux=2;
							insere(&G,fdp,hora);
						}
						else{
							//q=q->prox;
							aux=compara(fdp,q);
						}
					}
					if(aux==0){
						q->horas[hora]++;
						q->mes++;
						q->total++;
					}


				}
			}
			if(mes!=mescp && dia<30){
				if(aux2==0){
					q=G.inicio;
					printf("\nmes; ");
					while(q!=NULL){
						printf("%s; ",q->nome );
						q=q->prox;
					}
					aux2=1;
				}
				printf("\n %d/%d; ",mescp,anocp);
				q=G.inicio;
				while(q!=NULL){
					printf("%d; ",q->mes );
					//q->total=q->total+q->mes;
					q->mes=0;
					q=q->prox;
				}
				q=G.inicio;
				aux=compara(fdp,q);
				while(aux==1){
					q=q->prox;
					if(q==NULL){
						aux=2;
						insere(&G,fdp,hora);
					}
					else{
						aux=compara(fdp,q);
					}
				}
				if(aux==0){
					q->horas[hora]++;
					q->mes++;
				}
				mescp=mes;
				anocp=ano;

			}
		}


	}
	printf("\n %d/%d; ",mescp,anocp);
	q=G.inicio;
	while(q!=NULL){
		printf("%d; ",q->mes );
		//q->total=q->total+q->mes;
		q->mes=0;
		q=q->prox;
	}
	q=G.inicio;
	printf("\nnomes; ");
	while(q!=NULL){
		printf("%s; ",q->nome );
		q=q->prox;
	}
	printf("\ntotal; ");
	q=G.inicio;
	while(q!=NULL){
		printf("%d; ",q->total);
		q=q->prox;
	}

	printf("\n\nhoras; ");
	q=G.inicio;
	while(q!=NULL){
		printf("%s; ",q->nome );
		q=q->prox;
	}
	q=G.inicio;
	//printf("\n");
	cont=0;
	while(cont<24){
		printf("\n%d;",cont);
		q=G.inicio;
		while(q!=NULL){
			printf("%d; ",q->horas[cont] );
			q=q->prox;
		}
		cont++;
	}

	
	fclose(data);

	return 0;
}