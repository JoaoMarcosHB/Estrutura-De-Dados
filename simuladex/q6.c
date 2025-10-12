#include "../tabb/tabb.h"
#include <stdio.h>
int maiorjm(int x, int y) {
    if (x >= y) return x;
    return y;
}
int alturajm(TABB*a) {
    if (!a) return -1;
    return maiorjm(alturajm(a->esq), alturajm(a->dir))+1;
}

int eh_AVL(TABB* a) {
    if (!a) return 1;
    int fb = alturajm(a->esq) - alturajm(a->dir);
    if (fb < -1 || fb > 1) return 0;
    return eh_AVL(a->esq) && eh_AVL(a->dir);
}

int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 21);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 25);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 16);
    a = TABB_insere(a, 27);
    // a = TABB_insere(a, 35);
    // a = TABB_insere(a, 3);
    // a = TABB_insere(a, 40);
    // a = TABB_insere(a, 18);
    // a = TABB_insere(a, 22);
    // a = TABB_insere(a, 12);
    // a = TABB_insere(a, 28);
    // a = TABB_insere(a, 8);
    TABB_imp_ident(a);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    printf("Eh avl: %d\n", eh_AVL(a));
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    TABB_libera(a);
    return 0;
}