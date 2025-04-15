#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
};

// ��������� �� ���������� �������
Node* createCircularList(int size);
void printList(Node* head);
void freeList(Node* head);

// �������� � ��������
bool isSublist(Node* L1, Node* L2);

#endif