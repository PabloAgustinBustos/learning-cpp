#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next = NULL;
};

// Paso por referencia porque necesito modificar el puntero inicial. Para los demás nodos es indistinto pasar por valor o por referencia
void append(Node *&lista, int newValue) {
    if (!lista) {
        lista = new Node(); // Para esto necesito recibir la lista por referencia
        lista->value = newValue;

        return;
    }

    Node *aux = lista;

    // Voy a recorrer hasta llegar al final
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = new Node();
    aux = aux->next;
    aux->value = newValue;
}

void showList(Node *lista) {
    while (lista) {
        cout << lista << " -> " << lista->value << endl;

        lista = lista->next;
    }

    cout << "\n";
}

void appendStart(Node *&lista, int newValue) {
    Node *aux = lista;

    lista = new Node();

    lista->value = newValue;
    lista->next = aux;
}

// Busqueda secuencial. Recibe la lista y un elemento a buscar
Node *getNode(Node *lista, int value) {
    while (lista && lista->value != value) {
        lista = lista->next;
    }

    return lista;
}

/*void insertNext(Nodo *&lista, int value, int newValue) {

}*/

void deleteFirstNode(Node *&lista) {
    Node *aux = lista;

    lista = lista->next;

    delete aux;
}

void deleteLast(Node *lista) {
    Node *prev = NULL, *last=lista;

    if (lista) {
        // Recorre la lista hasta llegar al final
        while (last->next) {
            prev = last;
            last = last->next;
        }

        // Lista con único nodo
        if (last == lista) {
            delete lista;
            lista = NULL;
        }else {
            prev->next = NULL;
            delete last;
        }
    }
}

void deleteSpecific(Node *deleted, Node *&lista) {
    Node *prev = lista;

    while(prev->next != deleted)  {
        prev = prev->next;
    }

    if (!deleted->next) {
        deleteLast(lista);
    } else if (deleted == lista) {
        deleteFirstNode(lista);
    } else {
        while (prev->next != deleted) {
            prev = prev->next;
        }

        prev->next = deleted->next;
    }
}

int main() {
    /*Node *lista = NULL;

    append(lista, 1);
    append(lista, 2);
    append(lista, 3);

    appendStart(lista, 10);
    appendStart(lista, 5);

    append(lista, 4);

    showList(lista);
    deleteLast(lista);
    showList(lista);*/

    return 0;
}
