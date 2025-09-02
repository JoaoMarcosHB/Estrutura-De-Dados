#include "../tab/tab.h"
#include <stdio.h>

TAB* TAB_busca_impar(TAB*a) {
    if((!a) || (a->info % 2 == 1)) return a;
    TAB *resp = TAB_busca_impar(a->esq);
    if(resp) return resp;
    return TAB_busca_impar(a->dir);
}

TAB* TAB_retira_pares(TAB*a) {
    if (!a) return a;//Nó nulo

    if (a->info % 2 == 0) {// Encontrou nó com número par
        TAB *esq = TAB_busca_impar(a->esq); //Busca na subárvore esquerda por algum nó ímpar
        if (!esq) { // Se não achou um nó impar, podemos liberar a subárvore esquerda pois só tem pares ou nulos.
            TAB_libera(a->esq);
            a->esq = NULL;
            TAB* dir = TAB_busca_impar(a->dir); // Busca na subárvore direita por nó ímpar
            if (!dir) {// Se não achou nó ímpar nem na esquerda nem na direita, podemos liberar a árvore a.
                TAB_libera(a);
                a = NULL;
                return a;
            }
            //Achou nó ímpar na direita e troca os valores de a->info por dir->info
            int aux = dir->info;
            dir->info = a->info;
            a->info = aux;

        } else {
            //Achou nó ímpar na esquerda e troca os valores de a->info por esq->info.
            int aux = esq->info;
            esq->info = a->info;
            a->info = aux;
        }
    }
    //Chama recursivamente para as subárvores esquerda e direita.
    a->esq = TAB_retira_pares(a->esq);
    a->dir = TAB_retira_pares(a->dir);
    return a;
}

int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 18,16, 19, 30, 20, 25, 9};
    TAB* a = v2ab(vet, 14);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    a = TAB_retira_pares(a);
    TAB_imp_ident(a);
    TAB_libera(a);
    return 0;
}