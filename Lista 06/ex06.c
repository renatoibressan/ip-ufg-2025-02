#include <stdio.h>
#define N 205
// Ordenação por Data
typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct pessoa {
    int matric;
    Data niver;
    char nome[N];
} Pessoa;

int CalculaIdade(Data d);

int ComparaDataNasc(Data d1, Data d2);

void OrdenaPessoas(Pessoa *p1, Pessoa *p2, Pessoa *temp);

int main() {
    int n, i, j;
    Pessoa p[30];
    Pessoa temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%*c %d%*c %d%*c %d%*c %[^\n]%*c", &(p[i].matric), &(p[i].niver.dia), &(p[i].niver.mes), &(p[i].niver.ano), (p[i].nome));
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ComparaDataNasc(p[i].niver, p[j].niver) == 0) {
                OrdenaPessoas(&p[i], &p[j], &temp);
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", p[i].matric, p[i].nome, p[i].niver.dia, p[i].niver.mes, p[i].niver.ano);
    }
    return 0;
}

int CalculaIdade(Data d) {
    int anoAtual = 2025, mesAtual = 12, diaAtual = 5;
    int calculo = ((anoAtual * 365) + (mesAtual * 30) + diaAtual) - ((365 * d.ano) + (30 * d.mes) + d.dia);
    return calculo;
}

int ComparaDataNasc(Data d1, Data d2) {
    int n1 = CalculaIdade(d1);
    int n2 = CalculaIdade(d2);
    if (n1 <= n2) return 1;
    else return 0;
}

void OrdenaPessoas(Pessoa *p1, Pessoa *p2, Pessoa *temp) {
    *temp = *p1;
    *p1 = *p2;
    *p2 = *temp;
}
