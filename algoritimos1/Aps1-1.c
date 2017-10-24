#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tam;
	scanf("%d",&tam);
	getchar();
	char vetor[tam];
	gets(vetor);
	printf("%s",vetor);

	int q=0;
	int num1=0, num2=0;
	for(q=0;q<tam;q++)
	{
		if(vetor[q]=='0')
			num1++;
		else
		num2++;
	}
	printf("\n0s %d e 1s %d\n",num1,num2);
	return(0);
}
