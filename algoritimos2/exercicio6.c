#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x, y;
}ponto;

float distancia(ponto a, ponto b){
	float dist1, dist2;
	dist1=b.x-a.x;
	dist1=dist1*dist1;
	dist2=b.y-a.y;
	dist2=dist2*dist2;

	return sqrt(dist1 + dist2);
}

int main(void){
	ponto a, b;
	a.x=1;
	a.y=1;
	b.x=4;
	b.y=5;

	float modulo;

	modulo=distancia(a,b);
	printf("%f\n",modulo );

	return 0;
}