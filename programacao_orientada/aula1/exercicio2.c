#include <stdio.h>
#include <stdlib.h>

//nois faiz gambi mesmo
int main(void){
	int num, cont=0, m2=0, m3=0;
	char gambi[50];

	scanf("%s",&gambi);

	num=*gambi;
	printf("numero informado pelo usuario: %s\n",gambi );

	while(gambi[cont]!='\0'){
		num=gambi[cont];
		if(num%2==0){
			m2++;
		}
		if(num%3==0){
			m3++;
		}
		cont++;
	}

	printf("quantidade de algarismos: %d\n",cont );
	printf("quantidade de algarismos multiplos de 2: %d\n",m2 );
	printf("quantidade de algarismos multiplos de 3: %d\n",m3 );

	return 0;
}