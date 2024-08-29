#include <iostream>
#include <stdlib.h>

using namespace std;

void escrituraDeBinario(FILE *f) {
    int x = 5, y = 2;

    if ((f = fopen("db", "wb")) != NULL) {
        cout << "abierto" << endl;

        cout << "escribiendo " << sizeof(int)*2 << " bytes" << endl;
        fwrite(&x, sizeof(int), 1, f);
        fwrite(&y, sizeof(int), 1, f);

        cout << "escrito\n" << endl;

        fclose(f);
    } else {
        cout << "no se pudo abrir\n" << endl;
    }
}

void escrituraDeChar(FILE *f) {
    char letra = 'a';

    if ((f = fopen("db", "wb")) != NULL) {
        cout << "abierto" << endl;

        fwrite(&letra, sizeof(char), 1, f);

        cout << "escrito" << endl;

        fclose(f);
    } else {
        cout << "no se pudo abrir";
    }
}

void escrituraDeString(FILE *f) {
    string nombre = "pablo";

    if ((f = fopen("db", "w")) != NULL) {
        for (int i = 0; i < 5; i++) {
            fwrite(&nombre[i], sizeof(char), 1, f);
        }

        fclose(f);
    } else {
        cout << "no se pudo abrir";
    }
}

void leerUnSoloNumero(FILE *f) {
    int num, amount;

    if ((f = fopen("db", "rb")) != NULL) {
        cout << "abierto con cursor en posicion " << ftell(f) << endl;

        amount = fread(&num, sizeof(num), 1, f);

        cout << "lei " << amount << " dato. Cursor en posicion " << ftell(f) << endl;
        cout << "dato leido: " << num << endl;
    } else {
        cout << "No se pudo leer el archivo\n" << endl;
    }
}

void leerVariosNumeros(FILE *f) {
    int num, amount;

    if ((f = fopen("db", "rb")) != NULL) {
        cout << "abierto con cursor en posicion " << ftell(f) << endl;

        while (!feof(f)) {
            fread(&num, sizeof(num), 1, f);
            cout << "dato leido: " << num << endl;
            cout << "Cursor en posición " << ftell(f) << endl;
            cout << "EOF:" << feof(f) << "\n" << endl;
        }
    } else {
        cout << "No se pudo leer el archivo\n" << endl;
    }
}

int main() {
    // Creación del archivo
    FILE *f;

    escrituraDeBinario(f);
    //escrituraDeChar(f);
    //escrituraDeString(f);

    //leerUnSoloNumero(f);
    leerVariosNumeros(f);
    return 0;
}
