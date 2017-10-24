#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j, coluna, linha, cont, cont2, aux;
	double x;
	FILE *matriz;

	matriz=fopen("matriz.txt","r");

	fscanf(matriz,"%d %d",&i,&j);

	double M[i][j];

	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			fscanf(matriz,"%lf",&x);
			M[cont][cont2]=x;
		}
	}
	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			printf("%.2lf ",M[cont][cont2] );
		}
		printf("\n");
	}

	//escalonamento da matriz
	aux=0;
	cont=0;
	cont2=0;
	coluna=0;
	linha=0;
	x=0;

	while(coluna<j){
		linha=cont+1;
		while(linha<i){
			if(M[cont][coluna]!=0){
				x=M[linha][coluna]/M[cont][coluna];
				x=x*-1;
				aux=coluna;
				while(aux<j){
					M[linha][aux]=M[cont][aux]*x + M[linha][aux];
					aux++;
				}
				for(cont2=0;cont2<i;cont2++){
					for(aux=0;aux<j;aux++){
						printf("|%.2lf|",M[cont2][aux] );
					}
					printf("\n");
				}
				printf("\n");
			}
			linha++;
		}
		cont++;
		coluna++;
	}

	//voltando
	//j=j-1;
	//i=i-1;
	printf("voltando\n");
	coluna--;
	linha--;
	cont--;
	while(coluna>=0){
		linha=cont-1;
		while(linha>=0){
			if(M[cont][coluna]!=0){
				x=M[linha][coluna]/M[cont][coluna];
				x=x*-1;
				aux=coluna;
				while(aux<j){
					M[linha][aux]=M[cont][aux]*x + M[linha][aux];
					aux++;
				}
				for(cont2=0;cont2<i;cont2++){
					for(aux=0;aux<j;aux++){
						printf("|%.2lf|",M[cont2][aux] );
					}
					printf("\n");
				}
				printf("\n");
			}
			linha--;
		}
		cont--;
		coluna--;
	}

	printf("escalonada:\n");
	for(cont=0;cont<i;cont++){
		for(cont2=0;cont2<j;cont2++){
			printf("|%.2lf| ",M[cont][cont2] );
		}
		printf("\n");
	}
	if(j>=i){
		printf("solucionando sistema:\n");
		for(cont=0;cont<i;cont++){
			x=M[cont][cont];
			for(cont2=0;cont2<j;cont2++){
				M[cont][cont2]=M[cont][cont2]/x;
				printf("|%.2lf| ",M[cont][cont2] );
			}
			printf("\n");
		}
	}



	fclose(matriz);
	return 0;
}