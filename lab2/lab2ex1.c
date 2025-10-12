#include <stdio.h>
#include "../tlseint/TLSEINT.h"
#include "../tab/tab.h"

int aux(TAB*a, int elem, TLSEINT **lista) {
    if (!a) return 0;
    if (a->info == elem) {
        (*lista) = TLSEINT_insere(*lista, INT_MIN, INT_MAX);
        return 1;
    }
    if (a->info > elem) {
        (*lista) = TLSEINT_insere(*lista, INT_MIN, a->info);
    } else {
        (*lista) = TLSEINT_insere(*lista, a->info, INT_MAX);
    }
    int res = aux(a->esq, elem, lista);
    if (res) return 1;
    res = aux(a->dir, elem, lista);
    if (res) return 1;
    (*lista) = TLSEINT_retira_rec(*lista, a->info);
    return 0;
}

TLSEINT* misc(TAB*a, int elem) {
    if (!a) return NULL;
    if (!TAB_busca(a, elem)) return NULL;
    TLSEINT* lista = TLSEINT_inicializa();
    aux(a, elem, &lista);
    return lista;
}

int main(){
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18};
    TAB* a = v2ab(vet, 8);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    TLSEINT *l = misc(a, 2);
    TLSEINT_imprime(l);
    TLSEINT_libera(l);
    TAB_libera(a);
    return 0;
}