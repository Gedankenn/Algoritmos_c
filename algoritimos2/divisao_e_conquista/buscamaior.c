#include <stdio.h>
#include <time.h>
#include <math.h>


int buscamaior(int V[],int inicio,int fim){
	if(fim-inicio<=1){
		if(V[inicio]>V[fim-1]){
			return V[inicio];
		}
		else
			return V[fim-1];
	}
	else{
		int m=(inicio+fim)/2;
		int v1=buscamaior(V,inicio,m);
		int v2=buscamaior(V,m+1,fim);
		if(v1>v2){
			return v1;
		}
		else
			return v2;
	}
}

int main(void){
	int vet[10];
	srand((unsigned)time(NULL));
	int cont;
	for(cont=0;cont<10;cont++){
		vet[cont]=rand()%10;
	}
	for(cont=0;cont<10;cont++){
		printf("%d ",vet[cont] );		
	}

	printf("\n");
	printf("%d\n",buscamaior(vet,0,10) );
	return 0;
}