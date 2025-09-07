#include "../tabb/tabb.h"
#include <stdio.h>

TABB* retira_impares(TABB* a) {
    while (a && (a->info % 2 == 1)) a = TABB_retira(a, a->info);
    if (!a) return a;
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);
    return a;
}

int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 21);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 25);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 30);
    a = TABB_insere(a, 5);
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
    a = retira_impares(a);
    TABB_imp_ident(a);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    TABB_libera(a);
    return 0;
}