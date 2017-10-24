#define MAX 100 		/* Max. Tamanho da Lista */
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>

typedef struct{
		int chave;
		char info[100];
} elem;				        /* Tipo do Elemento */

typedef struct{
		int nelem;
		elem A[MAX+1];
} Lista; 			/* Tipo da Lista */


void Definir(Lista *L){
	/* Define uma lista vazia */
	L->nelem= 0;
	L->A[0].chave = 0;       /* Celula nao utilizada */
	L->A[0].info[0] = '\0';  /* Celula nao utilizada */
}

int Fim(Lista *L){
	/* Retorna a posiçao após o último elemento da lista */
	return (L->nelem + 1);
}

int Lista_vazia(Lista *L){
	/* Retorna true se lista vazia, false caso contrario */
	return (L->nelem == 0);
}

int Lista_cheia(Lista *L){
	/* Retorna true se lista cheia, false caso contrario */
	return (L->nelem == MAX);
}

int Inserir(elem* x, int p, Lista *L){
/* Insere elemento x na posicao p da Lista L.
Se a lista é tal que L=a1,a2,...,ap,...,an entao L=a1,a2,...,ap-1,x,ap+1,...,an.
Se p=Fim(L) entao L=a1,a2,...,an,x.
Devolve true se sucesso, false se L cheia ou nao tem posiçao p. L nao ordenada! */
	int atual;
	if (Lista_cheia(L))
		return FALSE;  /* lista cheia */
	else if (p > Fim(L) || p < 1)
		return FALSE; /* posicao nao existe */
	else {
		for(atual = L->nelem; atual >= p; atual--)
			L->A[atual+1] = L->A[atual];
		L->A[p]=  *x;
		L->nelem++;
		return TRUE; /* insercao com sucesso */
	}
}

int Remover(int p, Lista *L){
/* Remove o elemento da posicao p da Lista.
Se L = a1,a2,...,an entao tem-se a1,a2,...,ap-1,ap+1,...,an.
Devolve true se sucesso, false c.c. (L nao tem posicao p, inclusive se p = Fim(L))  */
	int atual;
	if(p >= Fim(L) || p < 1 || Lista_vazia(L))
        return FALSE;
	else {
		for (atual = p+1; atual <= L->nelem; atual++)
			L->A[atual-1] = L->A[atual];
		L->nelem--;
	}
    return TRUE;
}

elem* Obter(Lista *L, int p){
/* Retorna elem. da posicao p, ou elem. invalido se p e invalida */
	if (p >= Fim(L) || p < 1 || Lista_vazia(L))
		return NULL;    /* retorna elemento invalido */
	else
        return &(L->A[p]);
}
elem* buscaseq(Lista *L, char c[]){
/*busca sequencialmente o nome procurado*/
    int i=0;
    int aux;
    if(Lista_vazia(L))
        return NULL;
    else
        while (i <= L->nelem){
            if (strcmp(c, L->A[i].info) == 0)
                return &(L->A[i]);
            else
                i++;
        }
	if(i>L->nelem)
	return NULL;
}
/*elem* buscaseqreq(lista *L, char c[]){
    //busca sequencialmente em recursividade o nome procurado;
    if(Lista_vazia(L))
        return FALSE;
    else if
    if (strcmp(c, L->A[i].info)== 0)
        return &(L->A[i]);

}*/

int main(void){
    Lista chamada;			/* Exemplo de Declaracao*/
    Definir(&chamada);

    int i;
    int aux;
    //adicionar 5 novos alunos a chamada
    for (i=1; i<=5; i++) {
        elem novo;
        novo.chave = i;

        printf("Digite o nome de um aluno: ");
        scanf("%s", &novo.info);
        getchar();

        aux = Inserir(&novo, i, &chamada);
        if (aux<0)
            printf("Erro insercao");
    }
    printf("\n\n");

    elem *aluno = Obter(&chamada, 4);
    printf("O aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);

    printf("\nRemovendo aluno com matricula 3.\n");
    Remover(3, &chamada);
    aluno = Obter(&chamada, 4);
    printf("\nO aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);

    char jovem[50];
    printf("aluno para buscar: ");
    scanf("%s",&jovem);
    getchar();
	printf("%s",jovem);
    aluno = buscaseq(&chamada, jovem);
    printf("\nO aluno procurado foi %s com matricula nro. %d.\n", aluno->info, aluno->chave);

return 0;
}
