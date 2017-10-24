#include <stdio.h>

int main(void){
	int cont=0;
	char num[50];

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