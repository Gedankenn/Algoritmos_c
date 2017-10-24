#include <stdio.h>

void string_inverte(char *s){
	int cont;
	char r[50];

	while(s[cont]!='\0'){
		cont++;
		r[cont]=s[cont];
	}
	cont--;
	int cont2=0;
	while(cont>=0){
		s[cont2]=r[cont];
		cont2++;
		cont--;
	}
	s[cont2]='\0';
}

void replace(char *s, char a, char b){
	int cont=0;
	while(s[cont]!='\0'){
		if(s[cont]==a){
			s[cont]=b;
		}
		cont++;
	}
}

int main(void){
	char s[50];

	scanf("%s",&s);

	printf("%s\n",s );

	string_inverte(s);
	printf("%s\n",s );

	replace(s, 'a', 'x');

	printf("%s\n",s );

	return 0;
}