/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B3-3-Análise Assintótica dos algorimos *
 * Para: Prof Veríssimo * * Objetivo: Implementação de algoritmos de busca *
 * Autor: Henrique Canosa * * Data:11/09/2024 *
 * *--------------------------------------------------------------**/

int busa_linear(int A[], int n, int x) {
  for (int i = 1; i <= n; i++) {
    if (A[i] == x)
      return i;
  }

  return -1;
}