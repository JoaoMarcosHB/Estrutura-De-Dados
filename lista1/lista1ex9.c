#include "../tab/tab.h"
#include <stdio.h>

int nf(TAB*a) {
    if (!a) return 0;
    if ((!a->esq)&&(!a->dir)) return 1;
    return 0 + nf(a->esq) + nf(a->dir);
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9, 11};
    TAB* a = v2ab(vet, 15);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    printf("Qtd nos folha: %d\n", nf(a));
    TAB_libera(a);
    return 0;
}