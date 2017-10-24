#include <stdio.h>

int busca_maior(int *vet, int e, int d){
	int v1, v2;
	if(d-e<=1){
		if(vet[d]>vet[e]){
			return vet[d];
		}
		else{
			return vet[e];
		}
	}
	else{
		int m=(e+d)/2;
		v1=busca_maior(vet,e,m);
		v2=busca_maior(vet,m+1,d);
	}
	if(v1>v2){
		return v1;
	}
	else{
		return v2;
	}

}

int main(void){
	int vet[5]={1,9,3,4,5};

	int x=busca_maior(vet,0,4);
	printf("%d \n",x );

	return 0;
}