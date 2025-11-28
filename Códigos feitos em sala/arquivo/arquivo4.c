#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *arq = NULL;
    char ch;
    arq = fopen("notas", "r");
    if (arq == NULL) {
        printf("Arquivo inexistente\n");
        return 0;
    }
    while (fscanf(arq, "%c", &ch) != EOF) printf("%c", ch);
    fclose(arq);
    return 0;
}