#include "tab.h"
#include <stdio.h>
int main(void) {
    int vet[] = {4, 9, 8, 2, 1, 10, 14, 15,16, 19, 30, 20, 25, 9};
    TAB* a = v2ab(vet, 14);
    TAB_imp_pre(a);
    TAB_libera(a);
    printf("hello da main\n");
    return 0;
}