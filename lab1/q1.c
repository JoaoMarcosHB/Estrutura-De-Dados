#include "../tab/tab.h"
#include <stdio.h>

int mAux(TAB*a, int nivel){
	if(!a) return 0;
	int i = 1;
	if(nivel%2==0){
		i = -1;
	}
	return mAux(a->esq, nivel+1) + mAux(a->dir, nivel+1) + a->info*i;
}

int misc1(TAB * a){
	return mAux(a, 0);
}

int main(){
	int vet[] = {4, 9, 8, 2, 1, 10, 14, 18};
    TAB* a = v2ab(vet, 8);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    int total = misc1(a);
    printf("Soma: %d\n", total);
    TAB_libera(a);
	return 0;
}