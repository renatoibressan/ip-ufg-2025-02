#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int numJogo;
    int numero[6];
} cartela;
 
int main() {
    int n, i, j, k, idx;
    int count = 0, sena = 0, quina = 0, quadra = 0;
    int jogo_sena, jogo_quina, jogo_quadra;
    int *v6 = NULL, *v5 = NULL, *v4 = NULL;
    cartela concurso;
    scanf("%d", &n);
    cartela *apostas = malloc(n*sizeof(cartela));
    for (i = 0; i < n; i++) {
        scanf("%d", &(apostas[i]).numJogo);
        for (j = 0; j < 6; j++) {
            scanf("%d", &(apostas[i]).numero[j]);
        }
    }
    scanf("%d", &(concurso).numJogo);
    for (i = 0; i < 6; i++) {
        scanf("%d", &(concurso).numero[i]);
    }
    v6 = (int *)malloc(6*sizeof(int));
    v5 = (int *)malloc(5*sizeof(int));
    v4 = (int *)malloc(4*sizeof(int));
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 6; k++) {
                if (apostas[i].numero[j] == concurso.numero[k]) {
                    count++;
                    break;
                }
            }
        }
        if (count == 6) {
            sena++;
            jogo_sena = apostas[i].numJogo;
            idx = 0;
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 6; k++) {
                    if (apostas[i].numero[j] == concurso.numero[k]) {
                        v6[idx++] = apostas[i].numero[j];
                    }
                }
            }
        }
        else if (count == 5) {
            quina++;
            jogo_quina = apostas[i].numJogo;
            idx = 0;
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 6; k++) {
                    if (apostas[i].numero[j] == concurso.numero[k]) {
                        v5[idx++] = apostas[i].numero[j];
                    }
                }
            }
        }
        else if (count == 4) {
            quadra++;
            jogo_quadra = apostas[i].numJogo;
            idx = 0;
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 6; k++) {
                    if (apostas[i].numero[j] == concurso.numero[k]) {
                        v4[idx++] = apostas[i].numero[j];
                    }
                }
            }
        }
    }
    if (sena > 0) {
        printf("SENA %d:", jogo_sena);
        for (i = 0; i < 6; i++) {
            printf(" %d", v6[i]);
        }
        printf("\n");
    }
    if (quina > 0) {
        printf("QUINA %d:", jogo_quina);
        for (i = 0; i < 5; i++) {
            printf(" %d", v5[i]);
        }
        printf("\n");
    }
    if (quadra > 0) {
        printf("QUADRA %d:", jogo_quadra);
        for (i = 0; i < 4; i++) {
            printf(" %d", v4[i]);
        }
        printf("\n");
    }
    if (sena == 0 && quina == 0 && quadra == 0) printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", concurso.numJogo);
    free(apostas);
    free(v6);
    free(v5);
    free(v4);
    return 0;
}