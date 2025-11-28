#include <stdio.h>
#include <math.h>
// Raízes de equações quadradas
typedef struct Complex {
    float real, imaginario;
} complex;

typedef struct RaizEqu2 {
    complex x1;
    complex x2;
} raizes;

raizes calcula_raiz_equ_2(float a, float b, float c);

void complex_print(complex c);

int main() {
    float a, b, c;
    raizes r;
    scanf("%f %f %f", &a, &b, &c);
    r = calcula_raiz_equ_2(a, b, c);
    printf("x1 = ");
    complex_print(r.x1);
    printf("x2 = ");
    complex_print(r.x2);
    return 0;
}

raizes calcula_raiz_equ_2(float a, float b, float c) {
    raizes r;
    float d = (b * b) - (4 * a * c);
    if (d >= 0) {
        r.x1.real = (-b + sqrt(d)) / (2 * a);
        r.x1.imaginario = 0;
        r.x2.real = (-b - sqrt(d)) / (2 * a);
        r.x2.imaginario = 0;
    } else {
        r.x1.real = -b / (2 * a);
        r.x1.imaginario = sqrt(-d) / (2 * a);
        r.x2.real = -b / (2 * a);
        r.x2.imaginario = -sqrt(-d) / (2 * a);
    }
    return r;
}

void complex_print(complex c) {
    if (c.real == 0 && c.imaginario == 0) printf("0.00\n");
    else {
        if (c.real != 0) printf("%.2f", c.real);
        if (c.imaginario != 0) {
            if (c.imaginario == 1 && c.real == 0) printf("i");
            else if (c.imaginario == 1 && c.real != 0) printf("+i");
            else if (c.imaginario == -1) printf("-i");
            else {
                if (c.imaginario > 0 && c.real != 0) printf("+%.2fi", c.imaginario);
                else printf("%.2fi", c.imaginario);
            }
        }
        printf("\n");
    }
}
