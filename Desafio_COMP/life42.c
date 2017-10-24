#include <stdio.h>

int main(void){
	int num;

	scanf("%d",&num);
	while(num>100 || num<-100){
		scanf("%d",&num);
	}
	while(num!=42){
		printf("%d\n",num );
		scanf("%d",&num);
		while(num>100 || num<-100){
			scanf("%d",&num);
		}
	}


	return 0;
}