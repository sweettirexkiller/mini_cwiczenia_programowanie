#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4
#define MAX 25

void sort(int tab[N]);

void fill(int tab[N][N], int x, int y);

void print(int tab[N][N], int x, int y);

int equal(int tab1[N][N], int tab2[N][N], int x, int y);

char isToeplitz(int tab[N][N]);

void identityMatrix(int tab[N][N]);

void printMinMax(int tab[N][N]);

void countSort(int tab[N][N]);

int main() {
//    int min, max;
//    int i;
//    int tab[N];
//
    srand((unsigned) time(NULL));
//    scanf("%d %d", &min, &max);
//
//    for (i = 0; i < N; i++) {
//        tab[i] = min + rand() % (max - min + 1);
//    }
//
//    sort(tab);
//
//    for (i = 0; i < N; i++) {
//        printf("%d ", tab[i]);
//    }

//    int tab1[N][N], tab2[N][N];
//    int x, y;
//    puts("Enter size: ");
//    scanf("%d %d", &x, &y);
//
//    fill(tab1, x, y);
//    fill(tab2, x, y);

//    print(tab1, x, y);
//    print(tab2, x, y);
//    printf("equal = %d", equal(tab1, tab2, x, y));

    int toeplitz[N][N] = {{1, 2, 3, 4},
                          {2, 1, 2, 3},
                          {3, 2, 1, 2},
                          {4, 3, 2, 1}}; // 4x4 toeplitz
    print(toeplitz, 4, 4);
    printMinMax(toeplitz);
    printf("is toeplitz=%d", isToeplitz(toeplitz));

    puts("changing to identity...");

    identityMatrix(toeplitz);

    print(toeplitz, 4, 4);

    return 0;
}

//home : insertion sort
void sort(int tab[N]) {
    puts("selection sorting....");
    int i, j, iMin, swapHelp;
    for (i = 0; i < N - 1; i++) {
        iMin = i;
        for (j = i + 1; j < N; j++) {
            if (tab[j] < tab[iMin]) iMin = j;
        }
        swapHelp = tab[i];
        tab[i] = tab[iMin];
        tab[iMin] = swapHelp;
    }
}

void fill(int tab[N][N], int x, int y) {
    int iX, iY;
    for (iY = 0; iY < y; ++iY) {
        for (iX = 0; iX < x; ++iX) {
            tab[iX][iY] = rand() % (MAX + 1);
        }
    }
}

void print(int tab[N][N], int x, int y) {
    int iX, iY;
    for (iY = 0; iY < y; ++iY) {
        for (iX = 0; iX < x; ++iX) {
            printf("%d ", tab[iX][iY]);
        }
        printf("\n");
    }
    printf("\n");
}

int equal(int tab1[N][N], int tab2[N][N], int x, int y) {
    int iX, iY;
    for (iY = 0; iY < y; ++iY) {
        for (iX = 0; iX < x; ++iX) {
            if (tab1[iX][iY] != tab2[iX][iY]) {
                return 0;
            }
        }
    }
    return 1;
}

char isToeplitz(int tab[N][N]) {
    int iX, iY;
    for (iX = 0; iX < N - 1; ++iX) {
        for (iY = 0; iY < N - 1; ++iY) {
            if (tab[iX][iY] != tab[iX + 1][iY + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

void identityMatrix(int tab[N][N]) {
    int iX, iY;
    for (iX = 0; iX < N; ++iX) {
        for (iY = 0; iY < N; ++iY) {
            if (iX == iY) {
                tab[iX][iY] = 1;
                continue;
            }
            tab[iX][iY] = 0;
        }
    }
}

void printMinMax(int tab[N][N]) {
    int min, max;
    int iX, iY;
    for (iX = 0; iX < N; ++iX) {
        for (iY = 0; iY < N; ++iY) {
            if (tab[iX][iY] > max) {
                max = tab[iX][iY];
            } else if (tab[iX][iY] < min) {
                min = tab[iX][iY];
            }
        }
    }
    printf("min: %d, max: %d\n", min, max);
}

void countSort(int tab[N][N]) {
    int iX, iY, i, j;
    int counter[MAX + 1];

    for (iX = 0; iX < N; ++iX) {

        //zerujemy
        for (i = 0; i < MAX + 1; i++) {
            counter[i] = 0;
        }
        //zliczamy
        for (iY = 0; iY < N; ++iY) {
            counter[tab[iX][iY]] += 1;
        }

        //wypisujemy
        for (i = 0; i < MAX; i++) {
            iY = 0;
            while (counter[i] > 0) {
                tab[iX][iY] = i;

                iY +=1;
                counter[i] -=1;
            }
        }
    }
}







