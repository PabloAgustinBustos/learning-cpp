#include <iostream>

using namespace std;

void llenarArray(int *p) {
    for (int i = 0; i < 5; i++) {
        cout << "Ingresar numero en posicion " << p+i << " -> ";    // Muestra la dirección
        cin >> *(p+i);  // lo guarda en donde esté apuntando p+i
    }
}

void mostrarArray(int *p, bool reverse=false) {
    if (!reverse) {
        for (int i = 0; i< 5; i++) {
            cout << (p+i) << " -> " << *(p+i) << endl;
        }
    } else {
        for (int i = 4; i>=0; i--) {
            cout << (p+i) << " -> " << *(p+i) << endl;
        }
    }
}

void ejercicio1() {
    int array[5];   // Creo el array

    int *p = array; // Asigno en p la dirección de memoría de array

    llenarArray(p);

    cout << "\n";

    mostrarArray(p);
}

void ejercicio2() {
    int array[5];   // Creo el array

    int *p = array; // Asigno en p la dirección de memoría de array

    llenarArray(p);

    cout << "\n";

    mostrarArray(p, true);  // el segundo parámetro indica que será mostrado en reversa
}

int main() {
    //ejercicio1();
    //ejercicio2();


    return 0;
}
