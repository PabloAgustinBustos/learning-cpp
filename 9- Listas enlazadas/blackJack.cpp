#include <iostream>

using namespace std;

struct NodeCard {
    char value;
    NodeCard *next = NULL;
};

void addLast(NodeCard *&head, char newLetter) {
    if (!head) {
        head = new NodeCard();
        head->value = newLetter;

        return;
    }

    NodeCard *last = head;

    while (last->next) {
        last = last->next;
    }

    last->next = new NodeCard();
    last = last->next;
    last->value = newLetter;
}

void printListValues(NodeCard *head) {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }

    NodeCard *current = head;

    do {
        cout << current->value;

        if (current->next) cout << ", ";
        else cout << "\n";

        current = current->next;
    } while (current);
}

void nullify(NodeCard *mesa[], int players) {
    for(int i = 0; i < players; i++){
        mesa[i] = NULL;
    }
}

int main() {
    NodeCard *mesa[5];

    nullify(mesa, 5);

    addLast(mesa[3], 'A');
    addLast(mesa[3], 'K');

    for(int i = 0; i < 5; i++) {
        cout << "mesa " << i+1 << endl;
        printListValues(mesa[i]);
    }

    return 0;
}
