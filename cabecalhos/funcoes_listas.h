#include "tipos_de_dados.h"

/* FUNCOES LISTA VENDAS */
void inserir_venda_inicio(venda *&novaVenda, venda *&listaVendas);
void imprime_lista_vendas(venda *&listaVendas);
void cadastrar_venda(venda *&listaVendas, produto *&listaProdutos);\
void imprime_vendas_por_data(venda *&listaVendas);
bool buscarItemVendido(int codigo, venda *&listaVendas);
void desalocar_vendas(venda *&listaVendas);

/* FUNCOES LISTA DE PRODUTOS */
void imprimir_produtos(produto *lst);
void inserir_produto(produto *&lst, int codigo, char *desc, double preco, int estoque);
void desalocar_lista_produtos(produto *&listaProdutos);
void remover_produto(produto *&listaProdutos, venda *&listaVendas);
void alterar_dado_produto(produto *&listaProdutos);
void leitura_produtos(char *nome, produto *&lista);
produto* buscarProdutoNoEstoque(int codigo, int quantidade, produto *&listaProdutos);

/* FUNCOES LISTAS ITENS VENDIDOS */
void imprimir_itens_vendidos(produtoVendido *lst);
void desalocar_itens_vendidos(produtoVendido *&listaProdutosVendidos);
void inserir_produto_vendido_fim(int codigo, double valor, int quantidade, produtoVendido *&listaProdutosVendidos);
double calcularPrecoTotalDoCarrinho(produtoVendido *&listaProdutosVendidos);

/* GENÉRICOS */
void menu(int *&opcao);