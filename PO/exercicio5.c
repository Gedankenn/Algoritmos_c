#include <stdio.h>

int main(void){
	char frase[]="batatinha quando nasce se esparrama pelo chao.";
	int cont=0, cont2=0;
	char aux;
	printf("%s\n",frase );
	
	while(frase[cont]!='\0')
	{
		if(frase[cont]=='a'){
			cont2++;
		}
		cont++;
	}
	printf("%d\n",cont2 );

	return 0;
}