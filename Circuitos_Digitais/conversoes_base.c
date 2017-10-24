#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//se o numero for HEX favor inserir letras maiusculas.

//funcao que le um numero na base 10, e le para qual base quer transformar
int b10_b(int num, int b){
	if(num==0){
		return 0;
	}
	else{
		return (num%b+10*b10_b(num/b, b));
	}
}

//funcao que le um numero na base 10, e transforma para base 16
void b10_b16(int num, char *hex, int *cont){
	if(num==0){
		hex[*cont]='\0';
		int c=0, c2;
		char p;
		c2=*cont-1;
		while(c<c2){
			p=hex[c];
			hex[c]=hex[c2];
			hex[c2]=p;
			c2--;
			c++;
		}
		//return 0;
	}
	else{
		//hex[cont]=(char)(num%16+48);
		if(num%16>9){
			hex[*cont]=(char)(num%16+55);
		}
		else{
			hex[*cont]=(char)(num%16+48);
		}
		*cont=*cont+1;
		b10_b16(num/16,hex,cont);
	}
}

//funcao obsoleta.. funcao a baixo dessa faz todas as transformacoes ja
/*int b2_b10(char *num){
	int cont=0, pot=0, aux=0, dec=0, pot2;
	while(num[cont]!='\0'){
		cont++;
	}
	cont--;
	while(cont>=0){
		if(num[cont]=='1'){
			aux=pot;
			pot2=1;
			while(aux>0){
				pot2=pot2*2;
				aux--;
			}
			dec=dec+pot2;
		}
		pot++;
		cont--;
	}
	return dec;
}*/


//funcao que le um numero, e qual sua base, e transforma para base 10
int b_b10(char *num, int b){
	int cont=0, pot=0, cont2=0, pot2, res=0;
	while(num[cont]!='\0'){
		cont++;
	}
	cont--;
	while(cont>=0){
		if((int)num[cont]>48){
			cont2=pot;
			pot2=1;
			while(cont2>0){
				pot2=pot2*b;
				cont2--;
			}
			if((int)(num[cont])<58){
				res=res+(pot2*(int)(num[cont]-48));
			}
			else{
				res=res+(pot2*(int)(num[cont]-55));
			}
		}
		cont--;
		pot++;
	}
	return res;
	
}

//professor.. eu tentei implementar transformacao da b2 para a b8 e b16... porem cheguei a conclusao de que eh mais facil transformar da b2 para b10 e da b10 para as outras.



int main(void){
	int base, num, muda, cont=0, p;
	char numb[50], aux[50];

	printf("informe a base do numero:\n");
	scanf("%d",&base);
	printf("informe o numero:\n");

	if(base!=10){
		scanf("%s",numb);
		printf("%s na base %d\n",numb,base );
		num=b_b10(numb,base);
		printf("%s transformado na base 10: %d\n",numb,num );
		if(base==2){
			printf("%s transformado na base 8: %d\n",numb,b10_b(num,8) );
			p=0;
			b10_b16(num,aux,&p);
			printf("%s transformado na base 16: %s\n",numb,aux );
		}
		if(base==8){
			printf("%s transformado na base 2: %d\n",numb,b10_b(num,2) );
			p=0;
			b10_b16(num,aux,&p);
			printf("%s transformado na base 16: %s\n",numb,aux );	
		}
		if(base==16){
			printf("%s transformado na base 2: %d\n",numb,b10_b(num,2) );
			printf("%s transformado na base 8: %d\n",numb,b10_b(num,8) );
		}

	}
	else{
		scanf("%d",&num);
		printf("%d na base 10\n",num );
		p=0;
		b10_b16(num,numb,&p);
		printf("%d transformado na base 16: %s\n",num,numb );
		printf("%d trnasformado na base 8: %d\n",num,b10_b(num,8) );
		printf("%d transformado na base 2: %d\n",num,b10_b(num,2) );
	}

	return 0;
}