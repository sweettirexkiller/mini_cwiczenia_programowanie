// 
// Created by  Peter Yankievich on 06/12/2018.
//
#include <stdlib.h>
#include <stdio.h>

#define N 5

typedef struct Student {
    int age;
    float markAvg;
} Student;

void addAge(Student *studentPtr) {
    (*studentPtr).age += 10;
    studentPtr->age += 10; // syntactic sugar
}

int main(void) {
    Student s1;
    Student *students;
    int i;

    s1.age = 20;
    s1.markAvg = 5.0f;
    printf("age = %d\n", s1.age);

    students = malloc(N * sizeof(Student));

    if (students == NULL) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        students[i].age = 10;
    }

    addAge(&students[1]);
    printf("age = %d\n", students[1].age);

    addAge(students + 1);
    printf("age = %d\n", students[1].age);


    free(students);
    return 0;
}