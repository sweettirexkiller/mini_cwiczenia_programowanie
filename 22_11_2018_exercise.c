//
// Created by Peter Yankievich on 22/11/2018.
//

#include "stdio.h"
#define N 10

int main(void) {
//    if(n & 0x1) // is odd
    int a = 5, b = 3;
    int tmp;
    tmp = a;
    a = b;
    b = tmp;

    printf("%d %d %d\n", a, b, N);
    puts("finished");
//    printf("%s\n", "finished");

    return 0;
}