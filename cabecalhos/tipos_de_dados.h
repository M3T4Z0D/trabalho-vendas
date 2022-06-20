#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40
#define DATA_TAM 10
#define HORA_MIN_SEC_TAM 8
#define CPF_TAM 11

struct produto{
    int codigo_produto;
    char desc[MAX + 1];
    double preco;
    int quantidade_em_estoque;
    struct produto *proximo;
};

struct produtoVendido{
    int codigo_produto;
    double preco_venda;
    int quantidade_vendida;
    struct produtoVendido *proximo;
};

struct venda{
    char data_venda[DATA_TAM + 1];
    char hora_venda[HORA_MIN_SEC_TAM + 1];
    char cpf_cliente[CPF_TAM + 1];
    struct produtoVendido *listaProdutos;
    struct venda *proxima; 
    struct venda *anterior;
};