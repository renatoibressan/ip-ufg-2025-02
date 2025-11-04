#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, n;
    scanf("%d", &n);
    p = (int *) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    if (p == NULL) printf("Error\n");
    free(p);
    return 0;
}