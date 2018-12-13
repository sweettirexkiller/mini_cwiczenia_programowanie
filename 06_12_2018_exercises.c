//
// Created by  Peter Yankievich on 06/12/2018.
//

#include <stdio.h>
#include <stdlib.h>

typedef Struct Array {
    int *tab;
    int n;
} Array ;

void fill(float *tab, int n) {
    int i;
    for (i = 0; i < n; i++) {
        tab[i] = i + 1;
    }

    return;
}

int main() {

    int n;
    float *tab;
    scanf("%d", &n);
    tab = malloc(n * sizeof(float));
    if (tab == NULL) return 1;
    fill(tab, n);

    int i;
    for (i = 0; i < n; i++) {
        printf("%.1f ", tab[i]);
    }
    putchar('\n');

    free(tab);
    return 0;
}