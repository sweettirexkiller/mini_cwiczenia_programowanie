// 
// Created by  Peter Yankievich on 03/01/2019.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct Node Node;

struct Node {
    int val;
    Node *next;
};

//prepend

Node *append(Node *head, int newVal) { // add at the end
    Node *newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->val = newVal;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }

    Node *it = head;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = newNode;

    return head;
}

void printList(const Node *head) {
    const Node *it;
    it = head;
    while (it) {
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
}

void freeList(Node *head) {
    Node *it, *prev;
    it = head;
    while (it != NULL) {
        prev = it;
        it = it->next;
        free(prev);
    }
}

void removeEverySecondNode(Node *head) {
    Node *it, *prev;
    if (head == NULL) {
        return;
    }
    prev = head;
    it = prev->next;
    while (it != NULL) {
        prev->next = it->next;
        free(it);
        prev = prev->next;
        if(prev == NULL){
            break;
        }
        it = prev->next;
    }
}

int main(void) {
    Node *head = NULL;
    int i;

    for (i = 0; i < MAX; i++) {
        head = append(head, i);
    }

    removeEverySecondNode(head);
    printList(head);
    freeList(head);

    return 0;
}