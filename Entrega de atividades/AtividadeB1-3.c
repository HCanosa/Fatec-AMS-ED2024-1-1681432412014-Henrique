#include <stdio.h>

#define TAMANHO_ARRAY 5

void preencherArray(int array[]) {
  printf("Digite %d Notas:\n", TAMANHO_ARRAY);
  for (int i = 0; i < TAMANHO_ARRAY; i++) {
    scanf("%d", &array[i]);
  }
}

int encontrarMaiorElemento(int array[]) {
  int maior = array[0];
  for (int i = 1; i < TAMANHO_ARRAY; i++) {
    if (array[i] > maior) {
      maior = array[i];
    }
  }
  return maior;
}

int calcularSomaArray(int *array, int tamanho) {
  int soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += *(array + i);
  }
  return soma;
}

void imprimirArray(int *array, int tamanho) {
  printf("Array: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", *(array + i));
  }
  printf("\n");
}

void multiplicarArray(int *array, int valor) {
  for (int i = 0; i < TAMANHO_ARRAY; i++) {
    *(array + i) *= valor;
  }
}

int main() {
  int array[TAMANHO_ARRAY];

  preencherArray(array);

  int maiorElemento = encontrarMaiorElemento(array);
  printf("O maior nota é: %d\n", maiorElemento);

  int soma = calcularSomaArray(array, TAMANHO_ARRAY);
  printf("A soma de todos as notas é: %d\n", soma);

  imprimirArray(array, TAMANHO_ARRAY);

  int valor;
  printf("Digite o valor pelo qual multiplicara as notas: ");
  scanf("%d", &valor);
  multiplicarArray(array, valor);
  imprimirArray(array, TAMANHO_ARRAY);

  return 0;
}