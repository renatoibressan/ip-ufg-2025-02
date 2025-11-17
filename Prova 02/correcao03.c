#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n, m, d, i, j, **t, soma = 0;
    double menor = 1000.0, maior = -1000.0;
    int mm1, mm2;
    double media;
    scanf("%d", &n);
    t = (int **)malloc(n*sizeof(int *));
    for (i = 0; i < n; i++) {
        soma = 0;
        scanf("%d %d", &m, &d);
        t[i] = (int *)malloc(d*sizeof(int));
        for (j = 0; j < d; j++) {
            scanf("%d", (*(t + i) + j));
            soma += t[i][j];
            if (t[i][j] > maior) {
                maior = t[i][j];
                mm1 = m;
            }
            if (t[i][j] < menor) {
                menor = t[i][j];
                mm2 = m;
            }
        }
        media = soma / (d * 1.0);
        printf("Mes %d: %.1lf\n", m, media);
        free(*t);
    }
    printf("Maxima: %.1lf(%d), Minima: %.1lf(%d)\n", maior, mm1, menor, mm2);
    free(t);
    return 0;
}
