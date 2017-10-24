#include <stdio.h>

int main(void){
	int num, impar, cont;

	num=16;
	impar=1;
	cont=0;
	while(num>0){
		num=num-impar;
		impar=impar+2;
		cont++;
	}
	printf("%d\n",cont );

	return 0;
}