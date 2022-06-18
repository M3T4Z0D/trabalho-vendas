#include "listas.h"

void imprime_lista(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);
}

/*Funcao insere um novo no sempre no inicio da lista*/
void inserir_inicio(int x, celula*&L)
{
    celula* novo = (celula*) malloc (sizeof(celula));
    novo->chave = x;
    novo->prox = L;
    novo->ant = NULL;
    if(L != NULL)
        L->ant = novo;

    L = novo;
}



/*Funcao insere um novo no fim da lista*/
void inserir_fim(int x, celula*&L)
{
    celula* novo = (celula*) calloc (1, sizeof(celula));
    novo->chave = x;

    if(L == NULL)
        L = novo;
    else
    {
        celula *p;

        p = L;

        while( p->prox != NULL)
            p = p->prox;

        p->prox = novo;
        novo->ant = p;
    }
}


/*Procura e remove um no com valor x*/
void remover(int x, celula*&lst)
{
    celula *p;

    p = lst;
    while(p!= NULL && p->chave != x)
        p = p->prox;

    if(p == NULL)
        printf("\nNao encontrado");
    else{
        if(p->ant == NULL)
        {
            lst = lst->prox;
            if(lst != NULL)
                lst->ant = NULL;
            free(p);
        }
        else{
            p->ant->prox = p->prox;
            if(p->prox!=NULL)
                p->prox->ant = p->ant;
        }
    }
}




/*Funcao que apaga todos os nos da lista L*/
void desalocar(celula*&L)
{
    celula *aux;

    while( L != NULL )
    {
        aux = L;

        L = aux->prox;

        free(aux);
    }
}