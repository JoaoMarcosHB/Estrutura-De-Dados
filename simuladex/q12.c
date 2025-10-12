#include <stdio.h>
#include "../tg/TG.h"
#include "../tlse/tlse.h"
typedef struct tlsegcic {
    int info;
    int pai;
    struct tlsegcic* prox;
}TLSEGCIC;

TLSEGCIC* TLSEGCIC_retira(TLSEGCIC *l, int elem, int pai){
    TLSEGCIC *p = l, *ant = NULL;
    while((p) && (p->info != elem) && (p->pai != pai)){
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
TLSEGCIC* TLSEGCIC_busca_pai(TLSEGCIC *l, int elem, int pai){
    TLSEGCIC *p = l;
    while((p) && (p->info != elem) && (p->info != pai)) p = p->prox;
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
void TLSEGCIC_imprime(TLSEGCIC *l) {
    TLSEGCIC * p = l;
    int cont = 0;

    while(p) {
        printf("%d -> %d, ", p->pai, p->info);
        cont = cont + 1;
        if (cont %3 == 0) printf("\n");
        p = p->prox;
    }
}
TLSE* menor_caminho(TG*g, int no1, int no2) {
    TG* pNo1 = TG_busca_no(g, no1);
    TG* pNo2 = TG_busca_no(g, no2);
    if (!pNo1 || !pNo2) return NULL;
    TLSEGCIC*visit = NULL, *nvisit = TLSEGCIC_insere(NULL, pNo1->id_no, INT_MAX), *processando = NULL;
    int qtdCaminhos = 0;
    int encontrou = 0;
    while (nvisit) {
        processando = nvisit;
        nvisit = NULL;
        while (processando) {
            TG* no = TG_busca_no(g, processando->info);
            int pai = processando->pai;
            TVIZ*v = no->prim_viz;
            while (v) {
                if (no2 == v->id_viz) {
                    visit = TLSEGCIC_insere(visit, no2, no->id_no);
                    qtdCaminhos++;
                    v = v->prox_viz;
                    encontrou = 1;
                    continue;
                }
                if (!TLSEGCIC_busca_pai(visit, v->id_viz, no->id_no)
                    && !TLSEGCIC_busca_pai(nvisit, v->id_viz, no->id_no)
                    && !TLSEGCIC_busca_pai(processando, v->id_viz, no->id_no)) {
                    nvisit = TLSEGCIC_insere(nvisit, v->id_viz, no->id_no);
                }
                v = v->prox_viz;
            }
            visit = TLSEGCIC_insere(visit, no->id_no, pai);
            processando = TLSEGCIC_retira(processando, no->id_no,pai);
        }
    }
    TLSEGCIC_imprime(visit);

    TLSEGCIC_libera(nvisit);
    TLSEGCIC_libera(processando);
    if (!encontrou) {
        TLSEGCIC_libera(visit);
        return NULL;
    }
    TLSEGCIC_imprime(visit);
    TLSE* l = TLSE_inicializa();
    int noAtual = no2;
    while (noAtual != INT_MAX) {
        l = TLSE_insere(l, noAtual);
        noAtual = TLSEGCIC_busca(visit, noAtual)->pai;
    }
    TLSEGCIC_libera(visit);
    return l;
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
    g = TG_ins_no(g, 55);
    g = TG_ins_no(g, 77);

    // Insere as arestas
    TG_ins_aresta(g, 10, 1);
    TG_ins_aresta(g, 1, 33);
    TG_ins_aresta(g, 33, 42);
    TG_ins_aresta(g, 42, 7);
    TG_ins_aresta(g, 7, 99);
    TG_ins_aresta(g, 99, 12);
    TG_ins_aresta(g, 12, 109);

    // Caminho mais curto alternativo
    TG_ins_aresta(g, 10, 99);
    TG_ins_aresta(g, 99, 109);

    // Caminho extra longo pra testar
    TG_ins_aresta(g, 10, 55);
    TG_ins_aresta(g, 55, 77);
    TG_ins_aresta(g, 77, 109);
    // TG_ins_aresta(g,  99,  42);
    // TG_ins_aresta(g,  12,  1);
    // TG_ins_aresta(g,  10,  109);


    TG_imprime(g);
    int no1 = 10;
    int no2 = 109;
    TLSE*l = menor_caminho(g, no1, no2);
    if (!l)
        printf("Nos %d e %d nao conectados.\n", no1, no2);
    else
        TLSE_imprime(l);
    TLSE_libera(l);
    TG_libera(g);
    return 0;
}