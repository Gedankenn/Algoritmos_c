#include <stdio.h>

typedef struct{
	float altura;
	float peso;
}corpo;

typedef struct{
	corpo humano1;
	corpo humano2;
}casal;



int main(void){
	corpo fabio;
	casal suruba[10];

	fabio.altura=2.15;

	//printf("a altura de fabio eh: %.2f\n",fabio.altura );

	suruba[0].humano1.altura=1.63;
	suruba[0].humano1.peso=900;
	suruba[0].humano2.altura=2.15;
	suruba[0].humano2.peso=60;

	printf("altura de akila: %.2f \n",suruba[0].humano1.altura);
	printf("peso de akila: %.2f :ps: BALEIA <3\n",suruba[0].humano1.peso );
	printf("altura de fabio: %.2f\n",suruba[0].humano2.altura );
	printf("peso de fabio: %.2f\n",suruba[0].humano2.peso );

	return 0;
}