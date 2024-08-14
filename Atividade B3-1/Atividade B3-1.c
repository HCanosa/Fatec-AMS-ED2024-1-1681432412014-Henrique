/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B3-1-Cálculo tempo execuçao-Insertion Sort *
 * Para: Prof Veríssimo * * Objetivo: Tempo de execução *
 * Autor: Henrique * * Data:13/08/2024 *
 * *--------------------------------------------------------------**/

// 10t(n) + 10t(n²) + 2t

#include <stdio.h>
                                                    
int * organizar_arry(int arr[], int num) { // t
    for(int v = 1; v < num; v++) {         // 3t(n) 
        int key = arr[v];                  // 2t(n)
        int i = v - 1;                     // 2t(n)
        while(i >= 0 && arr[i] > key) {    // 4t(n²)
            arr[i + 1] = arr[i];           // 4t(n²)
            i -= 1;                        // 2t(n²)
        }
        arr[i + 1] = key;                  // 3t(n)
    }
    return arr;                            // t
}



void print(int arr[], int num) {
    for(int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int arry[] = {14, 21, 91, 7, 2};
    print(organizar_arry(arry, 5), 5);
}
