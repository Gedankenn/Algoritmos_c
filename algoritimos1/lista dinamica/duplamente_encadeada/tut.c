# include<stdio.h>

typedef struct notag{
	int chave;
	notag *prox;
	notag *ant;
}no;

typedef struct{
	no *inicio;
	no *fim;
	int quant;
}LD;
