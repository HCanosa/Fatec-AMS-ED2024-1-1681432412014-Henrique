/* -----------------------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados * * Aula #7 - Exemplos utilizados
 * * Nomes: Eric/Henrique no caderno de teoria * * Objetivo: conceitos de STRUCT
 * ** * * Autor: Prof Veríssimo * * Data:02/04/2024*
 * *-------------------------------------------------------------------------------**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estoque.h"

// Definindo a estrutura do nó da lista
struct Node {
  int id;
  char nome[100];
  float preco;
  struct Node *proximo;
};

// Função para criar um novo nó
struct Node *criarNode(int id, const char *nome, float preco) {
  struct Node *novoNode = (struct Node *)malloc(sizeof(struct Node));
  novoNode->id = id;
  strcpy(novoNode->nome, nome);
  novoNode->preco = preco;
  novoNode->proximo = NULL;
  return novoNode;
}

// Função para deletar um produto da lista
void deletarProduto(struct Node **lista, int id) {
  struct Node *atual = *lista;
  struct Node *anterior = NULL;

  // Caso o produto a ser deletado seja o primeiro da lista
  if (atual != NULL && atual->id == id) {
    *lista = atual->proximo; // Atualiza o ponteiro da lista para apontar para o
                             // próximo nó
    free(atual);             // Libera a memória do nó deletado
    return;
  }

  // Percorre a lista até encontrar o nó com o ID correspondente ou até chegar
  // ao final da lista
  while (atual != NULL && atual->id != id) {
    anterior = atual;
    atual = atual->proximo;
  }

  // Se o ID for encontrado, atualiza os ponteiros para remover o nó
  // correspondente
  if (atual != NULL) {
    anterior->proximo = atual->proximo;
    free(atual);
  }
}

// Função para imprimir a lista
void imprimirLista(struct Node *lista) {
  while (lista != NULL) {
    printf("ID: %d, Nome: %s, Preço: %.2f\n", lista->id, lista->nome,
           lista->preco);
    lista = lista->proximo;
  }
}

int main() {
  // Criando alguns nós para simular uma lista ligada
  struct Node *lista = NULL;
  lista = criarNode(1, "Produto A", 10.50);
  lista->proximo = criarNode(2, "Produto B", 20.75);
  lista->proximo->proximo = criarNode(3, "Produto C", 15.00);

  printf("Lista antes da exclusão:\n");
  imprimirLista(lista);

  // Excluindo o produto com ID igual a 2
  deletarProduto(&lista, 2);

  printf("\nLista após a exclusão:\n");
  imprimirLista(lista);

  return 0;
}
