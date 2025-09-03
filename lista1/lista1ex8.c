#include "../tab/tab.h"
#include <stdio.h>

int ni(TAB*a) {
    if (!a) return 0;
    if ((a->esq)||(a->dir)) return 1 + ni(a->esq) + ni(a->dir);
    return 0;
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9, 23, 24, 25};
    TAB* a = v2ab(vet, 17);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    printf("Qtd nos internos: %d\n", ni(a));
    TAB_libera(a);
    return 0;
}