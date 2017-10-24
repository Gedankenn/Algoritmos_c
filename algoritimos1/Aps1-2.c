#include<stdio.h>

int main()
{
	char string[30];
	gets(string);
	int q=0;
	do
	{
	q++;
	}while(string[q] != '\0');
	for(q;q>=0;q--)
	printf("%c",string[q]);
	printf("\n");
	return(0);
}
