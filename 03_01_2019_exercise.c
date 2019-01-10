// 
// Created by  Peter Yankievich on 03/01/2019.
//
#include <stdlib.h>
#include <stdio.h>

int combine(int x, int y, int (*fun)(int, int));

int add(int x, int y);

int mult(int x, int y);

int reduce(int *tab, int size, int(*fun)(int, int));


int main() {
//    int res = combine(2, 4, &add);

    int tab[] = {1, 2, 3, 4};
    int res = reduce(tab, 4, mult);
    printf("res = %d\n", res);

    return 0;
}

int combine(int x, int y, int (*fun)(int, int)) {
    return fun(x, y);
}

int add(int x, int y) {
    return x + y;
}
int mult(int x, int y) {
    return x*y;
}

int reduce(int *tab, int size, int(*fun)(int, int)) {
    int i;
    int ret;
    if (size == 0) {
        return 0;
    }

    ret = tab[0];
    for (i = 1; i < size; ++i) {
        ret = fun(ret, tab[i]);
    }

    return ret;
}
