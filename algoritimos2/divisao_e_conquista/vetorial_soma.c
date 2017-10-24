#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


int soma(int *V,int inicio, int fim){
	if(fim-inicio==1){
		return V[inicio]+V[fim];
	}
	if(fim-inicio==0){
		return V[inicio];
	}
	else{
		int meio=(inicio+fim)/2;
		int v1=soma(V,inicio,meio);
		int v2=soma(V,meio+1,fim);
		return v1+v2;
	}
}

int main(void){
	int MAX=50000000;
	int *vet;
	int cont;
	vet=malloc(MAX*sizeof(int));

	srand((unsigned)time(NULL));
	for(cont=0;cont<MAX;cont++){
		vet[cont]=rand()%5;
	}
	/*for(cont=0;cont<3;cont++){
		printf("%d ",vet[cont] );
	}*/

	printf("\n%d\n",soma(vet,0,MAX-1) );

	return 0;
}

//o consumo de tempo deste algoritmo eh O(NlogN)