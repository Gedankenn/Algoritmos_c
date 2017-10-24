#include<stdio.h>

int imprime(int n){
	if(n == 0)
	return 0;
	printf("%d ",n);
	return imprime(n-1);
}
void decimprime(int n){
	if(n>0)
	decimprime(n-1);
	printf("%d ",n);
	
}
int contador(char vetor[], int q, int cont, int n){
	if(vetor[n]=='\0')
	return cont;
	if(vetor[n] == '2')
	cont++;
	//printf("%d ",cont);
	contador(vetor,q,cont,n+1);
}

int main(void){
	int n=3, q=2;
	char vetor[40];
	int cont=0;

	printf("%d ",imprime(n));
	printf("\n");
	decimprime(n);
	printf("\n");
	n=0;
	gets(vetor);
	printf("%d\n",contador(vetor,q,cont,n));	

	return 0;
}
