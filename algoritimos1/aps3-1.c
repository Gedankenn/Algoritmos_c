#include <stdio.h>
void determina(int *maior, int *menor, int *num){
	if(*num > *maior)
		*maior = *num;
	if(*num < *menor)
		*menor = *num;
}


int main(void){

	int n=1, maior, menor;
	while(n != 0)
	{
		scanf("%d",&n);
		determina(&maior,&menor,&n);
	}
	printf("maior = %d\nmenor = %d\n",maior,menor);
}
