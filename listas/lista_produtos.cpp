#include "../cabecalhos/funcoes_listas.h"

void imprimir_produtos(produto *lst)
{
    produto *p;
    for (p = lst; p != NULL; p = p->proximo)
    {
        printf("Codigo: %d \n", p->codigo_produto);
        printf("Descricao: %s \n", p->desc);
        printf("Preco: %.2lf\n\n", p->preco);
    }
}

void remover_produto(produto *&listaProdutos, venda *&listaVendas)
{
    produto *produtoAnterior, *q;
    int codigo;
    produtoAnterior = NULL;
    q = listaProdutos;

    printf("Informe o codigo do produto a ser removido: ");
    scanf("%d", &codigo);

    while (q != NULL && q->codigo_produto != codigo)
    {
        produtoAnterior = q;
        q = q->proximo;
    }

    if (q == NULL)
        printf("O produto %d nao foi encontrado.", codigo);
    else
    {
        printf("Nome do item: %s\n", q->desc);
        
        bool produtoJaFoiVendido = false;

        produtoJaFoiVendido = buscarItemVendido(codigo, listaVendas);

        if (!produtoJaFoiVendido)
        {
            if (produtoAnterior != NULL)
                produtoAnterior->proximo = q->proximo;
            else
                listaProdutos = q->proximo;

            free(q);

            printf("Produto removido com sucesso.\n\n");
        }
        else{
            printf("O item nao pode ser excluido, pois esta vinculado a uma venda.\n\n");
        }
    }
}

void alterar_dado_produto(produto *&listaProdutos)
{
    produto *produto;
    int codigo_produto;

    printf("Informe o codigo do produto a ser alterado: ");
    scanf("%d", &codigo_produto);

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
        printf("Preco: %.2lf\n", produto->preco);
        printf("Quantidade em estoque: %d\n\n", produto->quantidade_em_estoque);

        // Receber novos valores
        printf("Novo valor do produto: ");
        scanf("%lf", &produto->preco);
        int quantidade_adicionar;
        printf("Quantidade de produtos para adicionar: ");
        scanf("%d", &quantidade_adicionar);

        produto->quantidade_em_estoque += quantidade_adicionar;
    }
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

    novo = (produto *)calloc(1, sizeof(produto));

    novo->codigo_produto = codigo;
    strcpy(novo->desc, desc);
    novo->preco = preco;
    novo->quantidade_em_estoque = estoque;

    if (lst == NULL)
    {
        lst = novo;
    }
    else if (novo->codigo_produto < lst->codigo_produto)
    {
        novo->proximo = lst;
        lst = novo;
    }
    else
    {
        p = lst;
        while (p->proximo != NULL && novo->codigo_produto > p->proximo->codigo_produto)
            p = p->proximo;
        novo->proximo = p->proximo;
        p->proximo = novo;
    }
}

void leitura_produtos(char *nome, produto *&lista)
{
    FILE *arq;
    int codigo, estoque;
    double preco;
    char nomep[MAX + 1];

    arq = fopen(nome, "r");
    if (arq == NULL)
    {
        printf("Arquivo nao pode ser aberto.");
        exit(0);
    }
    else
    {
        fscanf(arq, "%d", &codigo);
        while (feof(arq) == 0)
        {
            // leitura dos demais dados
            fscanf(arq, " %[^\n]", nomep);
            fscanf(arq, "%lf", &preco);
            fscanf(arq, "%d", &estoque);

            inserir_produto(lista, codigo, nomep,
                            preco, estoque);

            fscanf(arq, "%d", &codigo);
        }
        fclose(arq);
    }
}

produto *buscarProdutoNoEstoque(int codigo, int quantidade, produto *&listaProdutos)
{
    produto *produto;

    produto = listaProdutos;
    while (produto != NULL && produto->codigo_produto != codigo)
    {
        produto = produto->proximo;
    }

    return produto;
}