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
void printListValues(Node* node) {
    while (node != NULL) {
        //logNode(node);
        cout << node->value;

        if (node->next == NULL) cout << "\n";
        else cout << ", ";

        node = node->next;
    }
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

void deleteFirst(Node* &head) {
    if (head) {
        Node *aux = head;

        head = head->next;

        delete aux;
    }

}
void deleteLast(Node* &head) {
    if (!head) return;  // Caso de lista vacía

    Node* last = head;
    Node* beforeLast;   // Necesito trackear también el nodo anterior al último

    // Mientras que haya un siguiente nodo
    while (last->next) {
        beforeLast = last;
        last = last->next;
    }

    if (last == head) {
        // Caso de único elemento en la lista

        delete head;    // Liberamos la memoría
        head = NULL;    // Dejamos de apuntar a un espacio vacío
    } else {
        // Caso donde haya más elementos

        beforeLast->next = NULL;    // Desconectamos los nodos
        delete last;    // Eliminamos el que antes era el último
        last = NULL;
    }
}

int main() {
    Node* head  = NULL;

    addLast(head, 1);
    addLast(head, 2);
    addLast(head, 3);

    addFirst(head, 0);
    addFirst(head, -1);

    cout << "Lista: " << endl;
    printListValues(head);

    deleteLast(head);

    cout << "\nLista: " << endl;
    printListValues(head);

    return 0;
}
