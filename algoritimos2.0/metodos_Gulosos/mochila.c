#include <stdio.h>
int pmochila=15; 
int tam=8;

typedef struct{
	int peso;
	int lucro;
	char item;
}muamba;

void copiastruct(muamba *M, muamba *N){
	int i;
	while(i<tam){
		N[i]=M[i];
		i++;
	}
}

void gulosopeso(muamba *M){
	int i;
	int maior, peso, lucro, total;
	muamba N[tam];

	copiastruct(M,N);

	i=0;
	peso=0;
	lucro=0;
	total=0;
	int p=999;
	int cont=0;
	int aux;
	int auxt=tam;
	while(peso <= pmochila && cont<8){
		i=0;
		aux=-1;
		p=9999;
		while(i<auxt){
			if(p>N[i].peso && N[i].peso+peso <= pmochila){
				p=N[i].peso;
				aux=i;
			}
			i++;
		}
		if(aux!=-1){
			printf("%c %d %d\n",N[aux].item, N[aux].lucro, N[aux].peso );
			peso=peso+N[aux].peso;
			lucro=lucro+N[aux].lucro;
			N[aux]=N[auxt];
			auxt--;
		}
		cont++;

	}
	printf("lucro total: %d\npeso total: %d\n",lucro, peso );
}

void gulosolucro(muamba *M){
	int i;
	int maior, peso, lucro, total;
	muamba N[tam];

	copiastruct(M,N);

	i=0;
	peso=0;
	lucro=0;
	total=0;
	int p=0;
	int cont=0;
	int aux;
	int auxt=tam;

	while(peso <= pmochila && cont<8){
		i=0;
		aux=-1;
		p=0;
		while(i<auxt){
			if(p<N[i].lucro && N[i].peso+peso <= pmochila){
				p=N[i].lucro;
				aux=i;
			}
			i++;
		}
		if(aux!=-1){
			printf("%c %d %d\n",N[aux].item, N[aux].lucro, N[aux].peso );
			peso=peso+N[aux].peso;
			lucro=lucro+N[aux].lucro;
			N[aux]=N[auxt];
			auxt--;
		}
		cont++;

	}
	printf("lucro total: %d\npeso total: %d\n",lucro, peso );

}

void gulosomedia(muamba *M){
	int i;
	int maior, peso, lucro;
	muamba N[tam];

	copiastruct(M,N);

	i=0;
	peso=0;
	lucro=0;
	int p=0;
	int cont=0;
	int aux;
	int auxt=tam;

	while(peso <= pmochila && cont<8){
		i=0;
		aux=-1;
		p=0;
		while(i<auxt){
			if(p<(N[i].lucro/N[i].peso) && N[i].peso+peso <= pmochila){
				p=N[i].lucro/N[i].peso;
				aux=i;
			}
			i++;
		}
		if(aux!=-1){
			printf("%c %d %d\n",N[aux].item, N[aux].lucro, N[aux].peso );
			peso=peso+N[aux].peso;
			lucro=lucro+N[aux].lucro;
			N[aux]=N[auxt];
			auxt--;
		}
		cont++;

	}
	printf("lucro total: %d\npeso total: %d\n",lucro, peso );
}

int main(void){
	muamba lojinha[tam];
	int i=0;

	while(i<tam){
		scanf(" %c %d %d",&lojinha[i].item, &lojinha[i].lucro, &lojinha[i].peso);
		i++;
	}

	i=0;
	while(i<tam){
		printf("%c %d %d\n",lojinha[i].item, lojinha[i].lucro, lojinha[i].peso );
		i++;
	}
	printf("--------------------------------\n");
	gulosopeso(lojinha);
	printf("--------------------------------\n");
	gulosolucro(lojinha);
	printf("--------------------------------\n");
	gulosomedia(lojinha);

	return 0;
}