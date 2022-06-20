#include "../cabecalhos/funcoes_listas.h"

void imprimir_itens_vendidos(produtoVendido *lst)
{
    produtoVendido *p;
    for (p = lst; p != NULL; p = p->proximo)
        printf("%d - R$ %.2lf - %d\n\n", p->codigo_produto, p->preco_venda, p->quantidade_vendida);
}

void inserir_produto_vendido_fim(int codigo, double valor, int quantidade, produtoVendido *&listaProdutosVendidos)
{
    produtoVendido *novo, *p;

    // alocacao do no
    novo = (produtoVendido *)calloc(1, sizeof(produtoVendido));
    // copiando cada campo
    novo->codigo_produto = codigo;
    novo->preco_venda = valor;
    novo->quantidade_vendida = quantidade;

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

void desalocar_itens_vendidos(produtoVendido *&listaProdutosVendidos)
{
    produtoVendido *aux;

    while (listaProdutosVendidos != NULL)
    {
        aux = listaProdutosVendidos;

        listaProdutosVendidos = aux->proximo;

        free(aux);
    }
}

double calcularPrecoTotalDoCarrinho(produtoVendido *&listaProdutosVendidos)
{
    produtoVendido *p;
    double valorTotal = 0;
    for (p = listaProdutosVendidos; p != NULL; p = p->proximo)
        valorTotal += (p->preco_venda * p->quantidade_vendida);

    return valorTotal;
}