#include <stdio.h>
int Ttotal=10;
int tar=11;

typedef struct{
	int tarefa;
	int Ti;
	int Tf;
}tarefa;


void escalona(tarefa *T){
	int i, tf=0,ti=999, menor=9999, cont=0, aux, aux2;

	i=0;
	while(i<tar){
		if(3>=T[i].Ti && T[i].Tf-T[i].Ti <= menor){
			if(T[i].Tf-T[i].Ti==menor){
				if(T[i].Ti < T[aux2].Ti){
					aux2=i;	
					menor=T[i].Tf-T[i].Ti;
				}
			}
			else{
				aux2=i;
				menor=T[i].Tf-T[i].Ti;
			}
		}
		i++;
	}

	i=0;
	aux=0;
	tf=T[aux2].Tf;
	printf("%d | %d | %d\n",T[aux2].tarefa, T[aux2].Ti, T[aux2].Tf );
	while(tf<Ttotal && cont<tar){
		aux=0;
		while(aux<tar){
			if(T[aux].Ti==tf && T[aux].Tf-T[aux].Ti <= menor){
				if(T[aux].Tf-T[aux].Ti == menor){
					if(T[aux].Ti < T[aux2].Ti){
						aux2=aux;
						menor=T[aux2].Tf-T[aux2].Ti;		
					}
				}
			aux2=aux;
			menor=T[aux2].Tf-T[aux2].Ti;
			}
			aux++;
		}
		menor=9999;
		printf("%d | %d | %d\n",T[aux2].tarefa, T[aux2].Ti, T[aux2].Tf );
		cont++;
		tf=T[aux2].Tf;
	}

}

void escalonatudo(tarefa *T){
	int i, tf=0,ti=999, menor=9999, cont=0, aux, aux2, aux3=tar-1;

	i=0;
	while(0<=aux3){
		menor=9999;
		i=0;
		printf("CPU----------------------\n");
		while(i<=aux3){
			if(T[i].Tf-T[i].Ti <= menor){
				if(T[i].Tf-T[i].Ti==menor){
					if(T[i].Ti < T[aux2].Ti){
						aux2=i;	
						menor=T[i].Tf-T[i].Ti;
					}
				}
				else{
					aux2=i;
					menor=T[i].Tf-T[i].Ti;
				}
			}
			i++;
		}

		i=0;
		aux=0;
		tf=T[aux2].Tf;
		printf("%d | %d | %d\n",T[aux2].tarefa, T[aux2].Ti, T[aux2].Tf );
		if(aux3>=0){
			T[aux2]=T[aux3];
		}
		aux3--;
		cont=0;
		menor=99999;
		int xkcd=0;
		while(tf<Ttotal && cont<=aux3){
			aux=0;
			xkcd=0;
			while(aux<=aux3){
				if(T[aux].Ti>=tf && T[aux].Tf-T[aux].Ti <= menor){
					if(T[aux].Tf-T[aux].Ti == menor){
						if(T[aux].Ti < T[aux2].Ti){
							aux2=aux;
							menor=T[aux2].Tf-T[aux2].Ti;		
						}
					}
					aux2=aux;
					menor=T[aux2].Tf-T[aux2].Ti;
					xkcd=1;
				}
				aux++;
			}
		menor=9999;
		if(xkcd==1){
			printf("%d | %d | %d\n",T[aux2].tarefa, T[aux2].Ti, T[aux2].Tf );
			tf=T[aux2].Tf;
			if(aux3>=0){
				T[aux2]=T[aux3];
			}
			aux3--;
		}
		cont++;
		}
	}
}

int main(void){
	tarefa agenda[tar];
	int i;

	i=0;
	while(i<tar){
		scanf("%d %d %d",&agenda[i].tarefa, &agenda[i].Ti, &agenda[i].Tf);
		i++;
	}
	i=0;
	while(i<tar){
		printf("%d %d %d\n",agenda[i].tarefa, agenda[i].Ti, agenda[i].Tf);
		i++;
	}

	printf("-------------------------------------\n");
	escalona(agenda);
	printf("-------------------------------------\n");
	escalonatudo(agenda);

	return 0;
}