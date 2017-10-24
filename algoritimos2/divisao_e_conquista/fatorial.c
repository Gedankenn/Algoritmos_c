#include <stdio.h>

int fatorial(int N){
	if(N==0){
		return 1;
	}
	else
		return (fatorial(N-1)*N);
}

int main(void){
	int num;
	scanf("%d",&num);
	printf("%d\n",fatorial(num) );
	return 0;
}