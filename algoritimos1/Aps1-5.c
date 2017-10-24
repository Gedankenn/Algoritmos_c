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
	int q=0, i=0;
	int cont[10];
	while(q<3)
	{
		gets(pessoas[q].nome);
		scanf("%d",&pessoas[q].peso);
		scanf("%d",&pessoas[q].idade);
		if(pessoas[q].idade >=20 && pessoas[q].idade <= 30 && pessoas[q].peso >= 50)
		{
			cont[i]=q;
			i++;
		}
		q++;
	}
	for(i;i>=0;i--)
	printf("%s\n",pessoas[cont[i]].nome);
	
	return(0);
}
