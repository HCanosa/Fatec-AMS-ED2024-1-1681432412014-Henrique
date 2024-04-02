/* -----------------------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados * * Aula #7 - Exemplos utilizados * Nomes: Eric/Henrique
 * no caderno de teoria * * Objetivo: conceitos de STRUCT ** * * Autor: Prof
 * Veríssimo * * Data:02/04/2024*
 * *-------------------------------------------------------------------------------**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
  int id;
  char nome [30];
  int qtd;
  struct produto *prox;
};

void inserir_produto(struct produto **estoque, int id, char nome, int qtd) {
  struct produto *novo_produto = (struct produto *)malloc(sizeof(struct produto));
  if (novo_produto == NULL){
    printf("Erro ao alocar memória.\n");
    return;
  }
  novo_produto->id = id;
  strcpy(novo_produto->nome, nome);
  novo_produto->qtd = qtd;
  novo_produto->prox = *estoque;
  *estoque = novo_produto;
}