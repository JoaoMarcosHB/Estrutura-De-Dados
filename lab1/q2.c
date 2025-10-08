#include "../tab/tab.h"
#include <stdio.h>
#include <stdlib.h>
int maior_nivel(TAB*a, int nivel){
	if(!a) return nivel-1;
	int e = maior_nivel(a->esq, nivel+1);
	int d = maior_nivel(a->dir, nivel+1);
	if (e>d) return e;
	return d;
}

void preenche_vetores(TAB*a, int*v_soma, int*v_qtd, int nivel){
	if(!a) return;
	v_soma[nivel] = v_soma[nivel] + a->info;
	v_qtd[nivel] = v_qtd[nivel] + 1;
	preenche_vetores(a->esq, v_soma, v_qtd, nivel + 1);
	preenche_vetores(a->dir, v_soma, v_qtd, nivel + 1);
}

int*media(TAB*a, int*tam_vet){
	int nivel = maior_nivel(a, 0);
	if(nivel <= 0) return NULL;
	*tam_vet = nivel+1;
	int*v_soma = (int*)calloc(nivel,sizeof(int));
	int *v_qtd = (int*)calloc(nivel,sizeof(int));
	preenche_vetores(a, v_soma, v_qtd, 0);
	for(int i = 0; i <= nivel; i++)
		v_soma[i] = v_soma[i] / v_qtd[i];
	free(v_qtd);
	return v_soma;
}

int main(){
	int vet[] = {4, 9, 8, 2, 1, 10, 14, 18};
    TAB* a = v2ab(vet, 8);
    TAB_imp_ident(a);
    printf("=-=-==-=-=-==-=-=-=-=-=-=-==-=-=-=-=-=-=-=-==-===-=-=-=-=-==-=-=-=-=-=\n");
    int total = 0;
    int*v = media(a, &total);

    printf("Niveis: %d\n", total);
    for(int i = 0;i < total; i++){
    	printf("Nivel %d: %d\n", i, v[i]);
    }
    TAB_libera(a);
    free(v);
	return 0;
}