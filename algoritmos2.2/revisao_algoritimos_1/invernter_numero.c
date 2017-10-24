#include <stdio.h>

int main(void){
	char num[50];
	int cont=0;

	scanf("%s",&num);

	while(num[cont]!='\0'){
		cont++;
	}
	cont--;
	while(cont>=0){
		printf("%c",num[cont] );
		cont--;
	}

	return 0;
}