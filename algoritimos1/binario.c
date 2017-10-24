#include<stdio.h>
#include<stdio.h>

int binario(int k){
	if(k<2) 
	return (k);
	
	return (10*binario(k/2))+k%2;
}

int main(void){
	int k=12, r=0;
	printf("%d\n",binario(k));
	return 0;
}

