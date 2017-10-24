#include <stdio.h>
#include <math.h>

float deltacalc(float a, float b, float c, float k)
{
	float i=0.000000;
	while((i*i)<k)
	i=i+0.000001;

	return(i);
}

int main( )
{
	float a, b, c, delta, k, x1, x2;
        scanf("%f %f %f",&a,&b,&c);
	k=(b*b)-(4*a*c);
	printf("k= %f\n",k);
	if(k<0)
	printf("sem resposta\n");

	else
	{
		delta=deltacalc(a,b,c,k);

		printf("%f\n",delta);	
		x1=((-b)- delta)/(2*a);
		x2=((-b)+ delta)/(2*a);

		printf("x1= %f\nx2= %f\n",x1,x2);
	}
	return(0);
}

