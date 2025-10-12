#include <stdio.h>
#include "../tlseint/TLSEINT.h"
#include "../tabb/tabb.h"

void aux(TABB*a, int elem, TLSEINT **lista) {
    if (!a) return;
    if (a->info == elem) {
        (*lista) = TLSEINT_insere(*lista, INT_MIN, INT_MAX);
        return;
    }
    if (a->info > elem) {
        (*lista) = TLSEINT_insere(*lista, INT_MIN, a->info);
        aux(a->esq, elem, lista);
    } else {
        (*lista) = TLSEINT_insere(*lista, a->info, INT_MAX);
        aux(a->dir, elem, lista);
    }
}

TLSEINT* misc(TABB*a, int elem) {
    if (!a) return NULL;
    if (!TABB_busca(a, elem)) return NULL;
    TLSEINT* lista = TLSEINT_inicializa();
    aux(a, elem, &lista);
    return lista;
}

int main(){
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 20);
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
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    TLSEINT *l = misc(a, 8);
    TLSEINT_imprime(l);
    TLSEINT_libera(l);
    TABB_libera(a);
    return 0;
}