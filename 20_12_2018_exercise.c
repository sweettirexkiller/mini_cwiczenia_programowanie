// 
// Created by  Peter Yankievich on 20/12/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int size;
    int *tab;
} Vector;

void init(Vector *vector);

void add(Vector *vector, int n);

int size(Vector *vector);

void freeVector(Vector *vector);

void print(Vector *vector);

char **parse(const char *str, int *size);


int main(void) {
    int x;
    Vector vector;
    init(&vector);

    while (1) {
        scanf("%d", &x);

        if (x == -1) {
            break;
        }
        add(&vector, x);
    }

    print(&vector);

    freeVector(&vector);

//    int i;
//    char *str = "ala,ma,kota,a,jarek,ma,psa";
//    char **tab;
//    int size;
//    tab = parse(str, &size);
//
//    for (i = 0; i < size; ++i) {
//        printf("%s\n", tab[i]);
//    }

    return 0;
}

char **parse(const char *str, int *size) {
    int i, count = 0;
    int iC, iRow, start, currentSize;
    char **ret;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') { count++; }
    }
    count++;
    ret = (char **) malloc(sizeof(char *) * count);
    if (ret == NULL) return NULL;

    iC = 0;
    start = 0;
    for (iRow = 0; iRow < count; iRow++) {
        for (iC = start; str[iC] != ','; ++iC);

        currentSize = iC - start + 1;
        ret[iRow] = malloc(currentSize * sizeof(char));
        if (ret[iRow] == NULL) {
            // free for 0 to iRow
        }

        strncpy(ret[iRow], str + start, currentSize);
        ret[iRow] = '\0';
    }

}


void init(Vector *vector) {
    vector->size = 0;
    vector->tab = NULL;
}


void add(Vector *vector, int n) {
    int *tmp;
    vector->size++;
    tmp = realloc(vector->tab, sizeof(int) * size(vector));
    if (tmp == NULL) {
        free(vector->tab);
        vector->size = 0;
        return;
    }
    tmp[size(vector) - 1] = n;
    vector->tab = tmp;
}

int size(Vector *vector) {
    return vector->size;
}

void print(Vector *vector) {
    int i;
    for (i = 0; i < size(vector); i++)
        printf("%d ", vector->tab[i]);
    putchar('\n');
}

void freeVector(Vector *vector) {
    free(vector->tab);
}