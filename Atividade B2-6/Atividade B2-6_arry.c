/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B2-6 - Implemementar arry e inceriri dados no meio dela *
 * Para: Prof Veríssimo * * Objetivo: conceitos de fila *
 * Autor: Henrique * * Data:27/05/2024 *
 * *----------------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void insertInLinkedList(struct Node** head_ref, int value, int pos) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;

    if (pos == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        new_node->next = NULL;
        temp->next = new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = NULL;

    int value = 30;
    int pos = 2; // Posição onde será inserido (meio da lista)

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertInLinkedList(&head, value, pos);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Lista após inserção: ");
    printList(head);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
