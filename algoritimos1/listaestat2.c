#define MAX 100 		/* Max. Tamanho da Lista */
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

typedef struct{
	int chave;
	char info[100];
}elem;

typedef struct{
	int nelem;
	elem A[MAX+1];
}Lista;

void Definir(Lista *L){
	L->nelem=0;
	L->A[0].chave=0;
	L->A[0].info[0]='\0';
}

int Fim(Lista *L){
	//retorna a posicao depois do ultimo;
	return (L->nelem+1);
}

int Lista_vazia(Lista *L){
	//retorna 1 se a lista estiver vasia
	return(L->nelem == 0);
}

int Lista_cheia(Lista *L){
	//retorna 1 se a lista estiver cheia
	return(L->nelem == MAX);
}

int Inserir(elem* x, int p, Lista *L){
	int atual;
	if(Lista_cheia(L))
		return 0;
	else if(p > Fim(L) || p<1)
		return 0;
	else{
		for(atual=L->nelem;atual >= p; atual--)
			L->A[atual+1]=L->A[atual];
		L->A[p]= *x;
		L->nelem++;
		return 1;
	}
}

int Remover(int p, Lista *L){
	int atual;
	if(p>=Fim(L) || p<1 || Lista_vazia(L))
		return 0;
	else{
		for(atual = p+1; atual <= L->nelem; atual++)
			L->A[atual-1]=L->A[atual];
	L->nelem--;
	}
	return 1;
}

elem* Obter(Lista *L, int p){
	if(p >= Fim(L) || p<1 || Lista_vazia(L))
		return &(L->A[0]);
	else
		return &(L->A[p]);
}

elem* Buscaseq(Lista *L, char c[]){
	int i=0;
	int aux;
	if(Lista_vazia(L))
		return &(L->A[0]);

	else
		while(i<= L->nelem){
			if(strcmp(c,L->A[i].info)==0)
				return &(L->A[i]);
			else
				i++;
		}
		if(i> L->nelem)
			return &(L->A[0]);
}

//elem* buscarec(Lista *L, int chave, int num){
//	if(L->A[chave].chave==num)
//	return &(L->A[num]);
//		return buscarec(

int main(void){
	Lista chamada;
	Definir(&chamada);
	
	int i;
	int aux;
	int alunos;
	printf("informe o numero de pentelhos: ");
	scanf("%d",&alunos);
	getchar();

	for(i=1; i<=alunos; i++){
	elem novo;
	novo.chave = i;
	
	printf("informe o nome do pestinha ");
	gets(novo.info);

	aux = Inserir(&novo, i, &chamada);
	if(aux == 0)
		printf("erro insersao");
	
	}
	printf("\n\n");
	
	elem *aluno=Obter(&chamada, 4);
	printf("O aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);

	printf("\nRemovendo aluno com matricula 3.\n");
    	Remover(3, &chamada);
    	aluno = Obter(&chamada, 4);
    	printf("\nO aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);	

	char jovem[50];
	printf("informe o nome do pestinha: ");
	gets(jovem);
	aluno = Buscaseq(&chamada, jovem);
    	printf("\nO aluno procurado foi %s com matricula nro. %d. \n", aluno->info, aluno->chave);

return 0;
}
