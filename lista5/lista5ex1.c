#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ret_repeticao(char* ArqEntrada, char* ArqSaida) {
    FILE* fp = fopen(ArqEntrada, "rt");
    FILE* fs = fopen(ArqSaida, "wt");
    if ((!fp) || (!fs)) {
        exit(1);
    }
    char prevstr[51];
    prevstr[0] = '\0';
    char newstr[51];
    int r;
    r = fscanf(fp, " %s ", newstr);
    while (r == 1) {
        if (strcmp(newstr, prevstr) != 0) {
            fprintf(fs, "%s ", newstr);
            strcpy(prevstr, newstr);
        }
        r = fscanf(fp, " %s ", newstr);
    }
    fclose(fp);
    fclose(fs);
}

int main() {
    ret_repeticao("entrada.txt", "saida.txt");
    return 0;
}