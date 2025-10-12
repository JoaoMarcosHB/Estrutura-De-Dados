#include "../tabb/tabb.h"
#include <stdio.h>
int contaElems(TABB*a) {
    if (!a) return 0;
    return 1 + contaElems(a->esq) + contaElems(a->dir);
}
void preenche_vet(TABB*a, int*vet, int*i) {
    if (!a) return;
    preenche_vet(a->esq, vet, i);
    vet[(*i)++] = a->info;
    preenche_vet(a->dir, vet, i);
}
int* vet(TABB*a) {
    if (!a) return NULL;
    int qtde = contaElems(a);
    int *vetAux = (int*)malloc(qtde * sizeof(int));
    int i = 0;
    preenche_vet(a, vetAux, &i);
    for (int j = 0; j < qtde; j++) {
        printf("%d ", vetAux[j]);
    }
    printf("\n");
    return vetAux;
}

int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 21);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 25);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 16);
    a = TABB_insere(a, 27);
    a = TABB_insere(a, 35);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 40);
    a = TABB_insere(a, 18);
    a = TABB_insere(a, 22);
    a = TABB_insere(a, 12);
    a = TABB_insere(a, 28);
    a = TABB_insere(a, 8);
    TABB_imp_ident(a);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    int* v = vet(a);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    TABB_libera(a);
    free(v);
    return 0;
}