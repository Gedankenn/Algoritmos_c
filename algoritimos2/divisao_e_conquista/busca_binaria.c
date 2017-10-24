#include <stdio.h>
#include <time.h>
#include <math.h>

int busca_binaria(int V[],int chave, int inicio, int fim){
	int meio;
	if(fim<inicio){
		printf("numero nao encontrado\n");
		return 0;
	}
	else{
		meio=(inicio+fim)/2;
		if(V[meio]>chave){
			return busca_binaria(V,chave,inicio,meio-1);
		}
		else{
			if(V[meio]<chave){
				return busca_binaria(V,chave,meio+1,fim);
			}
			else
				return meio;
		}
	}
}

int main(void){
	int tam, num, cont;
	scanf("%d %d",&tam, &num);
	srand((unsigned)time(NULL));

	int vetor[tam];

	for(cont=0;cont<tam;cont++){
		vetor[cont]=rand()%10;
	}

	for(cont=0;cont<tam;cont++){
		printf("%d ",vetor[cont] );
	}
	printf("\n");

	cont=busca_binaria(vetor,num,0,tam);
	printf("%d\n",vetor[cont] );


	return 0;
}