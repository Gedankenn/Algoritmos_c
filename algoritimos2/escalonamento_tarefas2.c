#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int tarefa;
	int Ti;
	int Tf;
}tarefas;

int escalonamentotarefas(tarefas *T, int tam, int tempo){
	int cont,cont2,cont3,cont4,igual,vetTar[tam], numTar, melhor, melhorVetor[tam],cont5=0, menor;
	
	cont=0;
	melhor=0;
	//printf("teste\n");
	while(cont<tam){
		menor=99;
		while(cont2<tam){
			if(T[cont3].Tf<=T[cont2].Ti && T[cont2].Tf-T[cont2].Ti<menor && T[cont2].Tf<=tempo){
				vetTar[cont4]=T[cont3].tarefa;
				vetTar[cont4+1]=T[cont2].tarefa;
				cont5=cont2;
				menor=T[cont2].Tf-T[cont2].Ti;
			}
			cont2++;
		}
		cont3=cont5;
		cont++;
		cont4++;
	}
	//printf("teste7\n");
	printf("numero de tarefas: %d\n",melhor);
	for(cont2=0;cont2<melhor;cont2++){
		printf("%d ",melhorVetor[cont2]);
	}
	return melhor;
}



int main(void){	
	int tam, tempo, cont2;
	scanf("%d %d",&tam,&tempo);

	tarefas Tezaopia[tam];

	for(cont2=0;cont2<tam;cont2++){
		scanf("%d %d %d",&Tezaopia[cont2].tarefa,&Tezaopia[cont2].Ti,&Tezaopia[cont2].Tf);
	}
	for(cont2=0;cont2<tam;cont2++){
		printf("%d %d %d\n",Tezaopia[cont2].tarefa,Tezaopia[cont2].Ti,Tezaopia[cont2].Tf);
	}
	tam=escalonamentotarefas(Tezaopia,tam,tempo);
	return 0;
}