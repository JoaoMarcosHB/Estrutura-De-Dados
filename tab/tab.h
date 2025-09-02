#ifndef TAB_H
#define TAB_H

typedef struct arvbin{
    int info;
    struct arvbin *esq, *dir;
}TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);
TAB *v2ab(int*vet, int n);

void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_imp_ident(TAB *a);

void TAB_libera(TAB *a);

TAB *TAB_busca(TAB *a, int elem);

int TAB_altura(TAB *a);
#endif // TAB_H
