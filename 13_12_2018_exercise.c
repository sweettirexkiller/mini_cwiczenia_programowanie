// 
// Created by  Peter Yankievich on 13/12/2018.
//

#include <stdlib.h>
#include <stdio.h>

int *create(int n, int val) {
    int *ret;
    int i;
    ret = malloc(n * sizeof(int));
    if (ret == NULL) {
        return NULL;
    }
    for (i = 0; i < n; ++i) {
        ret[i] = val;
    }

    return ret;
}

int **create2D(int nRows, int nCols, int val) {
    int **ret;
    int i, j;
    ret = malloc(nRows * sizeof(int *));
    if (ret == NULL) {
        return NULL;
    }

    for (i = 0; i < nRows; ++i) {
        ret[i] = malloc(nCols * sizeof(int));
        if (ret[i] == NULL) {
            for (j = 0; j < i; ++j) {
                free(ret[j]);
            }
            free(ret);
            return NULL;
        }
    }

    for (i = 0; i < nRows; ++i) {
        for (j = 0; j < nCols; ++j) {
            ret[i][j] = val;
        }
    }

    return ret;
}

void free2D(int **tab, int nRows){
    int i;
    for(i=0; i<nRows; ++i){
        free(tab[i]);
    }
    free(tab);
    return;
}

int main() {

    int *tab;
    int **tab2D;
    int i, j;
    tab = create(5, 5);
    tab2D = create2D(5, 5, 2);

    for (i = 0; i < 5; ++i) {
        for(j = 0; j<5; ++j){
            printf("%d ", tab2D[i][j]);
        }
        putchar('\n');
    }

    free(tab);
    free2D(tab2D, 5);


    return 0;
}