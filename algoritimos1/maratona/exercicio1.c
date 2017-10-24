#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int vetor1[8], vetor2[8], vetor3[8];
	int cont;

	for(cont=0;cont<8;cont++){
		scanf("%d %d",&vetor1[cont],&vetor1[cont+1]);
		cont++;
	}

	for(cont=0;cont<8;cont++){
		scanf("%d %d",&vetor2[cont],&vetor2[cont+1]);
		cont++;
	}

	int intersecao;
	int dist1, dist2, dist3, dist4;
	dist1=vetor2[0] - vetor1[6];
	dist2=vetor2[3] - vetor1[1];
	intersecao=dist1 * dist2;
	printf("\n");
	if(intersecao<0){
		intersecao=intersecao*-1;
	}
	printf("\n%d\n",intersecao );

	return 0;
}