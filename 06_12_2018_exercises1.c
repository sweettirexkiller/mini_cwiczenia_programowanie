//
// Created by  Peter Yankievich on 06/12/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array {
    int *tab;
    int n;
} Array;

int main() {
    int totalSize, n, i, j;
    Array *arrayList;
    srand((unsigned) time(NULL));
    scanf("%d %d", &totalSize, &n);

    arrayList = malloc(totalSize * sizeof(Array));
    if (arrayList == NULL) return 1;

    for (i = 0; i < totalSize; i++) {
        arrayList[i].tab = malloc(n * sizeof(int));
        if (arrayList[i].tab == NULL) {
            int k;
            for (k = i; k >= 0; k--) {
                free(arrayList[k].tab);
            }
            free(arrayList);

            return 1;
        }
        for (j = 0; j < n; j++) {
            arrayList[i].tab[j] = rand() % 50;
        }
    }

    for (i = 0; i < totalSize; i++) {
        printf("Array %d:\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arrayList[i].tab[j]);
        }
        putchar('\n');
    }


    for (i = 0; i < totalSize; i++) {
        free(arrayList[i].tab);
    }
    free(arrayList);
    return 0;
}