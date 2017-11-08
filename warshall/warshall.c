#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int i, j, aux, cont, cont2, cont3;
	FILE *matriz;
	clock_t Ti, Tf;


	matriz=fopen("matriz.txt","r");
	fscanf(matriz,"%d %d",&i,&j);
	int w[i][j];

	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			fscanf(matriz,"%d",&aux);
			w[cont][cont2]=aux;
		}
	}

	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			printf("%d ",w[cont][cont2]);
		}
		printf("\n");
	}
	aux=0;
	while(aux<i){
		printf("--");
		aux++;
	}
	printf("\n");

	/*
	versao antiga

	aux=0;
	while(aux<i){
		for(cont=0;cont<i;cont++){
			for(cont2=0;cont2<j;cont2++){
				if(w[cont][cont2]==1){
					cont3=0;
					while(cont3<j){
						if(w[cont2][cont3]==1){
							w[cont][cont3]=1;
						}
						cont3++;
					}
				}
			}
		}

		aux++;
	}
	*/

	//otimizado
	Ti=clock();
	aux=0;
	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			if(w[cont][cont2]==1){
				for(cont3=0;cont3<j;cont3++){
					if(w[cont2][cont3]==1){
						w[cont][cont3]=1;
					}
				}
			}
		}
	}
	Tf=clock();

	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			printf("%d ",w[cont][cont2]);
		}
		printf("\n");
	}
	printf("tempo: %f\n",(Tf-Ti) );

	fclose(matriz);
	return 0;
}