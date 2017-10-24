//projeto estudo metodos gulosos - mochila

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
	int peso;
	int lucro;
	char item;
}muamba;

void copiastruct(muamba *M, muamba *N, int tam){
	tam=tam-1;
	while(tam>=0){
		N[tam]=M[tam];
		tam--;
	}
}

void lucro(muamba *M, int tam, int P, int *a, int *b){
	muamba N[tam];
	copiastruct(M,N,tam);
	int cont=0, peso_total=0, lucro=0, i=0, lucro_total=0, cont2=tam, fim=0;
	while(peso_total<P && fim==0){
		cont=0;
		i=-1;
		lucro=0;
		while(cont<tam && fim==0){
			if(N[cont].lucro>=lucro && (N[cont].peso+peso_total)<=P){
				if(N[cont].lucro==lucro){	
					if(N[cont].peso<N[i].peso){
						//printf("%c\n",N[cont].item );
						lucro=N[cont].lucro;
						i=cont;
					}
				}
				else{
					lucro=N[cont].lucro;
					i=cont;
				}	
			}
			cont++;
		}
		if(i!=-1){
			//printf("%c\n",N[i].item);
			lucro_total=lucro_total+lucro;
			peso_total=N[i].peso+peso_total;
			N[i]=N[tam-1];
			tam--;
		}
		else{
			fim=1;
		}
		cont2++;
	}
					//peso          //lucro
	printf("1,%d,%d,",peso_total,lucro_total);
	*a=peso_total;
	*b=lucro_total;
}

void peso(muamba *M, int tam, int P, int *a, int *b){
	muamba N[tam];
	copiastruct(M,N,tam);
	int cont=0, peso_total=0, peso=0, i=-1, lucro_total=0, cont2=tam, fim=0;

	while(peso_total<P && fim==0){
		cont=0;
		i=-1;
		peso=9999999;
		while(cont<tam){
			if(N[cont].peso<=peso && N[cont].peso+peso_total<=P){
				if(N[cont].peso==peso){
					if(N[cont].lucro>N[i].lucro){
						peso=N[cont].peso;
						i=cont;
					}
				}
				else{
					peso=N[cont].peso;
					i=cont;
				}
			}
			cont++;
		}
		if(i!=-1){
			//printf("%c\n",N[i].item);
			lucro_total=lucro_total+N[i].lucro;
			peso_total=N[i].peso+peso_total;
			N[i]=N[tam-1];
			tam--;
		}
		else{
			fim=1;
		}
	}
	printf("2,%d,%d,",peso_total,lucro_total);
	*a=peso_total;
	*b=lucro_total;
}

void relacao_lucro_peso(muamba *M, int tam, int P, int *a, int *b){
	muamba N[tam];
	copiastruct(M,N,tam);
	int cont=0, peso_total=0, i=-1, lucro_total=0, cont2=tam, fim=0;
	float media;

	while(peso_total<P && fim==0){
		cont=0;
		i=-1;
		media=-1;
		while(cont<tam){
			if((float)N[cont].lucro/(float)N[cont].peso>=media && N[cont].peso+peso_total<=P){
				if((float)N[cont].lucro/(float)N[cont].peso==media){
					if(N[cont].peso<N[i].peso){
						media=(float)N[cont].lucro/(float)N[cont].peso;
						i=cont;
					}
				}
				else{
					media=(float)N[cont].lucro/(float)N[cont].peso;
					i=cont;
				}
			}
			cont++;
		}
		if(i!=-1){
			//printf("%c\n",N[i].item );
			lucro_total=lucro_total+N[i].lucro;
			peso_total=N[i].peso+peso_total;
			N[i]=N[tam-1];
			tam--;
		}
		else{
			fim=1;
		}
	}
	printf("3,%d,%d,",peso_total,lucro_total);
	*a=peso_total;
	*b=lucro_total;
}



int main(void){
	srand((unsigned)time(NULL));
	int tam=10, cont, cont2, aux=0;
	int repeticoes=10000000;
	int peso_max=20;
	int lpeso=0, llucro=0, ppeso=0, plucro=0, mlucro=0, mpeso=0;
	int melhor1=0, melhor2=0, melhor3=0;
	muamba loja1[tam];

	while(aux<repeticoes){
		//srand((unsigned)time(NULL));
		cont=0;
		cont2=65;
		while(cont<tam){
			loja1[cont].item=cont2;
			loja1[cont].peso=(rand()%10+1);
			loja1[cont].lucro=(rand()%20)+1;
			cont++;
			cont2++;
		}

		/*cont=0;
		while(cont<tam){
			printf("item: %c | peso: %d | lucro: %d\n",loja1[cont].item, loja1[cont].peso, loja1[cont].lucro );
			cont++;
		}
		cont=0;*/
		//printf("\n");
		
		lucro(loja1,tam,peso_max,&lpeso,&llucro);
		peso(loja1,tam,peso_max,&ppeso,&plucro);
		relacao_lucro_peso(loja1,tam,peso_max,&mpeso,&mlucro);
		printf("\n");
		//printf("ponteiros, %d %d\n",lpeso, llucro );
		aux++;

		if(llucro>plucro && llucro>mlucro){
			melhor1++;
		}
		if(plucro>llucro && plucro>mlucro){
			melhor2++;
		}
		if(mlucro>plucro && mlucro>llucro){
			melhor3++;
		}
	}

	printf("foram melhores\n");
	printf("por lucro: %d vezes\npor peso: %d\npor media:%d\n",melhor1,melhor2,melhor3);
	printf("lucro: %d%%\npeso: %d%%\nmedia: %d%%\n",((melhor1*100)/repeticoes),((melhor2*100)/repeticoes),((melhor3*100)/repeticoes) );

	return 0;
}