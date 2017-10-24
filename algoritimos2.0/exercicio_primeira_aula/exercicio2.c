#include <stdio.h>

void invertesaporra(char s[]){
	int cont=0;
	char aux[50];
	while(s[cont]!='\0'){
		aux[cont]=s[cont];
		cont++;
	}
	int cont2=0;
	cont--;
	while(cont>=0){
		s[cont2]=aux[cont];
		cont--;
		cont2++;
	}
	s[cont2+1]='\0';
}

int subistitui(char s[],char A, char novo){
	int cont=0, cont2=0;
	while(s[cont]!='\0'){
		if(s[cont]==A){
			s[cont]=novo;
			cont2++;
		}
		cont++;
	}
	return cont2;
}


int main(void){
	
	char s[50];
	int num;

	scanf("%s",&s);
	printf("%s\n",s );
	invertesaporra(s);
	printf("%s\n",s );

	num=subistitui(s,'a','p');

	printf("%s\ncom total de %d substituicoes\n",s,num );

	return 0;
}