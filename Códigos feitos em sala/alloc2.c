#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m = NULL;
    m = (int**) malloc(3*sizeof(int));
    free(m);
    return 0;
}