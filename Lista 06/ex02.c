#include <stdio.h>
#include <string.h>
// Mercado
typedef struct fruta {
    char name[55];
    float price;
} fruit;

int position;

int ProcuraFruta(fruit *f, char *str, int n);

int main() {
    int idas, produtos, desejados, frutas, i;
    char fruta[55];
    float soma;
    scanf("%d", &idas);
    while (idas--) {
        scanf("%d", &produtos);
        fruit feira[produtos];
        for (i = 0; i < produtos; i++) {
            scanf(" %s %f", feira[i].name, &feira[i].price);
        }
        scanf("%d", &desejados);
        soma = 0.0;
        for (i = 0; i < desejados; i++) {
            scanf(" %s %d", fruta, &frutas);
            if (ProcuraFruta(feira, fruta, produtos) == 1) {
                soma += feira[position].price * frutas;
            }
        }
        printf("R$ %.2f\n", soma);
    }
    return 0;
}

int ProcuraFruta(fruit *f, char *str, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(f[i].name, str) == 0) {
            position = i;
            return 1;
        }
    }
    return 0;
}
