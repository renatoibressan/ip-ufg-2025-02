#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
    double u, x, y, z;
    double soma, norma;
} point;

int main() {
    point *p, temp;
    int n, i, j;
    scanf("%d", &n);
    p = (point *)malloc(n*sizeof(point));
    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &(p[i].u), &(p[i].x), &(p[i].y), &(p[i].z));
        p[i].soma = (p[i].u * p[i].u) + (p[i].x * p[i].x) + (p[i].y * p[i].y) + (p[i].z * p[i].z);
        p[i].norma = sqrt(p[i].soma);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].norma > p[j].norma) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", p[i].u, p[i].x, p[i].y, p[i].z, p[i].norma);
    }
    free(p);
    return 0;
}