#include "../tabb/tabb.h"
#include <stdio.h>

TABB* maior(TABB*a) { //Pela teoria da TABB, o maior nó será o nó mais a direita
    if (!a) return a;
    if (!a->dir) return a;
    return maior(a->dir);
}

int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 20);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 25);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 30);
    a = TABB_insere(a, 5);
    a = TABB_insere(a, 35);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 40);
    a = TABB_insere(a, 18);
    a = TABB_insere(a, 22);
    a = TABB_insere(a, 12);
    a = TABB_insere(a, 28);
    a = TABB_insere(a, 8);
    TABB_imp_ident(a);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    printf("Maior:\n");
    TABB* m = maior(a);
    TABB_imp_ident(m);
    TABB_libera(a);
    return 0;
}