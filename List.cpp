#include "list.h"
#include <iostream>

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* createCircularList(int size) {
    if (size <= 0) return nullptr;

    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= size; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    current->next = head; // Замикаємо кільце
    return head;
}

void printList(Node* head) {
    if (!head) return;

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

void freeList(Node* head) {
    if (!head) return;

    Node* current = head;
    Node* temp;

    do {
        temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
}

bool isSublist(Node* L1, Node* L2) {
    if (!L1) return true; // Порожній список є підсписком будь-якого списку

    Node* startL1 = L1;
    Node* startL2 = L2;
    Node* currentL2 = L2;

    do {
        Node* tempL1 = L1;
        Node* tempL2 = currentL2;
        bool match = true;

        do {
            if (tempL1->data != tempL2->data) {
                match = false;
                break;
            }
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        } while (tempL1 != startL1 && tempL2 != startL2);

        if (match && tempL1 == startL1) return true;

        currentL2 = currentL2->next;
    } while (currentL2 != startL2);

    return false;
}