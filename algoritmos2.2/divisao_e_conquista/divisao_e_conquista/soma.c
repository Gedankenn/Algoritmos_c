#include <stdio.h>
#include <time.h>

long int somarecursiva(long int n){
	if(n==1){
		return n;
	}
	else{
		return somarecursiva(n-1)+n;
	}
}
long int somagauss(long int n){
	return ((n*(n+1))/2);
}

int main(void){
	clock_t Ti, Tf;
	long int num=50000;
	float delta;
	srand((unsigned)time(NULL));
	long int s1;
	//recursiva
	Ti=clock();
	s1=somarecursiva(num);
	Tf=clock();
	delta=(Tf-Ti)/1000;
	printf("soma recursiva: %lo| com tempo: %f\n",s1, delta );

	//gauss
	Ti=clock();
	s1=somagauss(num);
	Tf=clock();
	delta=(Tf-Ti)/1000;
	printf("soma gauss: %lo| com tempo: %f\n",s1, delta );


	return 0;	
}