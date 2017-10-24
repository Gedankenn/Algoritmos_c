#include <stdio.h>
typedef struct{
	char estrada;
	float km;
	float pedagio;
	float consumo;
}viagem;

typedef struct{
	int pedagio;
	float consumos;
}mochilao;


void BornToBeWild (viagem escolha, mochilao *valores, float combustivel, float Ppedagio, float *preco){
	valores->pedagio = escolha.km / escolha.pedagio;
	valores->consumos = escolha.km / escolha.consumo;
	*preco = (valores->pedagio * Ppedagio) +  (valores->consumos * combustivel);
}

int main(void){
	viagem escolha[4];
	mochilao valores[4];
	int n;
	float combustivel,  Ppedagio, preco;
	scanf("%f %f",&combustivel, &Ppedagio);
	for(n=0;n<4;n++)
	{
		scanf(" %c",&escolha[n].estrada);
		scanf("%f %f %f",&escolha[n].km, &escolha[n].pedagio, &escolha[n].consumo);
	}
        printf("estrada  |   km total    |  distancia  |  consumo  | pedagios | consumo gasosa  | valor viagem\n");
	for(n=0;n<4;n++)
	{
		BornToBeWild(escolha[n],&valores[n],combustivel, Ppedagio, &preco);
		printf("%c       |      %.2f       |     %.2f      |   %.2f  | %d   | %.2f | %.2f\n",escolha[n].estrada, escolha[n].km, escolha[n].pedagio, escolha[n].consumo,valores[n].pedagio, valores[n].consumos, preco);
	}

return 0;
}
