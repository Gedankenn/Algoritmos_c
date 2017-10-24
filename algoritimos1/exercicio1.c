#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct{
	char letras[3];
}Letras;

typedef struct{
	Letras numero;
	int posicao;
}Teclado;

int main(void){
	char num[10];
	int cont,i=0, l=0, tabela=95;
	float possibilidades;
	scanf("%s",num);
	cont = strlen(num);
	Teclado teclado[cont];
	//printf("%d",cont);
	int Num[cont];
	
	possibilidades=POW(3,cont);
	for(l=0;l<possibilidades;l++){
		while(i<cont){
			printf("%c",(tabela+num[cont]+l));
			cont++;
			}
		}				
	


return 0;
}
