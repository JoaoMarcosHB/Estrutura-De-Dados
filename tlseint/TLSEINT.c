#include "TLSEINT.h"

TLSEINT* TLSEINT_inicializa(void){
  return NULL;
}

TLSEINT* TLSEINT_insere(TLSEINT *l, int inf, int sup){
  TLSEINT *novo = (TLSEINT *) malloc(sizeof(TLSEINT));
  novo->prox = l;
  novo->lim_inf = inf;
  novo->lim_sup = sup;
  return novo;
}

void TLSEINT_imprime(TLSEINT *l){
  TLSEINT *p = l;
  while(p){
    printf("[%d,%d] ", p->lim_inf, p->lim_sup);
    p = p->prox;
  } 
}

void TLSEINT_libera(TLSEINT *l){
  TLSEINT *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}


TLSEINT* TLSEINT_retira_rec(TLSEINT *l, int elem){
  if(!l) return l;
  if((l->lim_inf == elem)||(l->lim_sup == elem)){
    TLSEINT *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSEINT_retira_rec(l->prox, elem);
  return l;
}
