#include <iostream>
#include <stdlib.h>

using namespace std;

void leerFloats(FILE *stream) {
    float num;

    fseek(stream, 0, SEEK_SET);

    cout << "numeros: ";

    while (fread(&num, sizeof(float), 1, stream)) {
        cout << num << ", ";
    }

    cout << "\n" << endl;
}

void ejercicio1() {
    cout << "********************* Ejercicio 1 *********************\n" << endl;

    int elementAmount, bytesAmount;
    float num;
    FILE *stream;

    if((stream = fopen("bin/ejercicio1", "wb+")) != NULL) {
        cout << "Ingresar cantidad de numeros que va a ingresar: ";
        cin >> elementAmount;

        bytesAmount = elementAmount * sizeof(float);

        cout << "Se escribiran "<< bytesAmount << " bytes\n" << endl;

        for (int i = 0; i < elementAmount; i++) {
            cout << (i+1) << ") Ingresar numero float: ";
            cin >> num;

            fwrite(&num, sizeof(float), 1, stream);
        }

        fseek(stream, -bytesAmount, SEEK_CUR);                                           // Si bytesAmount es 12, muevo el cursor 12 bytes hacia atrás

        cout << "\n" << endl;
        cout << "Numeros guardados: ";

        for (int i = 0; i < elementAmount; i++) {
            fread(&num, sizeof(float), 1, stream);

            cout << num;

            if (i < elementAmount-1) cout << ", ";
        }

        cout << "\n" << endl;

        fclose(stream);
    } else {
        cout << "No se pudo abrir el archivo\n" << endl;
    }

}

void ejercicio2() {
    cout << "********************* Ejercicio 2 *********************\n" << endl;

    int byte;
    float newNumber;
    FILE *stream;

    if ((stream = fopen("bin/ejercicio1", "rb+")) != NULL) {
        do {
            cout << "Ingrese byte donde se encuentra el numero a reemplazar: ";
            cin >> byte;
        } while(byte % 4 != 0);

        cout << "Ingresar nuevo numero a guardar en esa posicion: ";
        cin >> newNumber;

        fseek(stream, byte, SEEK_SET);

        cout << "\nCursor en posicion " << ftell(stream) << endl;

        fwrite(&newNumber, sizeof(float), 1, stream);

        cout << "Numero actualizado y cursor en posición " << ftell(stream) << "\n" << endl;

        leerFloats(stream);

        fclose(stream);
    } else {
        cout << "No se pudo abrir el archivo\n" << endl;
    }
}

int main() {
    ejercicio1();
    ejercicio2();

    return 0;
}
