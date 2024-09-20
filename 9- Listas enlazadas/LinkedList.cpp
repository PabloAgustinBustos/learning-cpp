#include <iostream>

using namespace std;

struct Node {
    int value = NULL;
    Node* next = NULL;
};

void logNode(Node* node) {
    if (!node) {
        cout << NULL << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << "  value: " << node->value << endl;
    cout << "  next: " << node->next << endl;
    cout << "}" << endl;
}
void printList(Node* node) {
    while (node != NULL) {
        logNode(node);
        node = node->next;
    }
}
void addFirst(Node* &head, int newNumber) {
    Node* aux = head;   // Mantengo guardado el head en otro puntero para no perderlo

    head = new Node();
    head->value = newNumber;
    head->next = aux;
}
void addLast(Node* &head, int newNumber) {
    if (!head) {
        head = new Node();
        head->value = newNumber;

        return;
    }

    Node* last = head;  // Uso un nodo auxiliar que representará el último nodo en la lista

    while (last->next != NULL) {    // Recorro hasta llegar al último nodo
        last = last->next;
    }

    // Añado el nuevo nodo
    last->next = new Node();
    last = last->next;          // Ahora hay un nuevo último nodo, lo obtengo.
    last->value = newNumber;
}
Node* getNode(Node* head, int number) {
    Node* node = head;

    while (node != NULL && node->value != number) {
        node = node->next;
    }

    return node;
}

int main() {
    Node* head  = NULL;

    addLast(head, 1);
    addLast(head, 2);
    addLast(head, 3);

    addFirst(head, 0);
    addFirst(head, -1);

    cout << "Lista: " << endl;
    printList(head);

    Node* elem = getNode(head, 2);

    cout << "\nEncontre este nodo ";
    logNode(elem);

    cout << "\n";

    printList(head);

    return 0;
}

