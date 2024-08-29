#include <iostream>
#include <stdlib.h>

using namespace std;

void ejercicio1() {
    int elementAmount, bytesAmount;
    float num;
    FILE *stream;

    if((stream = fopen("bin/ejercicio1", "wb+")) != NULL) {
        cout << "Ingresar cantidad de números que va a ingresar: ";
        cin >> elementAmount;

        bytesAmount = elementAmount * sizeof(float);

        cout << "Se escribiran "<< bytesAmount << " bytes\n" << endl;

        for (int i = 0; i < elementAmount; i++) {
            cout << (i+1) << ") Ingresar numero float: ";
            cin >> num;

            fwrite(&num, sizeof(float), 1, stream);
            cout << "Se escribio " << sizeof(float) << " bytes\n" << endl;
        }

        cout << "Cursor en byte " << ftell(stream) << endl;
        fseek(stream, -bytesAmount, SEEK_CUR);                                           // Si bytesAmount es 12, muevo el cursor 12 bytes hacia atrás
        cout << "Cursor se movio y esta en byte " << ftell(stream) << "\n" << endl;

        cout << "Numeros guardados: ";

        for (int i = 0; i < elementAmount; i++) {
            fread(&num, sizeof(float), 1, stream);

            cout << num;

            if (i < elementAmount-1) cout << ", ";
        }

        fclose(stream);
    } else {
        cout << "No se pudo abrir el archivo";
    }

}

int main() {
    ejercicio1();
    return 0;
}
