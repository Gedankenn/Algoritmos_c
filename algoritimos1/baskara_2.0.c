#include <stdio.h>
#include <math.h>

float raiz(float num){
	float cont=0;
	while((cont*cont)<num){
		cont=cont+0.0001;
	}
	return cont;
}

int main(void){
	float a, b, c, delta1, x1, x2;
	scanf("%f %f %f",&a,&b,&c);

	delta1=(b*b)-(4*a*c);
	if(delta1<0){
		printf("%f\n",delta1 );
		printf("nao tem raiz\n");
	}
	else{
		x1=raiz(delta1);
		x2=x1;
		x1=(-b-x1)/(2*a);
		x2=(-b+x2)/(2*a);
		printf("x1=%.2f  x2=%.2f\n",x1,x2);
	}

	return 0;
}