/* -----------------------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados * * Atividade B2-1 Estrutura de Pilha
 * * Professor: Prof Veríssimo * * Objetivo: Conceitos de Pilha
 * ** * * Autor: Henrique Augusto Pais Canosa * * Data:22/04/2024*
 * *-------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int *items;
    int top;
    int maxSize;
} Stack;


void initializeStack(Stack *s, int size) {
    s->items = (int *)malloc(size * sizeof(int));
    if (s->items == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1); // Encerra o programa se a alocação falhar
    }
    s->top = -1;
    s->maxSize = size;
}

int isFull(Stack *s) {
    return s->top == s->maxSize - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void freeStack(Stack *s) {
    free(s->items);
}


void push(Stack *s, int item) {
  if (isFull(s)) {
    printf("Pilha cheia.\n");
  } else {
    s->items[++s->top] = item;
    printf("Elemento %d adicionado.\n", item);
  }
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Pilha vazia.\n");
    return -1;
  } else {
    int item = s->items[s->top--];
    printf("Elemento %d removido.\n", item);
    return item;
  }
}

int peek(Stack *s) {
  if (isEmpty(s)) {
    printf("Pilha vazia.\n");
    return -1;
  } else {
    return s->items[s->top];
  }
}

void displayMenu() {
  printf("\nOperações da Pilha:\n");
  printf("1. Adicionar elemento (Push)\n");
  printf("2. Remover elemento (Pop)\n");
  printf("3. Ver o elemento do topo (Peek)\n");
  printf("4. Adicionar o elemento do topo com novo elemento\n");
  printf("5. Subtrair o elemento do topo por novo elemento\n");
  printf("6. Multiplicar o elemento do topo por novo elemento\n");
  printf("7. Dividir o elemento do topo pelo novo elemento\n");
  printf("8. Sair\n");
  printf("Escolha uma opção: ");
}
void performMathOperation(Stack *s, int operation) {
  if (isEmpty(s)) {
    printf("Pilha vazia.\n");
    return;
  }
  int num;
  printf("Digite o número para realizar a operação: ");
  scanf("%d", &num);
  int topNum = pop(s);

  switch (operation) {
  case 1: // Adição
    push(s, topNum + num);
    break;
  case 2: // Subtração
    push(s, topNum - num);
    break;
  case 3: // Multiplicação
    push(s, topNum * num);
    break;
  case 4: // Divisão
    if (num != 0) {
      push(s, topNum / num);
    } else {
      printf("Erro: divisão por zero.\n");
      push(s, topNum); // recoloca o número no topo
    }
    break;
  }
}

  int main() {
    Stack s;
    int stackSize;

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &stackSize);
    initializeStack(&s, stackSize);

    int choice, item;

  do {
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o elemento a ser adicionado: ");
      scanf("%d", &item);
      push(&s, item);
      break;
    case 2:
      pop(&s);
      break;
    case 3:
      item = peek(&s);
      if (item != -1) {
        printf("Elemento no topo: %d\n", item);
      }
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      performMathOperation(&s, choice - 3);
      break;
    case 8:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (choice != 8);

  return 0;
}