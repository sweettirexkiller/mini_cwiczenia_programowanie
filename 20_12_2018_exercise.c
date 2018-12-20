// 
// Created by  Peter Yankievich on 20/12/2018.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size;
    int *tab;
} Vector;

void init(Vector *vector);

void add(Vector *vector, int n);

int size(Vector *vector);

void freeVector(Vector *vector);

void print(Vector *vector);

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
    return 0;
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

void freeVector(Vector *vector){
    free(vector->tab);
}