#include <iostream>

/*
    El algoritmo se basa en tener un n�mero a agregar.
    El primero objetivo es buscar el nodo con el n�mero anterior al numero a agregar

    Ej: tengo la lista [2, 4, 5, 8] y si quiero a�adir el 7, el nodo que necesito es el que guarda el n�mero 5.
        Entonces al nodo en su next agrego el nuevo nodo. Previamente debo guardar el next para asignarselo al next del nuevo
        nodo

    Si No encontr� el nodo, osea, si lo que me reetorta getNode es NULL, significa que el n�mero nuevo es menor a todos los
    que ya estan en la lista y debo a�adirlo al principio.
*/

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

int getBiggest(Node* head) {
    if (!head) return 0;

    Node* current = head;

    int biggest;

    do {
        biggest = current->value;
        current = current->next;
    } while (current && current->value > biggest);

    return biggest;
}

double getAverage(Node* head) {
    if (!head) return 0;

    double sum= 0, average = 0;
    int amount = 0;

    Node* current = head;

    do {
        sum += current->value;
        amount++;

        current = current->next;
    } while (current);

    average = sum/amount;

    return average;
}

void addNumber(Node* &head, int newNumber) {
    if (!head) {
        addFirst(head, newNumber);
        return;
    }

    if (getNode(head, newNumber)) return;

    Node* node = head;
    Node* prev = NULL;

    do {
        if(node->value < newNumber) prev = node;

        node = node->next;
    } while (node && node->value < newNumber);

    if(prev) addAfterNode(prev, newNumber);
    else addFirst(head, newNumber);

}

void renderMenu() {
    std::cout << "1. Agregar n�mero a la lista" << std::endl;
    std::cout << "2. Buscar el mayor elemento" << std::endl;
    std::cout << "3. Calcular promedio" << std::endl;
    std::cout << "4. Salir\n" << std::endl;
}

int main() {
    system("clear");
    
    Node* numbers = NULL;
    int op = 0;

    do {
        std::cout << "Lista: ";
        printListValues(numbers);

        std::cout << "\n";

        renderMenu();

        std::cout << "op: ";
        std::cin >> op;

        switch(op) {
            case 1: {
                int number;

                std::cout << "\nNumero a a�adir: ";
                std::cin >> number;

                addNumber(numbers, number);

                system("clear");

                break;
            }

            case 2: {
                system("clear");

                std::cout << "Mayor numero: " << getBiggest(numbers) << std::endl;
                getchar();

                system("clear");

                break;
            }

            case 3:
                system("clear");

                std::cout << "Promedio: " << getAverage(numbers) << std::endl;
                getchar();

                system("clear");


                break;
            case 4:
                break;

            default:
                std::cout << "\nOpcion incorrecta\n" << std::endl;
        }
    } while(op != 4);
    return 0;
}
