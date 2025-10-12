#include <stdio.h>
#include "../tab/tab.h"
int maioresQue(TAB*a, int k) {
    if (!a) return 1;
    if (a->info < k) return 0;
    return maioresQue(a->esq, k) && maioresQue(a->dir, k);
}

int menoresQue(TAB*a, int k) {
    if (!a) return 1;
    if (a->info > k) return 0;
    return menoresQue(a->esq, k) && menoresQue(a->dir, k);
}

int eh_TABB (TAB*a) {
    if (!a) return 1;
    if (((a->esq) && (a->esq->info > a->info)) || ((a->dir) && (a->dir->info < a->info))) return 0;
    int ret = menoresQue(a->esq, a->info) && maioresQue(a->dir, a->info);
    if (!ret) return ret;
    return eh_TABB(a->esq) && eh_TABB(a->dir);
}

int main(void) {
    int vet[] = {1,2,3,4,5,6,7};
    TAB* a = v2ab(vet, 7);
    TAB_imp_ident(a);
    printf("TABB: %d\n",  eh_TABB(a));
    TAB_libera(a);
    return 0;
}