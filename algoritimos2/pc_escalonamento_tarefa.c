#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int tarefa;
	int Ti;
	int Tf;
}tarefas;


int escalonamentotarefaspc(tarefas *T, int tam, int tempo){
	int cont,cont2,cont3,cont4,igual,vetTar[tam], numTar, melhor, melhorVetor[tam],cont5=0;
	
	cont=0;
	//melhor=0;
	//printf("teste\n");
	while(tam>0){
		melhor=0;
		cont=0;
		cont5=0;
		while(cont<tam){
			cont3=cont;
			cont2=0;
			cont4=0;
			while(cont2<tam){
				if(T[cont3].Tf==T[cont2].Ti && T[cont2].Tf<=tempo){
					vetTar[cont4]=T[cont3].tarefa;
					vetTar[cont4+1]=T[cont2].tarefa;
					cont3=cont2;
					cont4++;
				}
				
				cont2++;
			}
			if(cont4>=melhor){
				for(melhor=0;melhor<cont4+1;melhor++){
					melhorVetor[melhor]=vetTar[melhor];
				}
			}
			cont++;
		}
		//melhor=0;
		printf("numero de tarefas: %d\n",melhor);
		for(cont2=0;cont2<melhor;cont2++){
			printf("%d ",melhorVetor[cont2]);
		}
			printf("\n");
		for(cont2=0;cont2<melhor;cont2++){
			cont5=0;
			while(T[cont5].tarefa!=melhorVetor[cont2]){
				cont5++;
			}
			T[cont5]=T[tam-1];
			tam=tam-1;
		}
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
	/*for(cont2=0;cont2<tam;cont2++){
		printf("%d %d %d\n",Tezaopia[cont2].tarefa,Tezaopia[cont2].Ti,Tezaopia[cont2].Tf);
	}*/
	tam=escalonamentotarefaspc(Tezaopia,tam,tempo);
	return 0;
}