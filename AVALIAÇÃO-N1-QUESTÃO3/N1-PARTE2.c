#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do pacote
typedef struct {
    int id;
    char cidadeOrigem[50];
    char cidadeDestino[50];
    int status;
    char conteudo[100];
} Pacote;

// Função para inserir um novo pacote na lista
void inserir(Pacote lista[], int *contador) {
    printf("ID do pacote: %d\n", *contador + 2);
    lista[*contador].id = *contador + 2;
    printf("Cidade de origem: ");
    scanf("%s", lista[*contador].cidadeOrigem);
    printf("Cidade de destino: ");
    scanf("%s", lista[*contador].cidadeDestino);
    printf("Situação do pacote (1 para em processamento, 2 para em trânsito, 3 para em espera, 4 para entregue, 99 para extravido): ");
    scanf("%d", &lista[*contador].status);
    printf("Conteúdo do pacote: ");
    scanf("%s", lista[*contador].conteudo);
    (*contador)++;
}

// Função para alterar os dados de um pacote existente
void alterar(Pacote lista[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (lista[i].id == id) {
            printf("Novo ID do pacote: %d\n", id + 2);
            lista[i].id = id + 2;
            printf("Nova situação do pacote (1 para em processamento, 2 para em trânsito, 3 para em espera, 4 para entregue, 99 para extravido): ");
            scanf("%d", &lista[i].status);
            return;
        }
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}

// Função para consultar um pacote por ID
void consultar(Pacote lista[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (lista[i].id == id) {
            printf("ID do pacote: %d\n", lista[i].id);
            printf("Cidade de origem: %s\n", lista[i].cidadeOrigem);
            printf("Cidade de destino: %s\n", lista[i].cidadeDestino);
            printf("Situação do pacote: %d\n", lista[i].status);
            printf("Conteúdo do pacote: %s\n", lista[i].conteudo);
            return;
        }
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}

// Função para listar todos os pacotes
void listar(Pacote lista[], int contador) {
    printf("Lista de pacotes:\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d, Origem: %s, Destino: %s, Situação: %d, Conteúdo: %s\n",
               lista[i].id, lista[i].cidadeOrigem, lista[i].cidadeDestino,
               lista[i].status, lista[i].conteudo);
    }
}

int main() {
    Pacote lista[100]; // Supondo que a lista pode ter até 100 pacotes
    int contador = 0;
    int opcao, id;

    do {
        printf("\n1. Inserir\n2. Alterar\n3. Consultar\n4. Listar\n5. Sair\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir(lista, &contador);
                break;
            case 2:
                printf("Insira o ID do pacote a ser alterado: ");
                scanf("%d", &id);
                alterar(lista, contador, id);
                break;
            case 3:
                printf("Insira o ID do pacote a ser consultado: ");
                scanf("%d", &id);
                consultar(lista, contador, id);
                break;
            case 4:
                listar(lista, contador);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}