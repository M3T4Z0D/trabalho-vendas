#include "listas.h"

void leituraArq(char *nome, produto *&lista);

int main()
{
    produto *listaDeProdutos = NULL;
    venda *listaVendas = NULL;
    char nome_do_arquivo[MAX + 1]; // nome do arquivo a ser aberto

    printf("Digite nome arquivo com dados dos produtos: ");
    scanf(" %s", nome_do_arquivo);

    // funcao para carregar dados na lista
    leituraArq(nome_do_arquivo, listaDeProdutos);

    // imprimir dados da lista
    imprimir_produtos(listaDeProdutos);
    printf("\n");
    
    return 0;
}

void leituraArq(char *nome, produto *&lista)
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
        // leitura do primeiro dado
        fscanf(arq, "%d", &codigo);
        while (feof(arq) == 0)
        {
            // leitura dos demais dados
            fscanf(arq, " %[^\n]", nomep);
            fscanf(arq, "%lf", &preco);
            fscanf(arq, "%d", &estoque);

            // inseri dados do produto lido na lista
            inserir_produto(lista, codigo, nomep,
                        preco, estoque);

            // tenta ler o proximo codigo de produto
            fscanf(arq, "%d", &codigo);
        }
        // fechamento do arquivo
        fclose(arq);
    }
}