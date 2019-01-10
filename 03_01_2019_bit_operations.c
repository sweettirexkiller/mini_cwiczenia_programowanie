// 
// Created by  Peter Yankievich on 03/01/2019.
//
#include <stdio.h>
#include <stdlib.h>


void setIP(unsigned *ip, unsigned char n0, unsigned char n1, unsigned char n2, unsigned char n3) {
    *ip = (n0 << 24);
    *ip |= (n1 << 16);
    *ip |= (n2 << 8);
    *ip |= (n3);
}

void dumpIP(unsigned ip) {
    unsigned n0, n1, n2, n3;
    const unsigned mask = 255;
    n0 = (ip >> 24);
    n1 = (ip >> 16) & mask;
    n2 = (ip >> 8) & mask;
    n3 = ip & mask;

    printf("%d.%d.%d.%d\n", n0, n1, n2, n3);
}

void setBit(unsigned *n, int i) {
    *n |= (0x1 << i);
}

int getBit(unsigned n, int i) {
    return n & (0x1 << i);
}

int main(void) {
//    unsigned n = 0x0;

//    setBit(&n, 0);
//    setBit(&n, 1);
//    setBit(&n, 2);
//    setBit(&n, 4);
//
//    printf("Decimal:\n");
//    printf("n = %d\n", n);
//    printf("Binary:\n");
//    printf("%d %d %d %d %d\n", getBit(n, 4), getBit(n, 3), getBit(n, 2), getBit(n, 1), getBit(n, 0));

//    int x = 0x1, y = 0x2;
//    int z = x & y; // bit AND
//    int z = x | y; // bit AND
//    int z = x ^y; // bit AND
//
//    printf("z =  %d\n", z);
//
//    z <<= 2;
//
//    printf("z =  %d\n", z);
//
//    z = 60 >> 1;
//
//    printf("z =  %d\n", z);
//
//    printf("z =  %u\n", ~z);

//    unsigned ip;
//    setIP(&ip, 120, 100, 50, 40);
//    dumpIP(ip);
    int i;
    for (i = 0x10; i; i >>= 1) {
        puts("loop");
//        printf("%d\n", i);
    }
    return 0;
}



//    int x = 0x1, y = 0x2;
//    int z = x & y; // bit AND
//    int z = x | y; // bit AND
//    int z = x ^y; // bit AND
//
//    printf("z =  %d\n", z);
//
//    z <<= 2;
//
//    printf("z =  %d\n", z);
//
//    z = 60 >> 1;
//
//    printf("z =  %d\n", z);
//
//    printf("z =  %u\n", ~z);
//
//    if (z & 0x1) { // is odd
//
//    }