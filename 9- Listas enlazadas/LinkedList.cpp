#include <iostream>

using namespace std;

struct Node {
    int value = NULL;
    Node *next = NULL;
};

void logNode(Node *node) {
    if (!node) {
        cout << "NULL" << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << " value: " << node->value << endl;
    cout << " next: " << node->next << endl;
    cout << "}" << endl;
}
void printList(Node *head) {
    if (!head) {
        cout << "NULL" << endl;
        return;
    }

    Node *current = head;

    do {
        logNode(current);

        current = current->next;
    } while (current);
}
void printListValues(Node *head) {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }

    Node *current = head;

    do {
        cout << current->value;

        if (current->next) cout << ", ";
        else cout << "\n";

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
void addAfter(Node *head, int nodeNumber, int newNumber) {
    if (!head) return;

    Node *current = head;

    while (current->next && current->value != nodeNumber) {
        current = current->next;
    }

    if (!current) return;

    Node *newNode = new Node();
    Node *aux = current->next;

    newNode->value = newNumber;
    newNode->next = aux;

    current->next = newNode;
}
void addAfterNode(Node *node, int newNumber) {
    if (!node) return;

    Node *newNode = new Node();
    Node *aux = node->next;

    newNode->value = newNumber;
    newNode->next = aux;

    node->next = newNode;
}

void deleteFirst(Node *&head) {
    if(!head) return;

    Node *aux = head;
    head = head->next;

    delete aux;
    aux = NULL;
}
void deleteLast(Node *&head) {
    if (!head) return;

    Node *last = head;
    Node *beforeLast;

    while (last->next) {
        beforeLast = last;
        last = last->next;
    }

    if (last == head) {
        delete head;
        head = NULL;
    } else {
        beforeLast->next = NULL;

        delete last;
        last = NULL;
    }
}
void deleteNode(Node *&head, int number) {
    if (!head) return;

    Node *current = head;
    Node *beforeCurrent = NULL;

    while (current->next && current->value != number) {
        beforeCurrent = current;
        current = current->next;
    }

    if (current->value != number) return;

    if (current == head) {
        head = head->next;
    } else {
        beforeCurrent->next = current->next;
    }

    delete current;
    current = NULL;
}

Node* getNode(Node* head, int number) {
    Node* current = head;

    while (current && current->value != number) {
        current = current->next;
    }

    return current;
}

int main() {
    Node *numbers = NULL;

    addLast(numbers, 2);
    addLast(numbers, 4);
    addLast(numbers, 6);

    cout << "Lista por nodos: " << endl;
    printListValues(numbers);
    cout << "-------------------------------------------\n";

    Node *node = getNode(numbers, 2);

    addAfterNode(node, 3);

    cout << "Lista por nodos: " << endl;
    printListValues(numbers);
    cout << "-------------------------------------------\n";

    return 0;
}

