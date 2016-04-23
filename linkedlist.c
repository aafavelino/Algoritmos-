#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoLista{
    int dado;
    struct NoLista *prox;
}NoLista;

int tamLista;

void iniciaLista(NoLista *p){
    p->prox=NULL;
    tamLista=0;  
}

bool vazia(NoLista *lista){
    if(lista->prox==NULL)
	return true;
    else
	return false;
}

void insereFim(NoLista *lista){
    NoLista *novoNo = (NoLista*)malloc(sizeof(NoLista));
    printf("Qual o valor do novo nó?\n");
    scanf("%d",&novoNo->dado);
    novoNo->prox=NULL;
  
    if(vazia(lista))
	lista->prox=novoNo;
    else{
	NoLista *aux;
	aux=lista->prox;
	while(aux->prox!=NULL){
	    aux=aux->prox;
	}
	aux->prox=novoNo;
    }
    tamLista++;
}

void insereInicio(NoLista *lista){
    NoLista *novoNo = (NoLista*)malloc(sizeof(NoLista));
    printf("Qual o valor do novo nó?\n");
    scanf("%d",&novoNo->dado);

    NoLista *aux;
    aux=lista->prox;
    lista->prox=novoNo;
    novoNo->prox=aux;
  
    tamLista++;
}

void inserePosicao(NoLista *lista){
    int pos, i;
    
    printf("Em que posição (de 1 até %d) você deseja inserir?\n",tamLista);
    scanf("%d",&pos);

    if(pos>0 && pos<=tamLista){

	if(pos==1)
	    insereInicio(lista);
	else{
	    NoLista *novoNo = (NoLista*)malloc(sizeof(NoLista));
	    printf("Qual o valor do novo nó?\n");
	    scanf("%d",&novoNo->dado);      
	
	    NoLista *noAtual;
	    NoLista *noAnt;
	
	    noAtual=lista->prox;
	    noAnt=lista;
	    
	    for(i=0;i<pos;i++){
		noAnt=noAtual;
		noAtual=noAtual->prox;
	}
	
	noAnt->prox=novoNo;
	novoNo->prox=noAtual;
	tamLista++;
	}
    }
    else
	printf("Essa posição não é válida! Digite uma posição entre 1 e %d\n",tamLista);
	
}

void mostraLista(NoLista *lista){
    if(vazia(lista))
	printf("A lista está vazia!");
    else{
	NoLista *aux;
	aux=lista->prox;
	
	while(aux!=NULL){
	    printf("%d ",aux->dado);
	    aux=aux->prox;
	}
	
	printf("\n");
    }
}

NoLista* retiraInicio(NoLista *lista){
    if(vazia(lista)){
	printf("Underflow!\n");
	return NULL;
    }
    else{
	NoLista *auxNo;
	auxNo=lista->prox;
	lista->prox=auxNo->prox;
	tamLista--;
	return auxNo;
    }
}


NoLista* retiraFim(NoLista *lista){
    if(vazia(lista)){
	printf("Underflow!\n");
	return NULL;
    }
    else{
	NoLista *noAtual, *noAnt;
	noAnt=lista;
	noAtual=lista->prox;
	
	while(noAtual->prox!=NULL){
	    noAnt=noAtual;
	    noAtual=noAnt->prox;
	}
	noAnt->prox=NULL;
	tamLista--;
	
	return noAtual;
    }
}

NoLista* retiraPosicao(NoLista *lista){
    int pos, i;
    
    printf("Em que posição (de 1 até %d) você deseja retirar?\n",tamLista);
    scanf("%d",&pos);

    if(pos>0 && pos<=tamLista){
	if(pos==1)
	    retiraInicio(lista);
	else{
	    NoLista *noAtual;
	    NoLista *noAnt;
	
	    noAtual=lista->prox;
	    noAnt=lista;
	    
	    for(i=0;i<pos;i++){
		noAnt=noAtual;
		noAtual=noAtual->prox;
	    }
	
	    noAnt->prox=noAtual->prox;
	    tamLista--;
	    return noAtual;
	}
    }
    else{
	printf("Essa posição não é válida! Digite uma posição entre 1 e %d\n",tamLista);
	return NULL;
    }
}


int main(){
    NoLista *no;
    no=(NoLista*)malloc(sizeof(NoLista));
    
    iniciaLista(no);
    insereFim(no);
    insereInicio(no);
    insereFim(no);
    retiraFim(no);
    insereFim(no);
    retiraPosicao(no);
    
    mostraLista(no);
    
    return 0;
}
