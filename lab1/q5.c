#include "../tab/tab.h"
#include <stdio.h>

void aux(TAB*a, int nivel, int N, int M, int *MaiorNivel, TAB**ret){
	if(!a) return;
	if(((a->esq) && ((a->esq->info == N)||(a->esq->info == M))) && ((a->dir) && ((a->dir->info == M)||(a->dir->info == N)))){
		if(nivel >= (*MaiorNivel)){
			(*ret) = a;
			(*MaiorNivel) = nivel;
		}
	}
	aux(a->esq, nivel+1, N, M, MaiorNivel, ret);
	aux(a->dir, nivel+1, N, M, MaiorNivel, ret);
}

TAB* maior_nivel(TAB*a, int N, int M){
	TAB* ret = NULL;
	int maior_nivel = 0;
	aux(a, 0, N, M, &maior_nivel, &ret);
	return ret;
}

int main(){
	int vet[] = {4, 8, 8, 13, 1, 10, 14, 18};
    TAB* a = v2ab(vet, 8);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    TAB* r = maior_nivel(a, 8, 14);
    if(r){
    	TAB_imp_ident(r);
    }
    TAB_libera(a);
	return 0;
}