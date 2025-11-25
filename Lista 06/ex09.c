#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdc(int a, int b);

void simplify(int *n, int *d);

int main() {
    int n, i, j, k, m;
    int n1, n2, d1, d2;
    int equivalente = 0;
    char l[1000];
    scanf("%d%*c", &n);
    for (i = 1; i <= n; i++) {
        fgets(l, sizeof(l), stdin);
        m = 0;
        for (j = 0; l[j] != '\0'; j++) {
            if (l[j] == ' ') m++;
        }
        m++;
        char **frac = (char **)malloc(m*sizeof(char *));
        char *tok = strtok(l, " ");
        for (j = 0; j < m && tok != NULL; j++) {
            frac[j] = (char *)malloc((strlen(tok)+1)*sizeof(char));
            strcpy(frac[j], tok);
            tok = strtok(NULL, " ");
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