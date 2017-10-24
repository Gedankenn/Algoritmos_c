#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{
	int chave2;
	int chave1;
	char nome[40];
}ordenar;

void bubble_sort(ordenar *list, long n)
{
  long c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d].chave1 > list[d+1].chave1)
      {
        /* Swapping */
 
        t         = list[d].chave1;
        list[d].chave1   = list[d+1].chave1;
        list[d+1].chave1 = t;
        t         = list[d].chave2;
        list[d].chave2   = list[d+1].chave2;
        list[d+1].chave2 = t;
      }
      if(list[d].chave1 == list[d+1].chave1){
      		if(list[d].chave2>list[d+1].chave2){
      			t         = list[d].chave1;
        		list[d].chave1   = list[d+1].chave1;
        		list[d+1].chave1 = t;
        		t         = list[d].chave2;
        		list[d].chave2   = list[d+1].chave2;
        		list[d+1].chave2 = t;
      		}
      }
    }
  }
}

int main(void){
	ordenar vetores[5];
	int cont;
	int ch;

	srand((unsigned)time(NULL));

	for(cont=0;cont<5;cont++){
		ch=rand()%10;
		vetores[cont].chave1=ch;
	}


	for(cont=0;cont<5;cont++){
		ch=rand()%10;
		vetores[cont].chave2=ch;
	}


	for(cont=0;cont<5;cont++){
		printf("%d->%d \n",vetores[cont].chave1, vetores[cont].chave2 );
	}
	bubble_sort(vetores, 5);

	printf("\n\n\n");
	for(cont=0;cont<5;cont++){
		printf("%d->%d \n",vetores[cont].chave1, vetores[cont].chave2 );
	}
	return 0;
}

