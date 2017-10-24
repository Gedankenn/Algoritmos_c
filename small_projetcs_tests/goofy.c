#include <stdio.h>

int main(void){
	int vetor[10], novo_vetor[10];
	int num_digitos, num_remove;
	int cont, cont2, cont3, aux, maior=0, aux2;

	/*vetor[0]=1;
	vetor[1]=2;
	vetor[2]=3;
	vetor[3]=1;
	vetor[4]=2;
	num_remove=3;
	num_digitos=5;
	*/

	scanf("%d %d",&num_digitos,&num_remove);
	for (cont = 0; cont < num_digitos; cont++)
	{
		scanf("%d",&vetor[cont]);
	}

	cont3=0;
	cont2=0;
	aux2=num_remove;
	for(cont=0;cont<aux2;cont++){
		maior=0;
		for(cont2;cont2<=num_digitos - num_remove;cont2++){
			if(vetor[cont2]>maior){
				maior=vetor[cont2];
				aux=cont2;
			}
		}
		novo_vetor[cont3]=maior;
		cont3++;
		num_remove--;
		cont2=aux+1;
	}

	for(cont=0;cont<aux2;cont++){
		printf("%d ",novo_vetor[cont] );
	}

	return 0;
}