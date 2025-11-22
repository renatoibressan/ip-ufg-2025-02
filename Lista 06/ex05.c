#include <stdio.h>
#include <string.h>
#define CURSOMAX 105
#define NOMEMAX 505

typedef struct curso {
    int code;
    float cred;
    char nomedocurso[CURSOMAX];
} Curso;

typedef struct aluno {
    char nome[NOMEMAX];
    int id;
    int qtdcred;
} Aluno;

int main() {
    int n, m, i, j, k;
    float credito[1000];
    float mensal[1000];
    char grad[1000][CURSOMAX];
    Curso c[30];
    Aluno a[1000];
    scanf("%d%*c", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%*c %f%*c %[^\n]%*c", &(c[i].code), &(c[i].cred), (c[i].nomedocurso));
    }
    scanf("%d%*c", &m);
    for (j = 0; j < m; j++) {
        scanf("%[^\n]%*c %d%*c %d%*c", (a[j].nome), &(a[j].id), &(a[j].qtdcred));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (c[i].code == a[j].id) {
                credito[j] = c[i].cred;
                mensal[j] = c[i].cred * a[j].qtdcred;
                strcpy(grad[j], c[i].nomedocurso);
            }
        }
    }
    for (k = 0; k < m; k++) {
        printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n", a[k].nome, grad[k], a[k].qtdcred, credito[k], mensal[k]);
    }
    return 0;
}