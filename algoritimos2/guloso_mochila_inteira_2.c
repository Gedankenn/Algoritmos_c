#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int peso;
	int lucro;
	char chave;
}item;

void bubble_sort_peso(item *list, long n)
{
  long c, d, t;
  char aux;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d].peso > list[d+1].peso)
      {
        /* Swapping */
 
        t         = list[d].peso;
        list[d].peso   = list[d+1].peso;
        list[d+1].peso = t;
        t         = list[d].lucro;
        list[d].lucro   = list[d+1].lucro;
        list[d+1].lucro = t;
        aux=list[d].chave;
        list[d].chave=list[d+1].chave;
        list[d+1].chave=aux;
      }
      if(list[d].peso == list[d+1].peso){
      		if(list[d].lucro<list[d+1].lucro){
      			t         = list[d].peso;
        		list[d].peso   = list[d+1].peso;
        		list[d+1].peso = t;
        		t         = list[d].lucro;
        		list[d].lucro   = list[d+1].lucro;
        		list[d+1].lucro = t;
        		aux=list[d].chave;
        		list[d].chave=list[d+1].chave;
        		list[d+1].chave=aux;
      		}
      }
    }
  }
}

void bubble_sort_lucro(item *list, long n)
{
  long c, d, t;
  char aux;

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d].lucro > list[d+1].lucro)
      {
        /* Swapping */
 
        t         = list[d].lucro;
        list[d].lucro   = list[d+1].lucro;
        list[d+1].lucro = t;
        t         = list[d].peso;
        list[d].peso   = list[d+1].peso;
        list[d+1].peso = t;
        aux=list[d].chave;
        list[d].chave=list[d+1].chave;
        list[d+1].chave=aux;
      }
      if(list[d].lucro == list[d+1].lucro){
      		if(list[d].peso>list[d+1].peso){
      			t         = list[d].lucro;
        		list[d].lucro   = list[d+1].lucro;
        		list[d+1].lucro = t;
        		t         = list[d].peso;
        		list[d].peso   = list[d+1].peso;
        		list[d+1].peso = t;
        		aux=list[d].chave;
   			    list[d].chave=list[d+1].chave;
       		 	list[d+1].chave=aux;
      		}
      }
    }
  }
}

void bubble_sort_media(item *list, long n)
{
  long c, d, t;
  char aux;

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if ((list[d].lucro/list[d].peso) < (list[d+1].lucro/list[d+1].peso))
      {
        /* Swapping */
 
        t         = list[d].lucro;
        list[d].lucro   = list[d+1].lucro;
        list[d+1].lucro = t;
        t         = list[d].peso;
        list[d].peso   = list[d+1].peso;
        list[d+1].peso = t;
        aux=list[d].chave;
        list[d].chave=list[d+1].chave;
        list[d+1].chave=aux;
      }
      if((list[d].lucro/list[d].peso) == (list[d+1].lucro/list[d+1].peso)){
      		if(list[d].peso>list[d+1].peso){
      			t         = list[d].lucro;
        		list[d].lucro   = list[d+1].lucro;
        		list[d+1].lucro = t;
        		t         = list[d].peso;
        		list[d].peso   = list[d+1].peso;
        		list[d+1].peso = t;
        		aux=list[d].chave;
		        list[d].chave=list[d+1].chave;
        		list[d+1].chave=aux;
      		}
      }
    }
  }
}

void copiastruct(item A[], item B[], int quant){
	int cont;
	for(cont=0;cont<quant;cont++){
		B[cont]=A[cont];
	}
}

int gulosomochila(item items[],int w, int quant){
	int peso=0, peso2=0, peso3=0, lucro=0, lucro2=0, lucro3=0;
	int cont,cont1,cont2,cont3;
	char affe[4][9];
	item structaux[quant];

	copiastruct(items,structaux,quant);
//procura o melhor deles com peso como parametro
	bubble_sort_peso(structaux,quant);
	cont1=0;
	cont=0;
	peso=0;
	lucro=0;
	while(peso<w && cont<quant){
		if(peso+structaux[cont].peso<=w){
			peso=peso+structaux[cont].peso;
			affe[0][cont1]=structaux[cont].chave;
			lucro=structaux[cont].lucro+lucro;
			cont1++;
		}
		cont++;
	}


//procura o melhor deles com lucro como parametro
	bubble_sort_lucro(structaux,quant);
	cont2=0;
	cont=0;
	peso2=0;
	lucro2=0;
	while(peso2<w && cont<quant){
		if((peso2+structaux[cont].peso)<=w){
			peso2=peso2+ structaux[cont].peso;
			affe[1][cont2]=structaux[cont].chave;
			lucro2=structaux[cont].lucro+lucro2;
			cont2++;
		}
		cont++;
	}

//procura o melhor deles com a media como parametro
	bubble_sort_media(structaux,quant);
	peso3=0;
	cont3=0;
	cont=0;
	lucro3=0;
	while(peso3<w && cont<quant){
		if(peso3+structaux[cont].peso<=w){
			peso3=peso3+structaux[cont].peso;
			affe[2][cont3]=structaux[cont].chave;
			lucro3=structaux[cont].lucro + lucro3;
			cont3++;
		}
		cont++;
	}

	int maior=0;
	int vet[3];
	vet[0]=lucro;
	vet[1]=lucro2;
	vet[2]=lucro3;
	for(cont=0;cont<3;cont++){
		if(maior<vet[cont]){
			maior=vet[cont];
		}
	}
	printf("por peso o lucro foi: %d| com peso: %d | com os items: ",lucro,peso );
	for(cont=0;cont<cont1;cont++){
		printf(" %c ",affe[0][cont] );
	}
	printf("\npor lucro o lucro foi: %d | com peso: %d | com os items: ",lucro2,peso2);
	for(cont=0;cont<cont2;cont++){
		printf(" %c ",affe[1][cont]);
	}
	printf("\npor media o lucro foi: %d | com peso: %d | com os items: ",lucro3,peso3 );
	for(cont=0;cont<cont3;cont++){
		printf(" %c ",affe[2][cont] );
	}

	return maior;

}


int main(void){
	item bugigangas[8];
	int cont=0;

	for(cont=0;cont<8;cont++){
	
		scanf(" %c %d %d",&bugigangas[cont].chave,&bugigangas[cont].lucro,&bugigangas[cont].peso);

	}
	//bubble_sort_lucro(bugigangas,8);
	/*for(cont=0;cont<8;cont++){
	
		printf("%c %d %d\n",bugigangas[cont].chave,bugigangas[cont].lucro,bugigangas[cont].peso);

	}*/
	printf("%c %d %d\n",bugigangas[0].chave,bugigangas[0].lucro,bugigangas[0].peso );
	cont=gulosomochila(bugigangas,15,8);
	printf("\no melhor deles foi: %d\n",cont );

return 0;
}