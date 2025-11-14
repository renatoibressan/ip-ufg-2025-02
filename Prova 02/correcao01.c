#include <stdio.h>
#include <stdlib.h>
#define N 100
 
int main() {
    int n, i, j, **m;
    double *media;
    double maior = -1.0, menor = 101.0;
    scanf("%d", &n);
    m = (int **)malloc(n*sizeof(int *));
    media = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(2*sizeof(int));
        for (j = 0; j < 2; j++) {
            scanf("%d", (*(m + i) + j));
        }
        media[i] = (m[i][0] + m[i][1]) / 2.0;
        if (media[i] > maior) maior = media[i];
        if (media[i] < menor) menor = media[i];
        printf("Aluno %d: %.1lf\n", i + 1, media[i]);
    }
    printf("Maior: %.1lf, Menor: %.1lf\n", maior, menor);
    free(m);
    free(media);
    return 0;
}