#include "../tab/tab.h"
#include <stdio.h>

TAB* TAB_copia(TAB*a) {
    if (!a) return NULL;
    return TAB_cria(a->info, TAB_copia(a->esq), TAB_copia(a->dir));
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 15,16, 19, 30, 20, 25, 9};
    TAB* a = v2ab(vet, 14);
    TAB_imp_pre(a);
    printf("\n-----------------------------------------\n");
    TAB* copia = TAB_copia(a);
    TAB_imp_pre(copia);
    printf("\n");
    TAB_libera(copia);
    TAB_libera(a);
    return 0;
}