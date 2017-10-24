#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define total 180


int main(void){
	char respostas[total], cobaia1[total], cobaia2[total], cobaia3[total], cobaia4[total], cobaia5[total], cobaia6[total];
	float p1=0,p2=0,p3=0,p4=0,p5=0, p6=0;
	float t1,t2,t3,t4,t5,t6;
	int cont2=0, cont=0;
	srand((unsigned)time(NULL));

	while(cont<total){
		respostas[cont]=(rand()%5) +65;
		cobaia1[cont]='A';
		cobaia2[cont]='B';
		cobaia3[cont]='C';
		cobaia4[cont]='D';
		cobaia5[cont]='E';
		cont++;
	}
	cont=0;
	while(cont<total){
		cobaia6[cont]=(rand()%5) +65;
		cont++;
	}
	while(cont2<1000){
		cont=0;
		while(cont<total){
			respostas[cont]=(rand()%5) +65;
			cont++;
		}
		cont=0;
		while(cont<total){
			cobaia6[cont]=(rand()%5) +65;
			cont++;
		}

	
		cont=0;

		while(cont<total){
			if(cobaia1[cont]==respostas[cont]){
				p1++;
			}
			if(cobaia2[cont]==respostas[cont]){
				p2++;
			}
			if(cobaia3[cont]==respostas[cont]){
				p3++;
			}
			if(cobaia4[cont]==respostas[cont]){
				p4++;
			}
			if(cobaia5[cont]==respostas[cont]){
				p5++;
			}
			if(cobaia6[cont]==respostas[cont]){
				p6++;
			}

			cont++;
		}
		cont2++;
	}
	t1=p1/(total*1000.0);
	t2=p2/(total*1000.0);
	t3=p3/(total*1000.0);
	t4=p4/(total*1000.0);
	t5=p5/(total*1000.0);
	t6=p6/(total*1000.0);

	
	printf("A = %f \nB = %f \nC = %f \nD = %f \nE = %f \nAleatorio = %f\n",t1,t2,t3,t4,t5,t6 );


	return 0;
}