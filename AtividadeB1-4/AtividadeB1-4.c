#include <stdio.h>

/*---------------------------------------------------------------------*/
/*     FATEC-AR                      Estrutura de Dados                */ 
/*     Lab9 :  Listas - Estrutura de Arranjos                          */
/*     Prof. Carlos Henrique Veríssimo                                 */
/*---------------------------------------------------------------------*/
/* Programa: listaLigadaNo.C                                           */
/* Função: cria uma lista que recebe as função de entrada e processos:
0 - Sair
1 - Incluir
2 - Consultar
3 - Deletar
4 - Listar todos,                                                      */
/*---------------------------------------------------------------------*/

/* Definição da estrutura de nó */
struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

/* Função de criação de lista */
Lista* lst_cria(void) {
    return NULL;
}

/* Função de inserção no início */
Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* Função de impressão */
void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("%d\n", p->info);
}

/* Função para verificar se a lista está vazia */
int lst_vazia(Lista* l) {
    if (l == NULL)
        return 1;
    else
        return 0;
}

/* Função para buscar um elemento na lista */
int lst_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            printf("Encontrou: %d\n", v);
            return 1;
        }
    }
    printf("Nao encontrou: %d\n", v);
    return 0;
}

/* Função para liberar a memória ocupada pela lista */
void lst_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

/* Função para deletar um elemento da lista */
int lst_deleta(Lista** l, int v) {
    Lista* ant = NULL; /* ponteiro para elemento anterior*/
    Lista* p = *l;     /* ponteiro para percorrer a lista*/

    /* Procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    /* Verifica se achou elemento */
    if (p == NULL) {
        printf("Nao encontrou elemento para DELETAR: %d\n", v);
        return 1; /* não achou, retorna 1 */
    }

    /* Retira elemento */
    if (ant == NULL) {
        /* retira elemento do início*/
        *l = p->prox;
    } else {
        /* retira elemento do meio da lista*/
        ant->prox = p->prox;
    }

    free(p);
    return 0;
}

/* Função para listar todos os elementos da lista */
void lst_listar_todos(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista de elementos:\n");
    lst_imprime(l);
}

int main(void) {
    Lista *l;
    int opcao, item;

    /* Cria a lista */
    l = lst_cria();

    while (1) {
        /* Menu de opções */
        printf("\nEscolha uma opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Incluir na lista\n");
        printf("2 - Consultar na lista\n");
        printf("3 - Deletar elemento da lista\n");
        printf("4 - Listar todos os elementos\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                /* Sair do programa */
                lst_libera(l);
                return 0;
            case 1:
                /* Inserir elemento na lista */
                printf("Insira o item na lista:\n");
                scanf("%d", &item);
                if (item != 0)
                    l = lst_insere(l, item);
                break;
            case 2:
                /* Consultar elemento na lista */
                printf("Insira o valor a ser consultado:\n");
                scanf("%d", &item);
                lst_busca(l, item);
                break;
            case 3:
                /* Deletar elemento da lista */
                printf("Insira o valor a ser deletado:\n");
                scanf("%d", &item);
                lst_deleta(&l, item);
                break;
            case 4:
                /* Listar todos os elementos da lista */
                lst_listar_todos(l);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
    return 0;
}
