#include <stdio.h>

int soma(int V[], int tam){
	if(tam==0){
		return V[tam];
	}
	else{
		return V[tam]+soma(V,tam-1);
	}
}

int main(void){
	int MAX=510000;
	int vet[MAX];
	int cont;
	srand((unsigned)time(NULL));
	for(cont=0;cont<MAX;cont++){
		vet[cont]=rand()%10;
	}
	/*for(cont=0;cont<3;cont++){
		printf("%d ",vet[cont] );
	}*/

	printf("\n%d\n",soma(vet,MAX-1) );

	return 0;
}

// a complexidade desse algoritmo eh O(2N)