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

/* FUNCOES LISTA VENDAS */
void imprime_lista_vendidos(venda *lst);

/* FUNCOES LISTA DE PRODUTOS */
void inserir_produto(produto *&lst, int codigo, char *desc, double preco, int estoque);
void desalocar_lista_produtos(produto *&listaProdutos);
void remover_produto(int codigo, produto *&lst);
void imprimir_produtos(produto *lst);
void alterar_dado_produto(int codigo_produto, int estoque, double preco, produto *& listaProdutos);

/* FUNCOES LISTAS ITENS VENDIDOS */
void imprimir_itens_vendidos(produtoVendido *lst);
void desalocar(produtoVendido *&listaProdutosVendidos);
void inserir_fim(int codigo, double valor, produtoVendido *&listaProdutosVendidos);
