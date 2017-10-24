#include <stdio.h>

int goofy(int vetor[],int d,int max, int *aux[], int cont){
	int aux2=0;
	for(cont=0;cont<max;cont++){
		if(vetor[cont]>vetor[cont+1]){
			*aux[aux2]=vetor[cont];
			aux2++;
		}
		else *aux[aux2]=vetor[cont];
		}
	if(aux2>=d) return (aux, d, max, &aux, cont);
	
	else	return aux2;
}

int main(void){

	int max, d, cont;
	scanf("%d %d",&max,&d);
	int vetor[max], aux[d], aux2=0;

	for(cont=0;cont<max;cont++)
	scanf("%d",&vetor[cont]);
	cont=0;
	aux2=goofy(vetor,d,max,&aux,cont);
	
	
	for(cont=0;cont<aux2;cont++)
	printf("%d",aux[cont]);

return 0;
}
