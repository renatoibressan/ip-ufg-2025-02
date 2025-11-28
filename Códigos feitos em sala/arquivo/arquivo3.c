#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq = NULL;
    int i = 0;
    arq = fopen("notas", "r");
    while (fscanf(arq, "%[^\n]") != EOF) i++;
    printf("%d\n", i);
    fclose(arq);
    return 0;
}