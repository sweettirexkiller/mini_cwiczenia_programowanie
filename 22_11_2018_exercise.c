//
// Created by Peter Yankievich on 22/11/2018.
//

#include "stdio.h"

#define N 5

int areEqual(int tab1[N], int tab2[N]) {
    int i;

    for (i = 0; i < N; ++i) {
        if (tab1[i] != tab2[i]) {
            return 0;
        }
    }
    return 1;
}

char exists(int tab[N], int toFind){
    int i;
    for (i = 1; i < N; i++) {
        if (tab[i] == toFind) {
            return 1;
        }
    }
    return 0;
}

int sumMinMax(int tab[N]) {
    int max = tab[0], min = tab[0], i;
    for (i = 1; i < N; i++) {
        if (tab[i] < min) {
            min = tab[i];
        } else if (tab[i] > max) {
            max = tab[i];
        }
    }
    return min + max;
}

int main(void) {
//    if(n & 0x1) // is odd
//    int a = 5, b = 3;
//    int tmp;
//    tmp = a;
//    a = b;
//    b = tmp;

//    printf("%d %d %d\n", a, b, N);
//    puts("finished");
//    printf("%s\n", "finished");

    int tab1[N] = {1, 2, 3, 4, 5};
//    int tab2[N] = {1, 2, 3, 4, 5};
    int tab2[N] = {2, 4, 5, 6, 7};

    if (areEqual(tab1, tab2)) {
//        printf("%s\n", "Two arrays are equal.");
        puts("TAK");
    } else {
//        printf("%s\n", "Two arrays are not equal.");
        puts("NIE");
    }

    printf("Sum of min and max: %d", sumMinMax(tab1));

    return 0;
}