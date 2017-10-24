#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, int orig, int dest, int temp, long int *cont, FILE *txt){
	if(n==1){
		//printf("mova o menor pino para o pino %d\n",dest);
		*cont=*cont+1;
	}
	else{
	hanoi(n-1,orig,temp,dest,cont,txt);
	//printf("mover o disco %d do pino %d para o pino %d ",n,orig,dest);
	*cont=*cont+1;
	hanoi(n-1,temp,dest,orig,cont,txt);
	}
	if(*cont>2147483640){
		fprintf(txt, "+%ld\n",*cont );
		cont=0;
	}
	//printf("%d\n",*cont );
}


int main(void){
	int num;
	long int cont=0;
	float initime, endtime, timetot;
	scanf("%d",&num);

	FILE *txt;

	txt=fopen("data_hanoi_2","a+");

	initime=clock();
	hanoi(num,1,2,3,&cont,txt);
	endtime=clock();
	timetot=(endtime - initime)/1000;
	fprintf(txt,"|tamanho: %d | iteracoes: +%ld | tempo: %f\n\n",num,cont,timetot);


	return 0;
}
