#include "../tab/tab.h"
#include <stdio.h>

int aux(TAB*a, int soma, int n) {
    if (!a) return 0;
    soma += a->info;
    if ((!a->esq) && (!a->dir) && (soma == n)) return 1;
    return aux(a->esq, soma, n) + aux(a->dir, soma, n);
}

int quant_caminhos(TAB*a, int n) {
    return aux(a, 0, n);
}

int main(){
    int vet[] = {13, 8, 8, 21, 1, 10, 14, 15};
    TAB* a = v2ab(vet, 8);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    printf("QTD Caminhos somam 30: %d\n", quant_caminhos(a, 30));
    TAB_libera(a);
    return 0;
}