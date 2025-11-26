#include <stdio.h>
#include <stdlib.h>

typedef struct FUNCIONARIO {
    int matricula, idade, num_filhos;
    char sexo;
    double salario;
} funcionario;

void media_idade(int soma, int n, double *media);

void media_filhos(int soma, int n, double *media);

double renda_por_pessoa(double salario, int qtd);

int main() {
    funcionario *f;
    int n, i;
    int soma_idade = 0, soma_filhos = 0, *qtd_pessoas;
    int qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0;
    double mediaI, mediaF, *rendaPC;
    scanf("%d", &n);
    f = malloc(n*sizeof(funcionario));
    qtd_pessoas = (int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %c %lf", &(f[i].matricula), &(f[i].idade), &(f[i].num_filhos), &(f[i].sexo), &(f[i].salario));
        soma_idade += f[i].idade;
        soma_filhos += f[i].num_filhos;
        qtd_pessoas[i] = f[i].num_filhos + 1;
    }
    media_idade(soma_idade, n, &mediaI);
    media_filhos(soma_filhos, n, &mediaF);
    rendaPC = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++) {
        rendaPC[i] = renda_por_pessoa(f[i].salario, qtd_pessoas[i]);
        if (f[i].idade > mediaI && f[i].salario > 3600.00) qtd1++;
        if (f[i].sexo == 'F' && f[i].num_filhos > mediaF) qtd2++;
        if (f[i].sexo == 'M' && f[i].num_filhos > mediaF) qtd3++;
        if (f[i].idade > 47 && rendaPC[i] < 2400.00) qtd4++;
    }
    printf("%d %d %d %d\n", qtd1, qtd2, qtd3, qtd4);
    return 0;
}

void media_idade(int soma, int n, double *media) {
    *media = (double)soma / n;
}

void media_filhos(int soma, int n, double *media) {
    *media = (double)soma / n;
}

double renda_por_pessoa(double salario, int qtd) {
    return salario / (double)qtd;
}