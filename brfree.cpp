/***************************************************
 * Estudantes: - Lucas Cabral Carvalho de Oliveira
 *             - Samily Clarissa Lima do Nascimento
 * Trabalho BrFree - A melhor loja do mundo
 * Professor(a): Graziela Santos de Araujo
 * Comando usado para compilacao: gcc  brfree.cpp listas/* -o brfree -Wall
 */

#include "./cabecalhos/funcoes_listas.h"

void leituraArq(char *nome, produto *&lista);

int main()
{
    produto *listaDeProdutos = NULL;
    venda *listaVendas = NULL;
    char nome_do_arquivo[MAX + 1]; // nome do arquivo a ser aberto
    int *opcao;

    printf("Digite nome arquivo com dados dos produtos: ");
    scanf(" %s", nome_do_arquivo);

    // funcao para carregar dados na lista
    leitura_produtos(nome_do_arquivo, listaDeProdutos);

    do
    {
        menu(opcao);

        switch (*opcao)
        {
        case 1:
            cadastrar_venda(listaVendas, listaDeProdutos);
            break;

        case 2:
            imprime_vendas_por_data(listaVendas);
            break;

        case 3:
            alterar_dado_produto(listaDeProdutos);
            break;

        case 4:
            remover_produto(listaDeProdutos, listaVendas);
            break;

        case 5:
            printf("Ate mais :)\n");
            break;

        default:
            break;
        }

    } while (*opcao != 5);

    desalocar_lista_produtos(listaDeProdutos);

    printf("\n");
    return 0;
}

void menu(int *&opcao)
{

    printf("------------------\n");
    printf("Menu de opcoes:\n\n");
    printf("[1] - Cadastrar Venda\n");
    printf("[2] - Listas vendas por data\n");
    printf("[3] - Alterar estoque e preco de produto\n");
    printf("[4] - Remover produto do estoque\n");
    printf("[5] - Sair\n\n");
    printf("Opcao: ");

    // Leitura da opcao do usuario
    scanf("%d", &*opcao);

    printf("\n");
}