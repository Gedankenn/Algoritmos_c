#include <stdio.h>

int soma(int *vet, int e, int d){
	int v1, v2;
	if(d-e<1){
		return vet[e];
	}
	if(d-e==1){
		return (vet[e]+vet[d]);
	}
	else{
		int m=(e+d)/2;
		v1=soma(vet,e,m);
		v2=soma(vet,m+1,d);
	}
	return v1+v2;

}

int main(void){
	int vet[5]={1,2,3,4,5};

	int x=soma(vet,0,4);
	printf("%d \n",x );

	return 0;
}