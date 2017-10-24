#include <stdio.h>
#include <time.h>



int	fibonacci_dinamico(unsigned long int vet[], unsigned long int n){
	if (vet[n]!=-1){
		return vet[n];
	}
	if(n<=1){
		return 1;
	}
	else{
		return vet[n]=fibonacci_dinamico(vet,n-1) + fibonacci_dinamico(vet,n-2);
	}
}

int main(void){
	unsigned long int num;
	scanf("%d",&num);
	unsigned long int vet[num];
	int cont;
	float Ti, Tf;
	for(cont=0;cont<=num;cont++){
		vet[cont]=-1;
	}
	Ti=clock();
	printf("%li\n",fibonacci_dinamico(vet,num) );
	Tf=clock();
	printf("tempo de:%f\n",(Tf-Ti)/1000.0 );

	return 0;
}