#include <stdio.h>
#include <time.h>

int fatorial_recursivo(int n){
	if(n==1){
		return 1;
	}
	else{
		return fatorial_recursivo(n-1)*n;
	}
}

void fatorial_iterativo(int n){
	int cont=1;
	int fat=1;
	while(cont<=n){
		fat=fat*cont;
		cont++;
	}
	printf("fatorial iterativo: %d",fat );

}

int main(void){
	clock_t Tf, Ti;
	int fat;
	int n=15;

	srand((unsigned)time(NULL));

	Ti=clock();
	fat=fatorial_recursivo(n);
	Tf=clock();
	printf("Fatorial recursivo: %d| tempo: %f\n",fat, (Tf-Ti)/1000 );

	Ti=clock();
	fatorial_iterativo(n);
	Tf=clock();
	printf("| tempo: %f\n",(Tf -Ti)/1000);


	return 0;
}