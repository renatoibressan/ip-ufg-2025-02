#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double u, x, y, z;
} ponto;

typedef struct diferenca {
    double du, dx, dy, dz;
} diff;

int main() {
    ponto *p;
    diff *d;
    int n, i;
    double *soma, *distance;
    scanf("%d", &n);
    p = (ponto *)malloc(n*sizeof(ponto));
    for (i = 0; i < n; i++) {
        scanf("%lf%*c %lf%*c %lf%*c %lf%*c", &(p[i].u), &(p[i].x), &(p[i].y), &(p[i].z));
    }
    d = (diff *)malloc((n-1)*sizeof(diff));
    soma = (double *)malloc((n-1)*sizeof(double));
    distance = (double *)malloc((n-1)*sizeof(double));
    for (i = 0; i < n - 1; i++) {
        d[i].du = p[i].u - p[i + 1].u;
        d[i].dx = p[i].x - p[i + 1].x;
        d[i].dy = p[i].y - p[i + 1].y;
        d[i].dz = p[i].z - p[i + 1].z;
        soma[i] = (d[i].du * d[i].du) + (d[i].dx * d[i].dx) + (d[i].dy * d[i].dy) + (d[i].dz * d[i].dz);
        distance[i] = sqrt(soma[i]);
        printf("%.2lf\n", distance[i]);
    }
    free(p);
    free(d);
    free(soma);
    free(distance);
    return 0;
}