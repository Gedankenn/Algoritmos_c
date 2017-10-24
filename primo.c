#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void){
	int num, cont;
	clock_t Ti,Tf;

	scanf("%d",&num);

	Ti=clock();
	cont=2;
	int cont2=2;
	int raiz=2;
	int aux;
	float delta;
	printf("2 ");
	while(cont<=num){
		raiz=1;
		cont2=2;
		aux=0;
		while(raiz*raiz<cont){
			raiz++;
		}
		while(cont2<=raiz){
			if(cont%cont2==0){
				aux=1;
				cont2=raiz;
			}
			cont2++;
		}
		if(aux==0){
			//printf("%d ",cont );
		}
		cont++;
	}
	Tf=clock();
	delta=Tf-Ti;
	delta=delta/1000;
	printf("\n\n%f\n",delta );
	return 0;
}