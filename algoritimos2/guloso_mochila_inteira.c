#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int peso;
	int lucro;
	char chave;
}item;

void copiastruct(item A[], item B[], int quant){
	int cont;
	for(cont=0;cont<quant;cont++){
		B[cont]=A[cont];
	}
}


int gulosomochila(item items[],int w, int quant){
	int peso=0, peso2=0, peso3=0, lucro=0, lucro2=0, lucro3=0;
	int cont,cont1,cont2,cont3;
	char affe[4][9];
	int maior;
	int aux, aux2, lucroaux, pesoaux;
	item structaux[quant];

//procura o melhor deles com peso como parametro
	copiastruct(items,structaux,quant);
	aux=quant;
	cont1=0;
	peso=0;
	lucro=0;
	aux2=0;
	lucroaux=0;
	while(peso<=w && aux>-1){
		maior=99;
		for(cont=0;cont<aux;cont++){
			if(maior>=structaux[cont].peso){
				if(maior==structaux[cont].peso){
					if(lucro<items[cont].lucro){
						maior=structaux[cont].peso;
						aux2=cont;
						//lucroaux=lucroaux+structaux[cont].lucro;
					}
				}
				else{
					maior=structaux[cont].peso;
					aux2=cont;
					//lucroaux=lucroaux+structaux[cont].lucro;
				}
			}
		}
		if(peso+structaux[aux2].peso<=w){
			lucro= lucro+structaux[aux2].lucro;
			peso=peso+structaux[aux2].peso;
			affe[0][cont1]=structaux[aux2].chave;
			cont1++;
			structaux[aux2]=structaux[aux];
			aux--;
		}
		else{
			structaux[aux2]=structaux[aux];
			aux--;
		}
	}


//procura o melhor deles com lucro como parametro
	copiastruct(items,structaux,quant);
	aux=quant;
	cont2=0;
	peso2=0;
	lucro2=0;
	aux2=0;
	pesoaux=0;
	while(peso2<=w && aux>-1){
		maior=0;
		for(cont=0;cont<aux;cont++){
			if(maior<=structaux[cont].lucro){
				if(maior==structaux[cont].lucro){
					if(peso2<items[cont].peso){
						maior=structaux[cont].lucro;
						aux2=cont;
						//peso2=structaux[cont].peso;
					}
				}
				else{
					maior=structaux[cont].lucro;
					aux2=cont;

				}
			}
		}
		if(peso2+structaux[aux2].peso<=w){
			lucro2= lucro2+structaux[aux2].lucro;
			peso2=peso2+structaux[aux2].peso;
			affe[1][cont2]=structaux[aux2].chave;
			cont2++;
			structaux[aux2]=structaux[aux];
			aux--;
		}
		else{
			structaux[aux2]=structaux[aux];
			aux--;
		}
	}

//procura o melhor deles com a media como parametro
	copiastruct(items,structaux,quant);
	aux=quant;
	cont3=0;
	peso3=0;
	lucro3=0;
	aux2=0;
	while(peso3<=w && aux>-1){
		maior=0;
		for(cont=0;cont<aux;cont++){
			if(maior<=(structaux[cont].lucro / structaux[cont].peso)){
				if(maior==(structaux[cont].lucro / structaux[cont].peso)){
					if(lucro<items[cont].lucro){
						maior=(structaux[cont].lucro / structaux[cont].peso);
						aux2=cont;
					}
				}
				else{
					maior=(structaux[cont].lucro / structaux[cont].peso);
					aux2=cont;
				}
			}
		}
		if(peso3+structaux[aux2].peso<=w){
			lucro3= lucro3+structaux[aux2].lucro;
			peso3=peso3+structaux[aux2].peso;
			affe[2][cont3]=structaux[aux2].chave;
			cont3++;
			structaux[aux2]=structaux[aux];
			aux--;
		}
		else{
			structaux[aux2]=structaux[aux];
			aux--;
		}
	}

	maior=0;
	int vet[3];
	vet[0]=lucro;
	vet[1]=lucro2;
	vet[2]=lucro3;
	for(cont=0;cont<3;cont++){
		if(maior<vet[cont]){
			maior=vet[cont];
		}
	}
	printf("por peso o lucro foi: %d| com peso: %d | com os items: ",lucro,peso );
	for(cont=0;cont<cont1;cont++){
		printf(" %c ",affe[0][cont] );
	}
	printf("\npor lucro o lucro foi: %d | com peso: %d | com os items: ",lucro2,peso2);
	for(cont=0;cont<cont2;cont++){
		printf(" %c ",affe[1][cont]);
	}
	printf("\npor media o lucro foi: %d | com peso: %d | com os items: ",lucro3,peso3 );
	for(cont=0;cont<cont3;cont++){
		printf(" %c ",affe[2][cont] );
	}

	return maior;

}


int main(void){
	item bugigangas[8];
	int cont=0;

	for(cont=0;cont<8;cont++){
	
		scanf(" %c %d %d",&bugigangas[cont].chave,&bugigangas[cont].lucro,&bugigangas[cont].peso);

	}
	//bubble_sort_lucro(bugigangas,8);
	/*for(cont=0;cont<8;cont++){
	
		printf("%c %d %d\n",bugigangas[cont].chave,bugigangas[cont].lucro,bugigangas[cont].peso);

	}*/
	//printf("%c %d %d\n",bugigangas[0].chave,bugigangas[0].lucro,bugigangas[0].peso );
	cont=gulosomochila(bugigangas,15,8);
	printf("\no melhor deles foi: %d\n",cont );

return 0;
}