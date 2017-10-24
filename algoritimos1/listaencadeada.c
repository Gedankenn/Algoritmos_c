#include<stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct{
	float atual;
	int prox;
}elem;

typedef struct{
	elem vetor[MAX+1];
	int inicio;
	int nelem;
	int fim;
}Lista;

void Definir(Lista *L){
		L->vetor[0].atual=0;
		L->vetor[0].prox=1;
		L->inicio=0;
		L->nelem=0;
		L->fim=MAX;
}
int Lista_cheia(Lista *L){
	return(L->nelem == MAX);
}

int Penetrar(Lista *L, int num){
	int cont=1;
	if(Lista_cheia(L))
		return 0;
	if(L->nelem ==0){
		L->vetor[cont].atual=num;
		L->vetor[cont].prox=-1;	
		L->nelem++;
		return 1;
	} 
	else{
	cont=1;
	while(cont != -1){
		if(L->vetor[cont].atual > num){
			L->vetor[cont-1].prox=L->nelem+1;
			L->vetor[L->nelem+1].atual=num;
			L->vetor[L->nelem+1].prox=cont;
			L->nelem++;
			return 1;
			}
		cont=L->vetor[cont].prox;
	}
	L->vetor[L->nelem].prox=L->nelem+1;
	L->vetor[L->nelem+1].atual=num;
	L->vetor[L->nelem+1].prox=-1;
	L->nelem++;
	return 1;
}
}

int Aborto(Lista *L, int num){
	int cont=1;
	while(cont != -1){
	if(L->vetor[cont].atual == num){
		L->vetor[cont-1].prox = L->vetor[cont].prox;
		}
	cont=L->vetor[cont].prox;
	}
}

int main(void){

	int aux, cont=1;
	Lista lista;
	
	aux=Penetrar(&lista, 2);
	if(aux==0)
		printf("erro de penetracao: \n\n");
	
	aux=Penetrar(&lista, 4);
	aux=Penetrar(&lista, 5);
	aux=Penetrar(&lista, 3);
	aux=Aborto(&lista,5);
	while(cont != -1){
	printf("%.f\n",lista.vetor[cont].atual);
	cont=lista.vetor[cont].prox;
	}
	
return 0;
}	
