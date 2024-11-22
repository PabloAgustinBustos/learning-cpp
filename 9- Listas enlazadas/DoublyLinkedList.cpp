#include <iostream>

using namespace std;

struct Node {
    int value = NULL;

    Node *next = NULL;
    Node *prev = NULL;
};

void logNode(Node *node) {
    if (!node) {
        cout << "NULL" << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << " value: " << node->value << endl;
    cout << " next: " << node->next << endl;
    cout << " prev: " << node->prev << endl;
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

    Node *newNode = new Node();
    newNode->value = newNumber;

    last->next = newNode;
    newNode->prev = last;
}
void addFirst(Node *&head, int newNumber) {
    Node *aux = head;

    head = new Node();
    head->value = newNumber;

    head->next = aux;
    aux->prev = head;
}
void addAfterNode(Node *node, int newNumber) {
    if (!node) return;

    Node *newNode = new Node();
    Node *aux = node->next;

    newNode->value = newNumber;

    node->next = newNode;
    newNode->prev = node;

    if(aux) {
        newNode->next = aux;
        aux->prev = newNode;
    }
}

void deleteFirst(Node *&head) {
    if(!head) return;

    Node *aux = head;
    head = head->next;

    head->prev = NULL;

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
        if(head) head->prev = NULL;
    } else {
        beforeCurrent->next = current->next;
        if (current->next) current->next->prev = beforeCurrent;
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

    addLast(numbers, 3);
    addLast(numbers, 5);
    addFirst(numbers, 2);
    addFirst(numbers, 1);
    addFirst(numbers, 0);

    Node *node = getNode(numbers, 3);

    addAfterNode(node, 4);

    printList(numbers);

    deleteFirst(numbers);

    printList(numbers);


    return 0;
}
