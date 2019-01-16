// 
// Created by  Peter Yankievich on 10/01/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NAME_SIZE 5

typedef struct Node Node;

struct Node {
    char *name;
    Node *next;
    Node *prev;
};

char *createName() {
    char *ret;
    int i;
    ret = malloc((NAME_SIZE + 1) * sizeof(char));
    if (ret == NULL) {
        return NULL;
    }

    for (i = 0; i < NAME_SIZE; i++) {
        ret[i] = 'a' + rand() % ('z' - 'a' + 1);
    }
    ret[NAME_SIZE] = '\0';

    return ret;
}

Node *prepend(Node **head, Node **tail) {
    Node *newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->prev = NULL;
    newNode->next = *head;
    newNode->name = createName();

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    if (*tail == NULL) {
        *tail = newNode;
    }
    return newNode;
}

void printH(const Node *head) {
    const Node *it = head;
    while (it) {
        printf("%s\n", it->name);
        it = it->next;
    }
}

void printT(const Node *tail) {
    const Node *it = tail;
    while (it) {
        printf("%s\n", it->name);
        it = it->prev;
    }
}

void destroy(Node *head) {
    Node *it = head;
    Node *next;
    while (it) {
        next = it->next;
        free(it->name);
        free(it);

        it = next;
    }
}

void removeNode(Node **head, Node **tail, Node *toDelete) {
    Node *it = toDelete;
    if (*head == NULL || *tail == NULL) {
        return;
    }
    if (it->prev == NULL) {
        *head = it->next;
    } else {
        it->prev->next = it->next;
    }

    if (it->next == NULL) {
        *tail = it->prev;
    } else {
        it->next->prev = it->prev;
    }

    free(it->name);
    free(it);
}

char *merge(const Node *head) {
    int totalLen = 0;
    char *ret;
    const Node *it = head;
    while (it) {
        totalLen += strlen(it->name);
        it = it->next;
    }

    ret = malloc((totalLen + 1) * sizeof(char));

    if(ret == NULL){
        return NULL;
    }

    it = head;
    ret[0] = '\0';
    while (it) {
        strcat(ret, it->name);
        it = it->next;
    }

    return ret;
}

int main() {
    Node *head = NULL, *tail = NULL;
    Node *node;
    srand(time(NULL));

    prepend(&head, &tail);
    prepend(&head, &tail);
    node = prepend(&head, &tail);
    prepend(&head, &tail);
    prepend(&head, &tail);
    prepend(&head, &tail);

    printH(head);

    removeNode(&head, &tail, node);
    putchar('\n');

    printH(head);

    char *merged = merge(head);

    printf("\n%s\n\n", merged);

    destroy(head);

    free(merged);

    return 0;
}