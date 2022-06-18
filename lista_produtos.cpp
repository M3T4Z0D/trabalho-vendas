#include "listas.h"

//Retirar
void imprimir_produtos(produto *lst)
{
    produto *p;
    for (p = lst; p != NULL; p = p->proximo){
        printf("Codigo: %d \n", p->codigo_produto);
        printf("Descricao: %s \n", p->desc);
    }
}

void remover_produto(int codigo, produto *&lst)
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

void alterar_dado_produto(int codigo_produto, int estoque, double preco, produto *& listaProdutos){
    produto *produto;

    produto = listaProdutos;
    while (produto != NULL && produto->codigo_produto != codigo_produto)
    {
        produto = produto->proximo;
    }

    if (produto == NULL)
        printf("O produto %d nao foi encontrado.\n", codigo_produto);
    else
    {
        printf("Produto: %s\n", produto->desc);
        printf("Preco: %.2lf\n", produto-> preco);
        printf("Quantidade em estoque: %d\n\n", produto->quantidade_em_estoque);

        //Receber novos valores
        printf("Novo valor do produto: ", &produto->preco);
        int quantidade_adicionar;
        printf("Quantidade de produtos para adicionar: ", &quantidade_adicionar);
        produto->quantidade_em_estoque += quantidade_adicionar;
    }
    
    free(produto);
}

void desalocar_lista_produtos(produto *&listaProdutos)
{
    produto *aux;

    while (listaProdutos != NULL)
    {
        aux = listaProdutos;

        listaProdutos = aux->proximo;

        free(aux);
    }
}

void inserir_produto(produto *&lst, int codigo, char *desc, double preco, int estoque)
{
    produto *novo, *p;

    // alocacao do no
    novo = (produto *)calloc(1, sizeof(produto));
    // copiando cada campo
    novo->codigo_produto = codigo;
    strcpy(novo->desc, desc);
    novo->preco = preco;
    novo->quantidade_em_estoque = estoque;

    if (lst == NULL)
        lst = novo;
    else
    {
        p = lst;
        while (p->proximo != NULL)
            p = p->proximo;

        p->proximo = novo;
    }
}