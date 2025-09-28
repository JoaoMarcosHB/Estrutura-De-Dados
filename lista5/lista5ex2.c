#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_registros(char *arq) {
    FILE *fp = fopen(arq, "r");
    if (!fp) exit(1);
    char line[100];
    int contador = 0;
    while (fgets(line, sizeof(line), fp)) {
        contador++;
    }
    fclose(fp);
    return contador;
}

void media(char* ArqEntrada, char* ArqSaida) {
    int cont = conta_registros(ArqEntrada);
    FILE* fp = fopen(ArqEntrada, "rt");
    FILE* fs = fopen(ArqSaida, "wt");
    if (fp == NULL || fs == NULL) {
        exit(1);
    }
    char line[100];
    int contador = 0;
    char nomes[cont][10];
    float media[cont];
    while (fgets(line, sizeof(line), fp)) {
        int i = 0;
        int j = 0;
        int ind = 0;
        char c;
        do {
            c = line[ind++];
            nomes[contador][i++] = c;
        }while ((c != '/')&&(c!= '\0'));
        nomes[contador][i] = '\0';
        char n[5];
        do {
            c = line[ind++];
            if (c != '/')
                n[j++] = c;
        } while ((c != '/') && (c!='\0'));
        n[j] = '\0';
        float v = strtof(n, NULL);
        j = 0;
        do {
            c = line[ind++];
            n[j++] = c;
        } while ((c != '/') && (c!='\0'));
        n[j] = '\0';
        v += strtof(n, NULL);
        j = 0;
        media[contador] = v/2;
        contador++;
    }

    for (int i = 0; i < cont; i++) {
        int menor = i;
        for (int j = i+1; j < cont; j++) {
            if (media[menor] > media[j]) {
                menor = j;
            }
        }
        if (menor != i) {
            char aux[10];
            strcpy(aux, nomes[i]);
            strcpy(nomes[i],nomes[menor]);
            strcpy(nomes[menor], aux);
            float p = media[i];
            media[i] = media[menor];
            media[menor] = p;
        }

    }
    printf("Ordenado:\n");
    for (int i = 0; i < cont; i++) {
        printf("%s ", nomes[i]);
        printf("%.1f\n", media[i]);
        fprintf(fs,"%s ", nomes[i]);
        fprintf(fs,"%.1f\n", media[i]);
    }


    fclose(fp);
    fclose(fs);
}

int main() {
    media("ex2.txt", "ex2saida.txt");
    return 0;
}