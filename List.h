#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
};

// Створення та маніпуляції списком
Node* createCircularList(int size);
void printList(Node* head);
void freeList(Node* head);

// Операції з списками
bool isSublist(Node* L1, Node* L2);

#endif