#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numero;
	int ddd;
	char nome[40];
}hash;

typedef struct noips{
	int ipnum;
	struct noips *prox;
}ip;

typedef struct{
	ip* ips;
	char nome[40];
}tabelaip;

int funcaohash(char ch){
	return (ch-97);
}
void inicializa(int tam, hash *lista){
	int cont;
	for(cont=0;cont<tam;cont++){
		lista[cont].numero=0;
	}
}
void inicializadns(int tam, tabelaip *tabela){
	int cont;
	for(cont=0;cont<tam;cont++){
		tabela[cont].ips=NULL;
		tabela[cont].nome[0]='!';
	}
}

void insereip(char chave[], int ipnumero, tabelaip *tabela){
	int cont=0, cont2=1, cont3=0, dif=0;
	ip *q, *x;
	char aux;
	aux=chave[0];
	//printf("teste\n");
	cont=funcaohash(aux);
	if(strcmp(chave,tabela[cont].nome)==0){
		q=malloc(sizeof(ip));
		x=tabela[cont].ips;
		//printf("teste2\n");
		while(x!=NULL){
			x=x->prox;
		}
		x=q;
		q->ipnum=ipnumero;
		q->prox=NULL;
		free(q);
	}
	else{
		//printf("teste3\n");
		while(tabela[cont].nome[0]!='!'){
			aux=chave[cont2];
			cont=funcaohash(aux);
			cont2++;
		}
		//printf("teste4\n");
		q=malloc(sizeof(ip));
		tabela[cont].ips=q;
		q->ipnum=ipnumero;
		q->prox=NULL;
		strcpy(tabela[cont].nome,chave);
	}
}

void insere(char chave[], int ddd, int numero, hash *lista){
	int ch;
	int cont, cont2=1;
	char aux;
	aux=chave[0];
	ch=funcaohash(aux);
	while(lista[ch].numero!=0){
		aux=chave[cont2];
		ch=funcaohash(aux);
		cont2++;
	}
	lista[ch].numero=numero;
		strcpy(lista[ch].nome,chave);
		lista[ch].ddd=ddd;
}

int busca_nome(char chave[], hash *lista, int num){
	int cont=0;
	char aux;
	aux=chave[num];
	aux=funcaohash(aux);
	while(chave[cont]==lista[aux].nome[cont]){
		cont++;
	}
	if(chave[cont-1]=='\0'){
		return aux;
	}
	return busca_nome(chave,lista,1+num);
}


int main(void){
	//hash lista[100];
	tabelaip tabela[100];
	char nome[40];
	int aux;
	int telefone;
	int ddd;

	scanf("%s",&nome);
	//scanf("%d",&ddd);
	scanf("%d",&telefone);

	//inicializa(100,lista);
	inicializadns(100,tabela);

	//insere(nome,ddd,telefone,lista);
	//aux=nome[0];
	//aux=funcaohash(aux);
	//printf("%d\n",aux );

	//printf("%s\n\n",lista[aux].nome );
	//aux=busca_nome(nome,lista,0);
	//printf("%s\n\n",lista[aux].nome );
	//printf("%d\n\n",aux );

	insereip(nome,telefone,tabela);
	insereip("pausudo.com",224,tabela);
	aux=funcaohash(nome[0]);
	printf("%s\n",tabela[aux].nome);
	aux=funcaohash('a');
	printf("%s\n",tabela[aux].nome);



	return 0;
}