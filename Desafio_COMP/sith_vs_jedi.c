#include <stdio.h>

int main(void){
	int n, cont, aux;

	scanf("%d",&n);
	while(n<0 || n>101){
		scanf("%d",&n);
	}

	cont=0;
	while(cont<n){

		scanf("%d",&aux);
		while(aux<-1 || aux>1001){
			scanf("%d",&aux);
		}

		if(aux==0){
			printf("Jedi\n");
		}
		else if(aux%2==0){
			printf("Jedi\n");
		}
		else{
			printf("Sith\n");
		}
		cont++;
	}


	return 0;
}