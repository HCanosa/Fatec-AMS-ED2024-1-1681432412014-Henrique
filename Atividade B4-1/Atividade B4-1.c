include <stdio.h>

/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B4-1-Bubble Sort - Implementação *
 * Para: Prof Veríssimo * * Objetivo: Implementação de algoritmo bubbleSort *
 * Autor: Henrique Canosa * * Data:15/10/2024 *
 * *--------------------------------------------------------------**/


// Função otimizada para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Variável para verificar se houve troca

        // Itera sobre os elementos do array
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Marca que houve troca
            }
        }

        // Se não houve troca, o array já está ordenado
        if (!swapped)
            break;
    }
}

int main() {
    int n, i;

    // Solicita a quantidade de números
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int arr[n]; // Define o array com tamanho n

    // Entrada dos números no array
    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Mostra o array original
    printf("\nArray original: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Chama a função Bubble Sort para ordenar o array
    bubbleSort(arr, n);

    // Mostra o array ordenado
    printf("\nArray ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}