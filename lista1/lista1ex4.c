#include "../tab/tab.h"
#include <stdio.h>

int menor_aux(TAB*a, int menor) {
    if (!a) return menor;
    if (a->info < menor) menor = a->info;
    int e = menor_aux(a->esq, menor);
    if (e < menor) menor = e;
    int d = menor_aux(a->dir, menor);
    if (d < menor) menor = d;
    return menor;
}

int TAB_menor(TAB*a) {
    if (a) return menor_aux(a, a->info);
    return -999;
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, -2, 30, 20, 25, 9, 60};
    TAB* a = v2ab(vet, 16);
    TAB_imp_ident(a);
    printf("Menor: %d\n", TAB_menor(a));
    TAB_libera(a);
    return 0;
}