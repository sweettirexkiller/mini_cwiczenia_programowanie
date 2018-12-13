//
// Created by  Peter Yankievich on 06/12/2018.
//

#include <stdio.h>
#include <stdlib.h>

#define N 6

//typedef enum {
//    mon, tue, wed
//} Weekdays;

//void fun(){
//    int x; // in stack
//    int *tabPrt; // in stack pointing to heap
//    tabPrt = malloc(5 * sizeof(int)); // address in heap, if not enough memory available will return null
//
//    if(tabPrt == NULL){
//        return;
//    }
//
//    tabPrt[0] = 2;
//
//    free(tabPrt); // freeing the memory after function execution
//}
//
//void add(int *x, int y){
//    *x += y;
//}

int main() {
//
//    Weekdays day = mon;
//
//    printf("day = %d\n", day);
//
//    int x = 0;
//
//    add(&x, 3);
//
//    printf("x = %d", x);

    float *tab, *tmp;
    int i;
//    tab = malloc(6 * sizeof(float));
    tab = calloc(6, sizeof(float)); // initiates with zeros
    if (tab == NULL) {
        puts("fail");
        return 1;
    }

    for(i = 0; i < N; i++){
        tab[i]  = i;
    }
    for(i = 0; i < N; i++){
        printf("%1.2f ", tab[i]);
    }
    putchar('\n');

    // extending by 2
    tmp = realloc(tab, (N+2)* sizeof(float));
    if (tmp == NULL) {
        puts("fail");
        free(tab);
        return 1;
    }
    tab = tmp;

    free(tab);
    return 0;
}