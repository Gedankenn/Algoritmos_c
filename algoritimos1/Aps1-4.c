#include <stdio.h>

int main()
{
	struct pessoa {
	
		char nome[50];
		int peso;
		int idade;
	};
		
	struct pessoa pessoas[100];
	char continua='s';
	int q=0;
	while(continua == 's')
	{
		gets(pessoas[q].nome);
		scanf("%d",&pessoas[q].peso);
		scanf("%d",&pessoas[q].idade);
		printf("\ndeseja continuar?\n");
		getchar();
		scanf("%c",&continua);
		q++;
	}
	printf("%s esta vivo!\n",pessoas[0].nome);
	return(0);
}
