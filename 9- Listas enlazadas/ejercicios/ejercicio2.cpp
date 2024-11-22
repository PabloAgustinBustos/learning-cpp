#include <iostream>
//#include <conio.h>

struct Node {
    int value = 0;
    Node *next = NULL;
};

void logNode(Node *node) {
    if (!node) {
        std::cout << "NULL" << std::endl;
        return;
    }

    std::cout << node << " {" << std::endl;
    std::cout << " value: " << node->value << std::endl;
    std::cout << " next: " << node->next << std::endl;
    std::cout << "}" << std::endl;
}

void printListValues(Node *head) {
    if (!head) {
        std::cout << "Lista vacia" << std::endl;
        return;
    }

    Node *current = head;

    do {
        std::cout << current->value;

        if (current->next) std::cout << ", ";
        else std::cout << "\n";

        current = current->next;
    } while (current);
}

void addLast(Node *&head, int newNumber) {
    if (!head) {
        head = new Node();
        head->value = newNumber;

        return;
    }

    Node *last = head;

    while (last->next) {
        last = last->next;
    }

    last->next = new Node();
    last = last->next;
    last->value = newNumber;
}
void addFirst(Node *&head, int newNumber) {
    Node *aux = head;

    head = new Node();
    head->value = newNumber;
    head->next = aux;
}
void addAfterNode(Node *node, int newNumber) {
    if (!node) return;

    Node *newNode = new Node();
    Node *aux = node->next;

    newNode->value = newNumber;
    newNode->next = aux;

    node->next = newNode;
}
Node* getNode(Node* head, int number) {
    Node* current = head;

    while (current && current->value != number) {
        current = current->next;
    }

    return current;
}

bool mergeList(Node* list1, Node* list2, Node* &list3) {
    if (!list1 || !list2) return false;

    Node* current = list1;

    do {
        addLast(list3, current->value);

        current = current->next;
    } while (current);

    current = list2;

    do {
        addLast(list3, current->value);

        current = current->next;
    } while (current);

    return true;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* list3 = NULL;

    addLast(list1, 1);
    addLast(list1, 2);
    addLast(list1, 3);
    addLast(list1, 4);
    addLast(list1, 5);

    addLast(list2, 6);
    addLast(list2, 7);
    addLast(list2, 8);
    addLast(list2, 9);
    addLast(list2, 10);

    bool isMerged = mergeList(list1, list2, list3);

    printListValues(list1);
    printListValues(list2);

    if (isMerged) printListValues(list3);
    else std::cout << "No se pudo mergear" << std::endl;

    return 0;
}

