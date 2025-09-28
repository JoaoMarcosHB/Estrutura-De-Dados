#include <stdio.h>
#include "../tg/TG.h"
int cont_vizinhos(TVIZ*v) {
    if (!v) return 0;
    return 1 + cont_vizinhos(v->prox_viz);
}
int testek(TG*g, int k) {
    if (!g) return 0;
    int n = cont_vizinhos(g->prim_viz);
    if (n!=k) return 0;
    if (!g->prox_no) return 1;
    return testek(g->prox_no, k);
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
    // Conectando 10 com 1 (Aresta 10-1)
    TG_ins_aresta(g, 10, 1);

    // Conectando 33 com 42 e 12 (Arestas 33-42, 33-12)
    TG_ins_aresta(g,  33,  42);
    TG_ins_aresta(g,  33,  12);

    // Conectando o nó 12 com o nó 7 (Aresta 12-7)
    TG_ins_aresta(g,  12,  7);

    // Conectando 7 com 99 e 109 (Arestas 7-99, 7-109)
    TG_ins_aresta(g,  7,  99);
    TG_ins_aresta(g,  7,  109);

    // Fechando o ciclo (Aresta 1-42)
    TG_ins_aresta(g,  1,  42);

    // Adicionando um laço entre 99 e 109 (Aresta 99-109)
    TG_ins_aresta(g,  99,  109);
    TG_ins_aresta(g,  99,  42);
    TG_ins_aresta(g,  12,  1);
    TG_ins_aresta(g,  10,  109);


    TG_imprime(g);
    int n = testek(g, 3);
    printf("Todos nos com grau 3: %d\n", n);
    TG_libera(g);
    return 0;
}