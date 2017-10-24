#include <stdio.h>

int potencia_recursiva(a,n){
	if(n==0){
		return 1;
	}
	else if(n==1){
		return a;
	}
	else{
		int x=potencia_recursiva(a,n/2);
		if(n-(n/2)*2==0){
			return x*x;
		}
		else{
			return a*x*x;
		}
	}
}

int main(void){
	int a=3, n=3;
	int pot=potencia_recursiva(a,n);

	printf("potencia de %d^%d = %d\n",a,n,pot );
	
	return 0;
}