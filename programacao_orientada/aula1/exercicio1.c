#include <stdio.h>

float fatorial(float num){
	int total=1;
	while(num>0){
		total=total*num;
		num--;
	}
	return total;
}

int main(void){
	float total=0, cont=0;
	while(cont<15){
		total=total+(1/fatorial(cont));
		cont++;
	}
	printf("%f\n",total );
	return 0;
}