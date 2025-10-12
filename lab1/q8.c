#include "../tlse/tlse.h"
#include "../tg/TG.h"

int conectado(TG*g) {
    if (!g) return 0;
    TLSE*visit = NULL, *nvisit = TLSE_insere(NULL, g->id_no);
    while (nvisit) {
        TG*no = TG_busca_no(g, nvisit->info);
        if (!no) break;
        visit = TLSE_insere(visit, no->id_no);
        nvisit = TLSE_retira(nvisit, no->id_no);
        TVIZ* v = no->prim_viz;
        while (v) {
            if ((!TLSE_busca(visit, v->id_viz) && (!TLSE_busca(nvisit, v->id_viz)))) {
                nvisit = TLSE_insere(nvisit, v->id_viz);
            }
            v = v->prox_viz;
        }
    }
    TLSE_libera(nvisit);//Acho que não precisaria pq só chega aqui qd for null;
    int conect = 1;
    TG*aux = g;
    while (aux) {
        if (!TLSE_busca(visit, aux->id_no)) {
            conect = 0;
            break;
        }
        aux = aux->prox_no;
    }
    TLSE_libera(visit);
    return conect;
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
    TG_ins_aresta(g, 10, 1);
    TG_ins_aresta(g, 1, 33);
    TG_ins_aresta(g,  33,  42);
    TG_ins_aresta(g,  42,  7);
    TG_ins_aresta(g,  7,  99);
    TG_ins_aresta(g,  99,  12);
    TG_ins_aresta(g,  12,  109);
    // TG_ins_aresta(g,  1,  42);
    // TG_ins_aresta(g,  99,  109);
    // TG_ins_aresta(g,  99,  42);
    // TG_ins_aresta(g,  12,  1);
    // TG_ins_aresta(g,  10,  109);


    TG_imprime(g);
    int n = conectado(g);
    printf("Conectado: %d\n", n);
    TG_libera(g);
    return 0;
}