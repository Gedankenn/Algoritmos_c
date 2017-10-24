#include <stdio.h>

int main(void){
	char A[15], B[15];
	scanf("%[^\n]",&A);
	getchar();

	B=A;
	printf("%s",B);
	return 0;
}