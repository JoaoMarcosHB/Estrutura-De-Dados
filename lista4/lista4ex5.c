#include <stdio.h>
#include "../tg/TG.h"
int cont_vizinhos(TVIZ*v) {
    if (!v) return 0;
    return 1 + cont_vizinhos(v->prox_viz);
}
int igAux(TG*g1, TG*g2) {
    if (!g1 && !g2) return 1;
    if (!g1 || !g2) return 0;
    TG*pg1 = g1, *pg2;
    while (pg1) {
        pg2 = TG_busca_no(g2, pg1->id_no);
        if (!pg2) return 0;
        TVIZ*pv1 = pg1->prim_viz, *pv2;
        while (pv1) {
            pv2 = TG_busca_aresta(g2, pg1->id_no, pv1->id_viz);
            if (!pv2) {

                return 0;
            }
            pv1 = pv1->prox_viz;
        }
        pg1 = pg1->prox_no;
    }
    return 1;
}

int ig(TG*g1, TG*g2) {
    return igAux(g1, g2) && igAux(g2, g1);
}

int main(void) {
    TG* g = TG_inicializa();
    g = TG_ins_no(g, 10);
    g = TG_ins_no(g, 1);
    g = TG_ins_no(g, 33);
    g = TG_ins_no(g, 42);
    g = TG_ins_no(g, 7);
    g = TG_ins_no(g, 99);
    g = TG_ins_no(g, 12);
    g = TG_ins_no(g, 109);
    TG_ins_aresta(g, 10, 33);
    TG_ins_aresta(g, 10, 1);
    TG_ins_aresta(g,  33,  42);
    TG_ins_aresta(g,  33,  12);
    TG_ins_aresta(g,  12,  7);
    TG_ins_aresta(g,  7,  99);
    TG_ins_aresta(g,  7,  109);
    TG_ins_aresta(g,  1,  42);
    TG_ins_aresta(g,  99,  109);
    TG_ins_aresta(g,  99,  42);
    TG_ins_aresta(g,  12,  1);
    TG_ins_aresta(g,  10,  109);
    TG* g2 = TG_inicializa();
    g2 = TG_ins_no(g2, 10);
    g2 = TG_ins_no(g2, 1);
    g2 = TG_ins_no(g2, 33);
    g2 = TG_ins_no(g2, 42);
    g2 = TG_ins_no(g2, 7);
    g2= TG_ins_no(g2, 99);
    g2 = TG_ins_no(g2, 12);
    g2 = TG_ins_no(g2, 109);
    TG_ins_aresta(g2, 10, 33);
    TG_ins_aresta(g2, 10, 1);
    TG_ins_aresta(g2,  33,  42);
    TG_ins_aresta(g2,  33,  12);
    TG_ins_aresta(g2,  12,  7);
    TG_ins_aresta(g2,  7,  99);
    TG_ins_aresta(g2,  7,  109);
    TG_ins_aresta(g2,  1,  42);
    TG_ins_aresta(g2,  99,  109);
    TG_ins_aresta(g2,  99,  42);
    TG_ins_aresta(g2,  12,  1);
    TG_ins_aresta(g2,  10,  109);



    //TG_imprime(g);
    int n = ig(g, g2);
    printf("Grafos Iguais: %d\n", n);
    TG_libera(g);
    TG_libera(g2);
    return 0;
}