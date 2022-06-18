#include "listas.h"

void imprimir_produtos(produto *lst)
{
    produto *p;
    for (p = lst; p != NULL; p = p->proximo)
        printf("%d \n", p->codigo_produto);
}

void remover(int codigo, produto *&lst)
{
    produto *p, *q;
    p = NULL;
    q = lst;
    while (q != NULL && q->codigo_produto != codigo)
    {
        p = q;
        q = q->proximo;
    }
    
    if (q == NULL)
        printf("O produto %d nao foi encontrado.", codigo);
    else
    {
        if (p != NULL)
            p->proximo = q->proximo;
        else
            lst = q->proximo;

        free(q);
    }
}

// Funcao que apaga todos os nos da lista L
void desalocar(produto *&listaProdutos)
{
    produto *aux;

    while (listaProdutos != NULL)
    {
        aux = listaProdutos;

        listaProdutos = aux->proximo;

        free(aux);
    }
}