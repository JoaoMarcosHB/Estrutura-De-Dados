#include "../tab/tab.h"
#include <stdio.h>
void colore_aux(TAB*a, int nivel) {
    if (a) {
        a->info = nivel % 2;
        colore_aux(a->esq, nivel + 1);
        colore_aux(a->dir, nivel + 1);
    }
}

void TAB_colore(TAB* a) {
    //Definimos 0 como vermelho e 1 como preto
    //Para não ter que redefinir o TAB nem outras funções, será alterado a info de cada nó,
    //como se fosse sua cor, mas seria só fazer a alteração de info para cor no código acima
    //e mudar a estrutura TAB, e as funções de criação e impressão.
    colore_aux(a, 0);
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9};
    TAB* a = v2ab(vet, 14);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    TAB_colore(a);
    TAB_imp_ident(a);
    TAB_libera(a);
    return 0;
}