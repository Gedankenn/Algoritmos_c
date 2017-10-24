#include <stdio.h>

int potencia(int a, int b){
	if(b==0){
		return 1;
	}
	else{
		return (potencia(a,b-1)*a);
	}
}

int main(void){
	int num, pot;
	scanf("%d %d",&num,&pot);
	printf("%d\n",potencia(num,pot) );
	return 0;
}