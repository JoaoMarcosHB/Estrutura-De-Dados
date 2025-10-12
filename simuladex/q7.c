#include "../tabb/tabb.h"
#include <stdio.h>
int pAux(TABB*orig, TABB*a, int S) {
    if (!a) return 0;
    if (TABB_busca(orig, S - a->info)) return 1;
    return pAux(orig, a->esq, S) || pAux(orig, a->dir, S);
}

int temPar(TABB*a, int S) {
    return pAux(a, a, S);
}

int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 21);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 25);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 16);
    a = TABB_insere(a, 27);
    a = TABB_insere(a, 35);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 40);
    a = TABB_insere(a, 18);
    a = TABB_insere(a, 22);
    a = TABB_insere(a, 12);
    a = TABB_insere(a, 28);
    a = TABB_insere(a, 8);
    TABB_imp_ident(a);
    int s = 36;
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    printf("Tem par que soma (%d): %d\n",s, temPar(a, s));
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    TABB_libera(a);
    return 0;
}