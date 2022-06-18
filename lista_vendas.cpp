#include "listas.h"

void imprime_lista_vendidos(venda *lst)
{
    venda *venda;

    for (venda = lst; venda != NULL; venda = venda->proxima){ 
        printf("Data venda: %s \n", venda->data_venda);
        printf("Hora venda: %s \n", venda->hora_venda);
        printf("CPF cliente: %s \n", venda->cpf_cliente);
        // TO-DO: adicionar print da lista de itens vendidos
    }
}