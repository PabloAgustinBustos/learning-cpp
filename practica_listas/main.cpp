#include <iostream>

using namespace std;

struct Node {
    int value = 0;
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

    while(current) {
        logNode(current);

        current = current->next;
    }
}

void printListValues(Node *head) {
    if(!head) {
        cout << "Lista vacía" << endl;
        return;
    }

    Node *current = head;

    while(current) {
        cout << current->value;

        if(current->next) cout << ", ";
        else cout << "." << endl;

        current = current->next;
    }
}

int main()
{
    Node *a = new Node();
    Node *b = new Node();

    a->value=1;
    b->value=2;

    a->next = b;

    printListValues(a);

    return 0;
}
