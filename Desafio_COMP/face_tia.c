#include <stdio.h>

int main(void){
	int m,n,k,a, cont=0, cont2;
	char t[1001], aux;

	scanf("%d",&n);
	while(n<6 || n>1000){
		scanf("%d",&n);
	}
	m=1000;
	k=10000;
	a=11100;
	while((m+k+a)>n+1){
		scanf("%d",&m);
		while(m<0 || m>1000){
			scanf("%d",&m);
		}
		scanf("%d",&k);
		while(k<0 || k>1000){
			scanf("%d",&k);
		}
		scanf("%d",&a);
		while(a<0 || a>1000){
			scanf("%d",&a);
		}
	}

	//scanf("%[^\n]",NULL);
	scanf("%s",t);

	cont=0;
	cont2=0;
	int cont3=0;
	while(t[cont]!='\0'){
		if((int)t[cont]>48 && (int)t[cont]<57){
			cont2=1;
		}
		if(((int)t[cont]>65 && (int)t[cont]<90) || ((int)t[cont]>95 && (int)t[cont]<122)){
			cont3=1;
		}
		cont++;
	}
	if(cont3==1 && cont2==1){
		printf("OK =/\n");
	}
	else{
		printf("Ufa :)\n");
	}
	return 0;
}