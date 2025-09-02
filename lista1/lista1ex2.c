#include "../tab/tab.h"
#include <stdio.h>

TAB* TAB_espelho(TAB*a) {
    if (!a) return NULL;
    return TAB_cria(a->info, TAB_espelho(a->dir), TAB_espelho(a->esq));
}
int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9};
    TAB* a = v2ab(vet, 14);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    TAB*b = TAB_espelho(a);
    TAB_imp_ident(b);
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}