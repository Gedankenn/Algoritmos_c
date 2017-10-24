#include <stdio.h>

int soma(int num){
	if(num==1){
		return 1;
	}
	else{
		return (soma(num-1)+num);
	}
}

int main(void){
	int num;
	scanf("%d",&num);
	printf("%d\n",soma(num) );
	return 0;
}