#include <stdio.h>
#include "../tab/tab.h"
int naux(TAB*a, int k, int nivel) {
    if (!a) return -1;
    if (a->info == k) return nivel;
    int ret = naux(a->esq, k, nivel + 1);
    if (ret != -1) return ret;
    return naux(a->dir, k, nivel + 1);
}

int nivel(TAB*a, int k) {
    return naux(a, k, 0);
}
int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, -2, 30, 20, 25, 9, 60};
    TAB* a = v2ab(vet, 16);
    TAB_imp_ident(a);
    int k = 4;
    printf("Nivel (%d): %d\n",k,  nivel(a,k));
    TAB_libera(a);
    return 0;
}