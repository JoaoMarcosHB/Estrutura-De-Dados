#include <stdio.h>
#include <stdlib.h>
typedef struct tlse {
    int info;
    struct tlse* prox;
} TLSE;
typedef struct elem {
    int info;
    int qtd;
    struct tlse* pos;
    struct elem* prox;
} ELEM;

void elem_libera(ELEM* head) {
    if (head) {
        ELEM* aux = head->prox;
        TLSE* p = head->pos;
        while (p) {
            TLSE* auxiliar = p;
            p = p->prox;
            free(auxiliar);
        }
        free(head);
        elem_libera(aux);
    }
}
ELEM* ELEM_busca(ELEM* head, int x) {
    if (!head) return NULL;
    ELEM* p = head;
    while (p) {
        if (p->info == x) return p;
        p = p->prox;
    }
    return NULL;
}
void ELEM_ins_pos(ELEM* head, int pos) {
    if (!head) return;
    TLSE* novo = (TLSE*) malloc(sizeof(TLSE));
    novo->info = pos;
    novo->prox = head->pos;
    head->pos = novo;
    head->qtd = head->qtd + 1;
}
ELEM* ELEM_ins_elem(ELEM* head, int x, int pos) {
    ELEM* novo = (ELEM*) malloc(sizeof(ELEM));
    novo->info = x;
    novo->pos = NULL;
    novo->qtd = 0;
    ELEM_ins_pos(novo, pos);
    novo->prox = head;
    return novo;
}
void imprime(ELEM* head) {
    ELEM*p = head;
    while (p) {
        printf("%d: %d vezes nas posicoes: ", p->info, p->qtd);
        TLSE* aux = p->pos;
        while (aux) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
        p = p->prox;
    }
}
void resumo(char*arq) {
    FILE *fp = fopen(arq, "rt");
    if (!fp) exit(1);
    int n;
    int pos = 1;
    ELEM* lista = NULL;
    while (fscanf(fp, "%d", &n) == 1) {
        ELEM* elemento = ELEM_busca(lista, n);
        if (!elemento) {
            lista = ELEM_ins_elem(lista, n, pos);
        } else {
            ELEM_ins_pos(elemento, pos);
        }
        pos++;
    }
    imprime(lista);
    elem_libera(lista);
    fclose(fp);
}

int main(void) {
    resumo("ex3.txt");
    return 0;
}