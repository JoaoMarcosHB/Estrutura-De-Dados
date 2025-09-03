#include "../tab/tab.h"
#include <stdio.h>

int maior_aux(TAB*a, int maior) {
    if (!a) return maior;
    if (a->info > maior) maior = a->info;
    int e = maior_aux(a->esq, maior);
    if (e > maior) maior = e;
    int d = maior_aux(a->dir, maior);
    if (d > maior) maior = d;
    return maior;
}

int TAB_maior(TAB*a) {
    if (a) return maior_aux(a, a->info);
    return -999;
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9, 60};
    TAB* a = v2ab(vet, 15);
    TAB_imp_ident(a);
    printf("Maior: %d\n", TAB_maior(a));
    TAB_libera(a);
    return 0;
}