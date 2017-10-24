#include <stdio.h>

int main(void){
	
	int num, cont, cont2, sub;
	scanf("%d",&num);

	cont=1;
	cont2=3;

	sub=num-1;
	while(sub>0){
		sub=sub-cont2;
		cont2=cont2+2;
		cont++;
	}

	if(sub==0){
		printf("a raiz quadrada exata = %d\n",cont );
	}
	else{
		printf("a raiz quadrada aproxima = %d\n",cont );
	}

	return 0;
}