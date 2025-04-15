#include "list.h"
#include <iostream>

int main() {
    // Створення списків
    Node* L1 = createCircularList(3);  // Список 1->2->3->1...
    Node* L2 = createCircularList(5);  // Список 1->2->3->4->5->1...

    // Виведення списків
    std::cout << "List L1: ";
    printList(L1);
    std::cout << "List L2: ";
    printList(L2);

    // Перевірка чи L1 є підсписком L2
    if (isSublist(L1, L2)) {
        std::cout << "L1 is a sublist of L2" << std::endl;
    }
    else {
        std::cout << "L1 is NOT a sublist of L2" << std::endl;
    }

    // Звільнення пам'яті
    freeList(L1);
    freeList(L2);

    return 0;
}