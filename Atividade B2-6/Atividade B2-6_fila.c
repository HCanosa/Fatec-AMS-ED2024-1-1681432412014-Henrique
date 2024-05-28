/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B2-6 - Implemementar fila e inceriri dados no meio dela *
 * Para: Prof Veríssimo * * Objetivo: conceitos de fila *
 * Autor: Henrique * * Data:27/05/2024 *
 * *----------------------------------------------------------------**/

#include <stdio.h>
#include <time.h>

void insertInArray(int arr[], int size, int value, int pos) {
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
}

int main() {
    int arr[6] = {10, 25, 40, 80}; // Array inicial com espaço para mais um elemento
    int size = 4; // Tamanho atual do array
    int value = 30; // Valor a ser inserido
    int pos = size / 2; // Posição onde será inserido (meio do array)

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertInArray(arr, size, value, pos);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array após inserção: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
