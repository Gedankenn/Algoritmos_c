#include <stdio.h>

int busca_binaria(int *vet, int ch, int inicio, int fim){
	if(fim<inicio){
		printf("elemento nao encontrado\n");
		return 0;
	}
	else{
		int meio=(inicio+fim)/2;
		if(vet[meio]==ch)
			return meio;
		if(vet[meio]>ch){
			return busca_binaria(vet,ch, inicio, meio-1);
		}
		else{
			return busca_binaria(vet,ch,meio+1,fim);
		}
	}
}


int main(void){
	int vet[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	for(i=0; i<10;i++){
		printf("%d ",vet[i] );
	}
	printf("\n");
	int chave=1;
	int b=busca_binaria(vet,chave,0,9);
	printf("%d\n",vet[b] );
	
	return 0;
}