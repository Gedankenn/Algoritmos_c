#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int votos;
	char nome[40];
}hash;

int funcaohash(char ch){
	return (ch-97);
}
void inicializa(int tam, hash *lista){
	int cont;
	for(cont=0;cont<tam;cont++){
		lista[cont].nome[0]='!';
		lista[cont].votos=0;
	}
}

void insere(char chave[], int votos, hash *lista){
	int ch;
	int cont=0, cont2=1, aux2=0, aux3=0;
	char aux;
	aux=chave[0];
	ch=funcaohash(aux);
	while(aux2!=1 && chave[cont2]!='\0'){
		if(strcmp(lista[ch].nome,chave)==0){
			lista[ch].votos=lista[ch].votos + 1;
			aux2=1;
		}
		else{
			aux=chave[cont2];
			ch=funcaohash(aux);
			cont2++;
		}
	}
	if(aux2==0){
	//	printf("teste\n");
		cont=funcaohash(chave[0]);
		while(lista[cont].nome[0]!='!'){
			aux=chave[cont2];
			cont=funcaohash(aux);
			cont2++;
		}
		lista[cont].votos=1;
		strcpy(lista[cont].nome,chave);
	//	printf("%d\n",cont );
	}
}

int busca_nome(char chave[], hash *lista, int num){
	int cont=0;
	char aux;
	aux=chave[num];
	aux=funcaohash(aux);
	//printf("teste2\n");
	if(strcmp(lista[aux].nome,chave)==0)
		return aux;

	return busca_nome(chave,lista,1+num);
}

int main(void){
	hash lista[100];
	int aux;

	inicializa(100,lista);

	insere("pablolindo",1,lista);
	insere("fabiogostoso",1,lista);
	insere("fabiogostoso",1,lista);
	insere("fabiogostoso",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("evertonfrustrado",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);
	insere("calorinhatop",1,lista);

	insere("pablo2",1,lista);



	aux=busca_nome("calorinhatop",lista,0);
	//printf("%d\n",aux);
	printf("%s, %d\n\n",lista[aux].nome,lista[aux].votos );
	aux=busca_nome("fabiogostoso",lista,0);
	printf("%s, %d\n\n",lista[aux].nome,lista[aux].votos );
	aux=busca_nome("pablo2",lista,0);
	//printf("%d\n",aux );
	printf("%s, %d\n\n",lista[aux].nome,lista[aux].votos );
	aux=busca_nome("pablolindo",lista,0);
	printf("%s, %d\n",lista[aux].nome,lista[aux].votos );


	return 0;
}