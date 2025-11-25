#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdc(int a, int b);

void simplify(int *n, int *d);

int main() {
    int n, m, i, j, k;
    int n1, n2, d1, d2;
    int equivalente = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &m);
        char **frac = (char **)malloc(m*sizeof(char *));
        for (j = 0; j < m; j++) {
            frac[j] = (char *)malloc(20*sizeof(char));
            scanf("%s", frac[j]);
        }
        printf("Caso de teste %d\n", i);
        equivalente = 0;
        for (j = 0; j < m - 1; j++) {
            for (k = j + 1; k < m; k++) {
                sscanf(frac[j], "%d/%d", &n1, &d1);
                sscanf(frac[k], "%d/%d", &n2, &d2);
                simplify(&n1, &d1);
                simplify(&n2, &d2);
                if (n1 == n2 && d1 == d2) {
                    printf("%s equivalente a %s\n", frac[j], frac[k]);
                    equivalente = 1;
                }
            }
        }
        if (equivalente != 1) printf("Nao ha fracoes equivalentes na sequencia\n");
        for (j = 0; j < m; j++) {
            free(frac[j]);
        }
        free(frac);
    }
    return 0;
}

int mdc(int a, int b) {
    int aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void simplify(int *n, int *d) {
    int div = mdc(*n, *d);
    *n /= div;
    *d /= div;
}