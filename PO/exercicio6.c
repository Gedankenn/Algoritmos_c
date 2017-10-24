#include <stdio.h>

int compara(char *S1, char *S2){
	int cont=0;
	while(S1[cont]!='\0' && S2[cont]!='\0'){
		if(S1[cont]==S2[cont]){
			cont++;
		}
		else{
			return 0;
		}
	}
	return 1;
}


int main(void){
	char S1[]="fabio", S2[]="fabio";
	int cont;
	//printf("%d\n",compara(S1,S2) );
	cont=compara(S1,S2);
	if(cont==0){
		printf("as Strings nao sao iguais\n");
	}
	else
		printf("As strings sao iguais\n");
	return 0;
}
