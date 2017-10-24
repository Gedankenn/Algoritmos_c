#include <stdio.h>
#include <time.h>

int fibonacci(int n){
	if(n<=1){
		return 1;
	}
	else{
		return (fibonacci(n-1) + fibonacci(n-2));
	}
}

int main(void){
	int num;
	float Tf, Ti;
	scanf("%d",&num);
	Ti=clock();
	printf("%d \n",fibonacci(num));
	Tf=clock();

	printf("%f\n",(Tf-Ti)/1000.0 );


	return 0;
}