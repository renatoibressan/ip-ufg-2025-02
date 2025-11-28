#include <stdio.h>
#include <stdlib.h>
// Estiagem
typedef struct casa {
    int pessoas, consumo, media;
} Casa;

void ordena(Casa c[], int n);

void agrega(Casa c[], int n);

int main() {
    Casa casas[100];
    int n, i, cc = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &(casas[i].pessoas), &(casas[i].consumo));
            casas[i].media = casas[i].consumo / casas[i].pessoas;
        }
        ordena(casas, n);
        if (cc > 0) printf("\n");
        printf("Cidade# %d:\n", cc + 1);
        agrega(casas, n);
        cc++;
    }
    return 0;
}

void ordena(Casa c[], int n) {
    int i, j, im;
    Casa temp;
    for (i = 0; i < n - 1; i++) {
        im = i;
        for (j = i + 1; j < n; j++) {
            if (c[j].media < c[im].media) im = j;
        }
        temp = c[i];
        c[i] = c[im];
        c[im] = temp;
    }
}

void agrega(Casa c[], int n) {
    int cref = -1, sp = 0, i = 0, total = 0, npt = 0;
    while (i < n) {
        if (c[i].media != cref) {
            if (i > 0) printf("%d-%d ", sp, cref);
            sp = c[i].pessoas;
            cref = c[i].media;
        } else {
            sp += c[i].pessoas;
        }
        total += c[i].consumo;
        npt += c[i].pessoas;
        i++;
    }
    printf("%d-%d ", sp, cref);
    printf("\nConsumo medio: %.2lf m3.\n", ((double)total / npt));
}
