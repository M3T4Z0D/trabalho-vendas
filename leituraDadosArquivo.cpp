#include <stdio.h>  /*printf*/
#include <string.h> /*strcpy*/
#include <stdlib.h> /*malloc, calloc, free*/
#define MAX 40

struct celProd
{
    int codprod;
    char desc[MAX + 1];
    double preco;
    int estoque;
    struct celProd *prox;
};

// funcao para desalocar todos os nos da lista
void desalocar(celProd *&L);

// funcao para inserir um novo produto sempre no fim da lista
void inserir_fim(celProd *&lst, int codprod, char *desc,
                 double preco, int estoque);

// funcao para imprimir todos os nos da lista
void imprimir(celProd *lst);

// funcao para ler os dados do arquivo 'nome' e armazena-los na lista
// encadeada
void leituraArq(char *nome, celProd *&lista);

// funcao principal
int main()
{
    celProd *lista = NULL; /*lista sem cabeca vazia*/
    char nome[MAX + 1];    // nome do arquivo a ser aberto

    printf("Digite nome arquivo com dados dos produtos: ");
    scanf(" %s", nome);

    // funcao para carregar dados na lista
    leituraArq(nome, lista);

    // imprimir dados da lista
    imprimir(lista);
    printf("\n");

    /*apagar toda a lista encadeada alocada dinamicamente*/
    desalocar(lista);

    return 0;
}

/*leitura dos dados dos produtos do arquivo --> armazenando-os na lista
simplesmente encadeada*/
void leituraArq(char *nome, celProd *&lista)
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
            inserir_fim(lista, codigo, nomep,
                        preco, estoque);

            // tenta ler o proximo codigo de produto
            fscanf(arq, "%d", &codigo);
        }
        // fechamento do arquivo
        fclose(arq);
    }
}

/*Funcao imprime os dados armazenados em cada no da lista L*/
void imprimir(celProd *lst)
{
    celProd *p;

    for (p = lst; p != NULL; p = p->prox)
        printf("%d %s %.2f %d\n", p->codprod, p->desc, p->preco, p->estoque);
}

void inserir_fim(celProd *&lst, int codprod, char *desc, double preco, int estoque)
{
    celProd *novo, *p;

    // alocacao do no
    novo = (celProd *)calloc(1, sizeof(celProd));
    // copiando cada campo
    novo->codprod = codprod;
    strcpy(novo->desc, desc);
    novo->preco = preco;
    novo->estoque = estoque;

    if (lst == NULL)
        lst = novo;
    else
    {
        p = lst;
        while (p->prox != NULL)
            p = p->prox;

        p->prox = novo;
    }
}

// Funcao que apaga todos os nos da lista L
void desalocar(celProd *&L)
{
    celProd *aux;

    while (L != NULL)
    {
        aux = L;

        L = aux->prox;

        free(aux);
    }
}
