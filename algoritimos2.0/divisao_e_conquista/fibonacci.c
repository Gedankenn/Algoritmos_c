#include <stdio.h>
#include <time.h>

int fibonacci_recursivo(int n){
	if(n<1){
		return 1;
	}
	else{
		return (fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2));
	}
}

void fibonacci_iterativo(int n){
	int cont=0;
	int atual=1;
	int anterior=1;
	int prox=1;
	while(cont<n){
		prox=anterior+atual;
		anterior=atual;
		atual=prox;
		cont++;
	}
	printf("fibonacci_iterativo: %d\n",prox );
}

int main(void){

	int n=3;
	float Tf, Ti;
	int r;

	srand((unsigned)time(NULL));

	Ti=clock();
	r=fibonacci_recursivo(n);
	Tf=clock();
	printf("fibonacci recursivo: %d |com tempo: %f\n",r, (Tf-Ti)/1000 );

	Ti=clock();
	fibonacci_iterativo(n);
	Tf=clock();
	printf("iterativo com tempo: %f\n",(Tf-Ti)/1000 );

	return 0;
}