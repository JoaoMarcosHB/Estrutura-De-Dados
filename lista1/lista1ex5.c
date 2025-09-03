#include "../tab/tab.h"
#include <stdio.h>

int TAB_igual(TAB* a1, TAB* a2) {
    if ((!a1) && (!a2)) return 1;
    if ((!a1) || (!a2)) return 0;
    if (a1->info != a2->info) return 0;
    int resp = TAB_igual(a1->esq, a2->esq);
    if (resp == 0) return 0;
    return TAB_igual(a1->dir, a2->dir);
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, -2, 30, 20, 25, 9, 60, 7};
    TAB* a = v2ab(vet, 17);
    int vet2[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, -2, 30, 20, 25, 9, 60, 7};
    TAB* b = v2ab(vet2, 17);

    printf("Iguais: %d\n", TAB_igual(a, b));
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}