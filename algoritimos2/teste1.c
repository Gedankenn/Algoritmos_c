#include <stdio.h>
#include <stdlib.h>

typedef struct notag{
	char chave;
	struct notag *prox;
}no;

typedef struct{
	no* topo;
	int quant;
}LD;

void DefineS(LD *L){
	L->quant=0;
	L->topo=NULL;
}

void empilha(LD *L, char chave){
	no *p;
	p=malloc(sizeof(no));
	p->chave=chave;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
}

void desempilha(LD *L){
	char chave;
	no *p;
	p=L->topo;
	chave=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
	printf("%c",chave );
}

int main(void){
	LD lista;
	int cont=0, aux;
	char chave[] = "ESTE EXERCICIO E MUITO FACIL .";
	DefineS(&lista);

	while(chave[cont]!='.'){
		empilha(&lista,chave[cont]);
		if(chave[cont]== ' ' || chave[cont]=='.'){
                while(lista.quant>0)
                    desempilha(&lista);
		}
		cont++;
	}


return 0;
}
