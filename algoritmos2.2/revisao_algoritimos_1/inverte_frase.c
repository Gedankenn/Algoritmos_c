#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void string_inverte(char *s){
	int cont=0;
	char r[50];

	while(s[cont]!='.'){
		r[cont]=s[cont];
		cont++;
	}
	r[cont]='.';
	//cont--;
	int cont2=0;
	while(cont>=0){
		s[cont2]=r[cont];
		cont2++;
		cont--;
	}
	s[cont2]='\0';
}

//versao com pilha

typedef struct notag{
	char chave;
	struct notag *prox;
}no;

typedef struct{
	int total;
	no *inicio;
}lista;

void define(lista *L){
	L->inicio=NULL;
	L->total=0;
}

void empilha(lista *L, char c){
	no *p;
	p=malloc(sizeof(no));
	p->chave=c;
	p->prox=L->inicio;
	L->inicio=p;
	L->total++;
}

char desempilha(lista *L){
	char c;
	no *p;
	p=L->inicio;
	c=p->chave;
	L->inicio=p->prox;
	free(p);
	L->total--;
	return c;
}

int main(void){
	char s[]="tudo puta e viado.";
	clock_t Ti, Tf;

	//scanf("%[^\n]",&s);
	printf("%s\n",s );

	Ti=clock();
	string_inverte(s);
	Tf=clock();
	printf("%s\nem tempo: %f",s,(Tf-Ti) );

	//usando pilha
	char t[]="tudo puta e viado.";
	lista pilha;
	int cont=0;
	char aux;

	printf("\npilha\n");
	Ti=clock();
	define(&pilha);

	while(t[cont]!='.'){
		while(t[cont]!=' ' && t[cont]!='.'){
			empilha(&pilha,t[cont]);
			cont++;
		}
		while(pilha.total>0){
			aux=desempilha(&pilha);
			printf("%c",aux );
		}
		printf(" ");
		if(t[cont]!='.'){
			cont++;
		}
	}
	Tf=clock();
	printf("\npilha com tempo: %f\n",(Tf-Ti) );

	return 0;
}