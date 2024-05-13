/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B2-4 - Implemementar fila de atendimento - Hospital *
 * Para: Prof Veríssimo * * Objetivo: conceitos de fila *
 * Autor: Henrique * * Data:13/05/2024 *
 * *----------------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 100

typedef struct {
    char nome[50];
    int idade;
    char motivo[100];
    int prioridade;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_FILA];
    int inicio, fim;
} FilaAtendimento;

void inicializarFila(FilaAtendimento *fila) {
    fila->inicio = 0;
    fila->fim = -1;
}

int filaVazia(FilaAtendimento *fila) {
    return (fila->fim < fila->inicio);
}

void adicionarPaciente(FilaAtendimento *fila, Paciente paciente) {
    if (fila->fim < MAX_FILA - 1) {
        fila->fim++;
        fila->pacientes[fila->fim] = paciente;
    } else {
        printf("Fila cheia! Impossível adicionar paciente.\n");
    }
}

void removerPaciente(FilaAtendimento *fila) {
    if (!filaVazia(fila)) {
        for (int i = fila->inicio; i < fila->fim; i++) {
            fila->pacientes[i] = fila->pacientes[i + 1];
        }
        fila->fim--;
    }
}

void atenderPacientes(FilaAtendimento *filaNormal, FilaAtendimento *filaPrioritaria, FilaAtendimento *filaUrgente, int n) {
    int count = 0;

    while (!filaVazia(filaUrgente)) {
        printf("Atendendo paciente URGENTE: %s\n", filaUrgente->pacientes[filaUrgente->inicio].nome);
        removerPaciente(filaUrgente);
    }

    while (count < n && !filaVazia(filaNormal)) {
        printf("Atendendo paciente NORMAL: %s\n", filaNormal->pacientes[filaNormal->inicio].nome);
        removerPaciente(filaNormal);
        count++;
    }

    if (count < n) {
        while (count < n && !filaVazia(filaPrioritaria)) {
            printf("Atendendo paciente PRIORITÁRIO: %s\n", filaPrioritaria->pacientes[filaPrioritaria->inicio].nome);
            removerPaciente(filaPrioritaria);
            count++;
        }
    }
}

void mostrarFila(FilaAtendimento *fila) {
    printf("Fila de Atendimento:\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("Nome: %s | Idade: %d | Motivo: %s | Prioridade: %d\n",
               fila->pacientes[i].nome, fila->pacientes[i].idade,
               fila->pacientes[i].motivo, fila->pacientes[i].prioridade);
    }
    printf("\n");
}

int main() {
    FilaAtendimento filaNormal, filaPrioritaria, filaUrgente;
    inicializarFila(&filaNormal);
    inicializarFila(&filaPrioritaria);
    inicializarFila(&filaUrgente);

    
    Paciente p1 = {"Maria", 35, "Dor de cabeça", 0};  // Normal
    Paciente p2 = {"João", 65, "Consulta de rotina", 1};  // Prioritário
    Paciente p3 = {"Pedro", 50, "Febre alta", 2};  // Urgente

    adicionarPaciente(&filaNormal, p1);
    adicionarPaciente(&filaPrioritaria, p2);
    adicionarPaciente(&filaUrgente, p3);

    printf("Filas antes do atendimento:\n");
    mostrarFila(&filaNormal);
    mostrarFila(&filaPrioritaria);
    mostrarFila(&filaUrgente);

    atenderPacientes(&filaNormal, &filaPrioritaria, &filaUrgente, 2);

    printf("Filas após o atendimento:\n");
    mostrarFila(&filaNormal);
    mostrarFila(&filaPrioritaria);
    mostrarFila(&filaUrgente);

    return 0;
}
