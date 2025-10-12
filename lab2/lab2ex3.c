#include "../tab/tab.h"
#include <stdio.h>
int aux(TAB*a, int nivel) {
    if (!a) return 1;
    int cont = 0;
    if (a->esq)cont++;
    if (a->dir)cont++;
    if (nivel % 2) {
        if (cont == 1) return 0;
        int ret = aux(a->esq, nivel + 1);
        if (ret == 0) return 0;
        return aux(a->dir, nivel + 1);
    }
    if (cont != 1) return 0;
    int ret = aux(a->esq, nivel + 1);
    if (ret == 0) return 0;
    return aux(a->dir, nivel + 1);
}

int teste_arv(TAB*a) {
    return aux(a, 0);
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9, 60};
    TAB* a = v2ab(vet, 15);
    TAB_imp_ident(a);
    printf("Segue propriedade: %d\n", teste_arv(a));
    TAB_libera(a);
    return 0;
}