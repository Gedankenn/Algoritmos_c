#include <stdio.h>

int main(void){
	int MAX=510000;
	int vet[MAX];
	int cont;
	int soma=0;
	srand(time(NULL));
	for(cont=0;cont<MAX;cont++){
		vet[cont]=rand()%10;
	}
	for(cont=0;cont<MAX;cont++){
		soma=soma+vet[cont];
		printf("%d ",soma );
	}

	printf("\n%d\n",soma );

	return 0;
}