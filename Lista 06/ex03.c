#include <stdio.h>
#include <string.h>

char *paises[24] = { "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
			"inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
			"mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
			"marrocos", "japao" };

char *saudacoes[24] = { "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
			"Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
			"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
			"Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
			"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!" };

typedef struct traducao {
    char pais[50];
    char saud[100];
} tradutor;

tradutor trad[24];

int position;

void PreencheTrad();

int PesquisaPais(char *str);

int main() {
    PreencheTrad();
    char pais[100];
    while (scanf(" %s", pais) != EOF) {
        if (PesquisaPais(pais) == 1) printf("%s\n", trad[position].saud);
        else printf("-- NOT FOUND --\n");
    }
    return 0;
}

void PreencheTrad() {
    int i;
    for (i = 0; i < 24; i++) {
        strcpy(trad[i].pais, paises[i]);
        strcpy(trad[i].saud, saudacoes[i]);
    }
}

int PesquisaPais(char *str) {
    int i;
    for (i = 0; i < 24; i++) {
        if (strcmp(trad[i].pais, str) == 0) {
            position = i;
            return 1;
        }
    }
    return 0;
}