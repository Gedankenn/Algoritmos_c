#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	char c;
	c=97;
	/*printf("%c\n",c );
	srand((unsigned)time(NULL));
	printf("%d\n",rand()%30 );
	*/
	FILE *f;
	f=fopen("teste.txt","r");
	int cont=0;
	printf("%c",f[2] );
	

	fclose(f);
	return 0;	
}