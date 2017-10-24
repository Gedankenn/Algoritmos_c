//funcoes.h
//teste1
typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;
typedef struct{
	no* inicio;
	int quant;
	no* fim;
}LDD;


void DefineS(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

void DefineD(LDD *L){
	L->quant=0;
	L->inicio=NULL;
	L->fim=NULL;
}

no* BuscaValor(LD *L, int ch){
	no *p;
	if(L->quant==0) return NULL;
	else{
		p=L->inicio;
		while(p!=NULL){
			if(p->chave==ch) return p;
			else p=p->prox;
		}
	}
	return NULL;
} 

no* BuscaPosicao(LD *L, int pos){
	no *p;
	p=L->inicio;
	int cont;
	if(pos > L->quant){
		printf("posicao invalida\n");
		return NULL;
	}
	while(p!=NULL){
		if(pos==cont) return p;

		cont++;
		p=p->prox;
	}
	return NULL;
}

void RemoverDepois(LD *L, no **q){
	no *p;
	p=(*q)->prox;
	(*q)->prox=p->prox;
	free(p);
	L->quant--;
}

int insere(LD *L, int ch, int pos){
	int cont=0;
	no *q, *p;
	p=L->inicio;
	if(L->quant==0){
	q=malloc(sizeof(no));
	q->chave=ch;
	q->prox=NULL;
	L->inicio=q;
	L->quant++;
	return 1;
	}
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=ch;
			q->prox=p->prox;
			p->prox=q;
			L->quant++;
			return 1;
		}
		cont++;
		p=p->prox;
	}
	return 0;
}
void inserefinal(LD *L, int ch){
	no *q, *p;
	q=L->inicio;
	if(q==NULL){
		p=malloc(sizeof(no));
		p->chave=ch;
		p->prox=NULL;
		L->inicio=p;
		L->quant++;
	}
	else{
		while(q->prox!=NULL){
			q=q->prox;
		}
		p=malloc(sizeof(no));
		q->prox=p;
		p->chave=ch;
		L->quant++;
		p->prox=NULL;
	}
}

int RemovePosicao(LD *L,int pos){
	no *q, *p;
	p=BuscaPosicao(L,pos);
	if(p==NULL) return 0;

	q=p->prox;
	p->chave=p->prox->chave;
	p->prox=q->prox;
	free(q);
	L->quant--;
	return 1;
}

int RemoveChave(LD *L, int ch){
	no *p, *q;
	p=BuscaValor(L,ch);
	if(p==NULL) return 0;

	q=p->prox;
	p->chave=q->chave;
	p->prox=q->prox;
	free(q);
	L->quant--;
	return 1;
}

void RemoveDuplica(LD *L){
	no *p, *x;
	p=L->inicio;
	while(p!=NULL){
		x=p->prox;
		while(x!=NULL){
			if(p->chave==x->chave){
				no *r;
				r=x->prox;
				x->chave=r->chave;
				x->prox=r->prox;
				free(r);
			}
			else
				x=x->prox;
		}
		p=p->prox;
	}
}
void Removeponteiro(LD *L, no *p){
	no *q;
	q=p->prox;
	p->chave=q->chave;
	p->prox=q->prox;
	free(q);
	L->quant--;
}

LD merge(LD *L, LD *L2){
	no *p, *q, *maior;
	LD L3;
	if(L->quant>=L2->quant){
		maior=L->inicio;
		p=L2->inicio;
	}
	else{
		maior=L2->inicio;
		p=L->inicio;
	}
	q=malloc(sizeof(no));
	L3.inicio=q;
	L3.quant=0;
	while(maior!=NULL){
		q->chave=maior->chave;
		q->prox=malloc(sizeof(no));
		q=q->prox;
		maior=maior->prox;
		if(p!=NULL){
			q->chave=p->chave;
			p=p->prox;
			q->prox=malloc(sizeof(no));
			q=q->prox;
		}
	}
	q=NULL;
	return L3;
}
void transformacircular(LD *L){
	no *q;
	q=L->inicio;
	while(q->prox!=NULL)
		q=q->prox;

	q->prox=L->inicio;
}

void SeparaCircular(LD *L,LD *L2){
	no *p;
	p=L->inicio;
	while(p->prox!=L->inicio){
		if(p->chave%2!=0){
			inserefinal(L2,p->chave);
			Removeponteiro(L,p);
		}
		else
			p=p->prox;
	}
	if(p->chave%2!=0){
		inserefinal(L2,p->chave);
		Removeponteiro(L,p);
		L->inicio=p;
	}
}

void inserechar(LDZ *L){
	noz *q, *p;
	q=L->inicio;
	if(L->inicio==NULL){
		p=malloc(sizeof(noz));
		L->inicio=p;
		scanf("%[^\n]",p->chave);
		getchar();
		L->quant++;
		p->prox=L->inicio;
	}
	else{
		while(q->prox!=L->inicio){
			q=q->prox;
		}
		p=malloc(sizeof(noz));
		q->prox=p;
		scanf("%[^\n]",p->chave);
		getchar();
		p->prox=L->inicio;
		L->quant++;
	}

}

void empilha(LD *L, int num){
	no *p;
	p=malloc(sizeof(no));
	p->chave=num;
	p->prox=L->topo;
	L->topo=p;
	L->quant++;
	return 1;
}

int desempilha(LD *L){
	int chave;
	no *p;
	p=L->topo;
	chave=p->chave;
	L->topo=p->prox;
	free(p);
	L->quant--;
	return chave;
}

void contrario(char s[]) {
 	if (s[0] != '\0'){
	contrario(&s[1]);
 	printf("%c",s[0]); 
 	}
 }

