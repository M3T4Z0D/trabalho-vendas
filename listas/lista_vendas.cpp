#include "../cabecalhos/funcoes_listas.h"

void imprime_lista_vendas(venda *&listaVendas)
{
    venda *venda;

    for (venda = listaVendas; venda != NULL; venda = venda->proxima)
    {
        printf("Data venda: %s \n", venda->data_venda);
        printf("Hora venda: %s \n", venda->hora_venda);
        printf("CPF cliente: %s \n", venda->cpf_cliente);
        // TO-DO: adicionar print da lista de itens vendidos
    }
}

void inserir_venda_inicio(venda *&novaVenda, venda *&listaVendas)
{
    novaVenda->proxima = listaVendas;
    novaVenda->anterior = NULL;

    if (listaVendas != NULL)
        listaVendas->anterior = novaVenda;

    listaVendas = novaVenda;
}

void cadastrar_venda(venda *&listaVendas, produto *&listaProdutos)
{
    venda *novaVenda;
    int codigo_produto, quantidade_produto, statusVenda = 1;
    double valorTotalVenda = 0;
    produto *produto;

    novaVenda = (venda *)calloc(1, sizeof(venda));

    novaVenda->listaProdutos = NULL;

    printf("Informe a data da venda(YYYY/mm/dd): ");
    scanf(" %s", novaVenda->data_venda);
    printf("Informe a hora da venda(HH:mm:ss): ");
    scanf(" %s", novaVenda->hora_venda);
    printf("Informe o CPF do cliente: ");
    scanf(" %s", novaVenda->cpf_cliente);

    do
    {
        imprimir_produtos(listaProdutos);

        printf("Informe o codigo do produto: ");
        scanf("%d", &codigo_produto);
        printf("Informe a quantidade desejada: ");
        scanf("%d", &quantidade_produto);

        produto = buscarProdutoNoEstoque(codigo_produto, quantidade_produto, listaProdutos);

        if (produto->quantidade_em_estoque < quantidade_produto)
        {
            if (produto->quantidade_em_estoque == 0)
            {
                printf("Nao temos nenhuma unidade deste produto em nosso estoque no momento.\n\n");
            }
            else
            {

                int opcao;
                printf("Atualmente só existem %d %s no estoque. Deseja levar essa quantidade?\n", produto->quantidade_em_estoque, produto->desc);
                printf("[1] para Sim. [2] para Nao.\n\n Opcao: ");
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    inserir_produto_vendido_fim(codigo_produto, produto->preco, quantidade_produto, novaVenda->listaProdutos);
                    produto->quantidade_em_estoque = 0; // atualizar estoque
                }
            }
        }
        else
        {
            inserir_produto_vendido_fim(codigo_produto, produto->preco, quantidade_produto, novaVenda->listaProdutos);
            produto->quantidade_em_estoque -= quantidade_produto; // atualizar estoque
        }

        /*Esta parte nos criamos pois faria sentido, mas como não foi solicitada no trabalho, deixamos comentada.*/
        // if (produto->quantidade_em_estoque == 0)
        // {
        //     remover_produto(produto->codigo_produto, listaProdutos);
        // }

        printf("Adicionar mais itens? \n");
        printf("[1] - Sim\n[2] - Concluir venda\n\n Opcao: ");
        scanf("%d", &statusVenda);
        printf("\n");

    } while (statusVenda != 2);

    inserir_venda_inicio(novaVenda, listaVendas);

    valorTotalVenda = calcularPrecoTotalDoCarrinho(novaVenda->listaProdutos);
    printf("O valor total desta venda e R$ %.2lf\n\n", valorTotalVenda);
}

void imprime_vendas_por_data(venda *&listaVendas)
{
    char data[DATA_TAM + 1];
    venda *venda;
    bool houveVenda = false;

    printf("Informe a data da consulta (YYYY/mm/dd): ");
    scanf(" %s", data);
    printf("\n");

    for (venda = listaVendas; venda != NULL; venda = venda->proxima)
    {
        if (strcmp(venda->data_venda, data) == 0)
        {
            houveVenda = true;
            printf("Hora venda: %s \n", venda->hora_venda);
            printf("CPF cliente: %s \n", venda->cpf_cliente);
            printf("Valor total: %.2lf\n", calcularPrecoTotalDoCarrinho(venda->listaProdutos));
            printf("-------------------\n");
        }
    }

    if(!houveVenda){
        printf("Nao houve nenhuma venda na data %s\n", data);
    }
}

bool buscarItemVendido(int codigo, venda *&listaVendas){
    venda *venda;

    for(venda = listaVendas; venda != NULL; venda = venda->proxima){
        produtoVendido *produtoVendido;
        produtoVendido = venda->listaProdutos;

        for(; produtoVendido != NULL; produtoVendido = produtoVendido->proximo){
            if(produtoVendido->codigo_produto == codigo)
                return true;
        }
    }

    return false;
}

void desalocar_vendas(venda *&listaVendas){
    venda *aux;

    while (listaVendas != NULL)
    {
        desalocar_itens_vendidos(listaVendas->listaProdutos);
        
        aux = listaVendas;
        listaVendas = aux->proxima;

        free(aux);
    }
}
