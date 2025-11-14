#include <stdio.h>
#define M 100
#define N 100

void troca_maior_e_menor(int m[M][N], int l1, int c1, int l2, int c2);

int main() {
    int nl, nc, i, j, m[M][N];
    int maiL, maiC, menL, menC;
    int menor = 1000, maior = 0;
    scanf("%d %d", &nl, &nc);
    for (i = 0; i < nl; i++) {
        for (j = 0; j < nc; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j] < menor) {
                menor = m[i][j];
                maiL = i;
                maiC = j;
            }
            if (m[i][j] > maior) {
                maior = m[i][j];
                menL = i;
                menC = j;
            }
        }
    }
    troca_maior_e_menor(m, maiL, maiC, menL, menC);
    for (i = 0; i < nl; i++) {
        for (j = 0; j < nc; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void troca_maior_e_menor(int m[M][N], int l1, int c1, int l2, int c2) {
    int swap;
    if ((l1 >= 0 && l1 < M) && (c1 >= 0 && c1 < N) && (l2 >= 0 && l2 < M) && (c2 >= 0 && c2 < N)) {
        swap = m[l1][c1];
        m[l1][c1] = m[l2][c2];
        m[l2][c2] = swap;
    }
}
