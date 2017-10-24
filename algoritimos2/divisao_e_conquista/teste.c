#include <stdio.h>
#include <math.h>
#include <time.h>

int soma(int V[],int inicio, int fim){
	if(fim-inicio <= 1)
  		return (V[inicio]+V[fim])/(2-fim-inicio);
	else{
		int meio=(inicio+fim)/2;
		int v1=soma(V,inicio,meio);
		int v2=soma(V,meio+1,fim);
		return v1+v2;
	}
}

int main(void){
	int vet[3];
	int cont;
	srand((unsigned)time(NULL));
	for(cont=0;cont<3;cont++){
		vet[cont]=rand()%10;
	}
	for(cont=0;cont<3;cont++){
		printf("%d ",vet[cont] );
	}

	printf("\n%d\n",soma(vet,0,2) );

	return 0;
}