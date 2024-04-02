#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estoque.h"

void busca_produtoPorID(struct produto *estoque, int id){
  struct produto *ptr = estoque;
  while (ptr != NULL) {
    if (ptr->id == id) {
    printf("\n*Busca por ID*\n");
    printf("Nome: %s\n", ptr->nome);
    printf("Quantidade: );
    }
  }
}