#include <stdio.h>

int main(void){
	int cont;
	int cont2;
	int cont3;

	char vet[]="Eu to louca, eu to crazy to suave, to amazing Pode pah, aah ele bem chave ta com a nave ta botando a corneta pra gritar.";
	//tati-zaqui <3
	cont=0;
	cont2=0;

	printf("%s\n",vet );

	while(vet[cont]!='\0'){
		cont2=cont;
		cont3=0;
		while(vet[cont2]!='\0'){
			if(vet[cont]==vet[cont2] && vet[cont]!='!'){
				cont3++;
				if(cont3>1){
					vet[cont2]='!';
				}
			}
			cont2++;
		}
		if(cont3!=0){
			printf("%c repete %d veses\n",vet[cont],cont3 );
		}
		cont++;
	}

	return 0;
}