#include "listas.h"

void imprimir_itens_vendidos(produtoVendido *lst)
{
    produtoVendido *p;
    for (p = lst; p != NULL; p = p->proximo)
        printf("%d - R$  \n", p->codigo_produto, p->preco_venda);
}

void inserir_fim(int codigo, double valor, produtoVendido *&listaProdutosVendidos)
{
    produtoVendido *novo, *p;

    // alocacao do no
    novo = (produtoVendido *)calloc(1, sizeof(produtoVendido));
    // copiando cada campo
    novo->codigo_produto = codigo;
    novo->preco_venda = valor;

    if (listaProdutosVendidos == NULL)
        listaProdutosVendidos = novo;
    else
    {
        p = listaProdutosVendidos;
        while (p->proximo != NULL)
            p = p->proximo;

        p->proximo = novo;
    }
}

void desalocar(produtoVendido *&listaProdutosVendidos)
{
    produtoVendido *aux;

    while (listaProdutosVendidos != NULL)
    {
        aux = listaProdutosVendidos;

        listaProdutosVendidos = aux->proximo;

        free(aux);
    }
}