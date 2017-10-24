#include <stdio.h>

int f91(int n){
	if(n>=101){
		return n-10;
	}
	else{
		return f91(f91(n+11));
	}
}

int main(void){

	int x=f91(91);

	printf("%d \n",x );

	return 0;
}