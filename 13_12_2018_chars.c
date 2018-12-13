// 
// Created by  Peter Yankievich on 13/12/2018.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int myStrstr(const char *str, const char *toFind){
    int i = 0, j;

    for(i = 0; str[i]; ++i){
        for(j = 0; toFind[j]; ++j){
            if(str[i+j] != toFind[j])
                break;
        }
        if(toFind[j] == '\0'){
            return i;
        }
    }
    return -1;
}

int myStrlen(const char *str) {
    int i = 0;
    while (str[i++] != '\0');
    return i - 1;
}

char *myStrdup(const char *src) {
    int len = myStrlen(src) +1;
    int i;
    char *ret;
    ret = malloc(len * sizeof(char));
    if(ret == NULL){
        return NULL;
    }
    for (i = 0; i < len; ++i) {
        ret[i] = src[i];
    }

    return  ret;
}

int main(void) {

//    char s1[] = "ala"; // 4 bajty, ala0s
//    char *s2 = "ala"; // it is a reference to const ! segmentation fault if trying to change this type
//    char s3[] = {97, 98, 97, 0}; // const
//    char *s4;
//
//    char string1[] = "ala ma kota";
//    char string2[] = "ala da kota";
//    s2[1] = 'a' ERROR
//    puts(s1);
//    puts(s2);
//    puts(s3);

//    s4 = malloc(4 * sizeof(char)); // heap
//    if(s4 == NULL){
//        return 1;
//    }
//
//    s4[0] = 'a';
//    s4[1] = 'l';
//    s4[2] = 'a';
//    s4[3] = '\0';
//
//    puts(s4);

//    printf("lenght of 'ala ma kota'  = %d", myStrlen(string1));


//    printf("cmp1 = %d, cmp12 = %d\n", strcmp(string1, string1), strcmp(string1, string2));
//    free(s4);

    char str1[] = "ala ma kota";
    char toFind[] = "ma";

    printf("%d\n", myStrstr(str1, toFind));



    return 0;
}