#include <stdio.h>
#include "../tg/TG.h"
#include "../tlse/tlse.h"
typedef struct tlsegcic {
    int info;
    int pai;
    struct tlsegcic* prox;
}TLSEGCIC;

TLSEGCIC* TLSEGCIC_retira(TLSEGCIC *l, int elem){
    TLSEGCIC *p = l, *ant = NULL;
    while((p) && (p->info != elem)){
        ant = p;
        p = p->prox;
    }
    if(!p) return l;
    if(!ant) l = l->prox;
    else ant->prox = p->prox;
    free(p);
    return l;
}
TLSEGCIC* TLSEGCIC_insere(TLSEGCIC *l, int elem, int pai){
    TLSEGCIC *novo = (TLSEGCIC *) malloc(sizeof(TLSEGCIC));
    novo->prox = l;
    novo->pai = pai;
    novo->info = elem;
    return novo;
}
TLSEGCIC* TLSEGCIC_busca(TLSEGCIC *l, int elem){
    TLSEGCIC *p = l;
    while((p) && (p->info != elem)) p = p->prox;
    return p;
}
void TLSEGCIC_libera(TLSEGCIC *l){
    TLSEGCIC *p = l, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}
int dir_ciclico(TG*g) {
    if (!g) return 0;
    int conect = conectado(g);
    if (!conect) return conect;
    TLSE*visit = NULL;
    TLSEGCIC*nvisit = TLSEGCIC_insere(NULL, g->id_no, INT_MAX);
    int pai = INT_MAX, cic = 0;
    while (nvisit) {
        TG*no = TG_busca_no(g, nvisit->info);
        pai = nvisit->pai;
        if (!no) break;
        TVIZ*v = no->prim_viz;
        while (v) {
            if (TLSE_busca(visit, v->id_viz) && v->id_viz != pai) {
                cic = 1;
                break;
            }
            if (!TLSEGCIC_busca(nvisit, v->id_viz) && v->id_viz != pai) nvisit = TLSEGCIC_insere(nvisit, v->id_viz,no->id_no);
            v = v->prox_viz;
        }
        if (cic) break;
        nvisit = TLSEGCIC_retira(nvisit, no->id_no);
        visit = TLSE_insere(visit, no->id_no);
    }
    TLSEGCIC_libera(nvisit);
    TLSE_libera(visit);
    return cic;
}

int main() {
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

    TG_ins_aresta(g,  10,  99);
    TG_ins_aresta(g,  99,  109);
    TG_imprime(g);
    printf("Ciclico: %d\n", dir_ciclico(g));
    TG_libera(g);

    return 0;
}