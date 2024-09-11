/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B3-3-Análise Assintótica dos algorimos *
 * Para: Prof Veríssimo * * Objetivo: Implementação de algoritmos de busca *
 * Autor: Henrique Canosa * * Data:11/09/2024 *
 * *--------------------------------------------------------------**/

int busca_binaria(int A[], int n, int x) {
  int bottom = 1;
  int top = n;

  while (bottom <= top) {
    int mid = (((int)(bottom + top)) / 2);

    if (A[mid] == x)
      return mid;
    else if (x > A[mid])
      bottom = mid + 1;
    else
      top = mid - 1;
  }

  return -1;
}