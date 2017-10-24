#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

void quickSort(int *valor, int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}

void bubble_sort(int *list, int n)
{
  int c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}

int* copiavetor(int *vet, int max){
  int cont;
  int *q;
  q=malloc(sizeof(int) * max);
  for(cont=0;cont<max;cont++){
    q[cont]=vet[cont];
  }
  return q;
}

int main(void){
	int *vetor1, *vetor_inverso, *vetor_copia;
	srand((unsigned)time(NULL));
	clock_t Ti, Tf;
	float iteracoes;
	int tamanho=1000;
	int cont=0;
	int cont2;
	float tempo1,tempo2, tempo3;
	float tempo_aux;


	printf("bubble_sort, bubble_sort_ja_ordenado, bubble_sort_inverso, merge_sort, merge_sort_ja_ordenado, merge_sort_inverso, quickSort, quickSort_ja_ordenado, quickSort_inverso\n");

	while(tamanho<=4000){
		iteracoes=0;
		tempo1=0;
		tempo2=0;
		tempo3=0;
		while(iteracoes<50.0){
			vetor1=malloc(sizeof(int)*tamanho);
			vetor_inverso=malloc(sizeof(int)*tamanho);
			cont=0;
			while(cont>tamanho){
				vetor1[cont]=rand() % tamanho;
				cont++;
			}
			vetor_copia=copiavetor(vetor1,tamanho);

			Ti=clock();
			bubble_sort(vetor_copia,tamanho);
			Tf=clock();
			tempo_aux=(Tf-Ti)/1000.0;
			tempo1=tempo_aux+tempo1;
			free(vetor_copia);


			vetor_copia=copiavetor(vetor1,tamanho);

			Ti=clock();
			merge_sort(vetor_copia,tamanho);
			Tf=clock();
			tempo_aux=(Tf-Ti)/1000.0;
			tempo2=tempo_aux+tempo2;
			free(vetor_copia);

			vetor_copia=copiavetor(vetor1,tamanho);

			Ti=clock();
			quickSort(vetor_copia,0,tamanho-1);
			Tf=clock();
			tempo_aux=(Tf-Ti)/1000.0;
			tempo3=tempo_aux+tempo3;
			free(vetor_copia);

			iteracoes=iteracoes+1.0;
		}

		cont=tamanho-1;
		cont2=0;
		quickSort(vetor1,0,tamanho-1);
		while(cont>=0){
			vetor_inverso[cont2]=vetor1[cont];
			cont--;
			cont2++;
		}
		printf("%d ",tamanho );

		vetor_copia=copiavetor(vetor_inverso,tamanho);

		//bubblesort
		Ti=clock();
		bubble_sort(vetor1,tamanho);
		Tf=clock();
		printf("%f",tempo1/iteracoes );
		tempo1=(Tf-Ti)/1000.0;
		printf("%f",tempo1);
		Ti=clock();
		bubble_sort(vetor_inverso,tamanho);
		Tf=clock();
		tempo1=(Tf-Ti)/1000.0;
		printf("%f",tempo1 );
		free(vetor_inverso);


		//mergesort
		vetor_inverso=copiavetor(vetor_copia,tamanho);
		Ti=clock();
		merge_sort(vetor1,tamanho);
		Tf=clock();
		printf("%f",tempo2/iteracoes );
		tempo2=(Tf-Ti)/1000.0;
		printf("%f",tempo2 );
		Ti=clock();
		merge_sort(vetor_inverso,tamanho);
		tempo2=(Tf-Ti)/1000.0;
		printf("%f",tempo2 );
		free(vetor_inverso);

		//quicksort
		vetor_inverso=copiavetor(vetor_copia,tamanho);
		Ti=clock();
		quickSort(vetor1,0,tamanho-1);
		Tf=clock();
		printf("%f",tempo3/iteracoes );
		tempo3=(Tf-Ti)/1000.0;
		printf("%f",tempo3 );
		Ti=clock();
		quickSort(vetor_inverso,0,tamanho-1);
		Tf=clock();
		tempo3=(Tf-Ti)/1000.0;
		printf("%f",tempo3 );
		free(vetor_inverso);
		free(vetor1);
		free(vetor_copia);


		tamanho=tamanho+1000;
		printf("\n");
	}

	return 0;
}