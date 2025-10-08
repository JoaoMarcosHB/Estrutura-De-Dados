#include <stdio.h>
#include "../tabb/tabb.h"
int TABB_conta_nummenor(TABB*a, int x) {
    if (!a) return 0;
    if (a->info < x) return 1 + TABB_conta_nummenor(a->esq, x) + TABB_conta_nummenor(a->dir, x);
    return TABB_conta_nummenor(a->esq, x);
}

int preenche_vetor(TABB*a, int*v, int x, int qtdpreenchida) {
    if (!a) return qtdpreenchida;
    if (a->info < x) {
        
        qtdpreenchida = preenche_vetor(a->esq, v, x, qtdpreenchida);
        v[qtdpreenchida++] = a->info;
        qtdpreenchida = preenche_vetor(a->dir, v, x, qtdpreenchida);
    } else {
        qtdpreenchida = preenche_vetor(a->esq, v, x, qtdpreenchida);
    }
    return qtdpreenchida;
}
void print_vet(int*v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int* mN(TABB*a, int N) {
    if (!a) return NULL;
    int cont = TABB_conta_nummenor(a, N);
    if (cont == 0) return NULL;
    int* v = (int*) malloc(cont*sizeof(int));
    if (!v) return NULL;
    int qtd = preenche_vetor(a, v, N, 0);
    printf("Cont: %d\n", cont);
    printf("Qtd preenchida: %d\n", qtd);
    print_vet(v, qtd);
    return v;
}


int main() {
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 21);
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
    int* v = mN(a, 21);
    printf("-=-=-=-=-=-==--==-=-=--=-=-=-=-=-==--==-=--=-\n");
    TABB_libera(a);
    free(v);
    return 0;
}