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

void leerEnteros(FILE *stream) {
    int num;

    fseek(stream, 0, SEEK_SET);

    while (fread(&num, sizeof(float), 1, stream)) {
        cout << num << ", ";
    }

    cout << "\n" << endl;
}

void populateFiles(FILE *f1, FILE *f2) {
    int num1=1, num2=2, num3=3, num4=4;

    f1 = fopen("bin/archivo1", "wb");
    f2 = fopen("bin/archivo2", "wb");

    fwrite(&num1, sizeof(int), 1, f1);
    fwrite(&num3, sizeof(int), 1, f1);

    fwrite(&num2, sizeof(int), 1, f2);
    fwrite(&num4, sizeof(int), 1, f2);

    fclose(f1);
    fclose(f2);
}

void populateFiles2(FILE *f1, FILE *f2) {
    //int numbers1[] = {1,4,5,20,31};
    //int numbers2[] = {3,6,8,9,12};
    int numbers1[] = {1,2,3,4};
    int numbers2[] = {5,6,7};

    //int numbers1[] = {1,2,3,5,9,10};
    //int numbers2[] = {4,6,7,8};

    f1 = fopen("bin/archivo1", "wb");
    f2 = fopen("bin/archivo2", "wb");


    fwrite(numbers1, sizeof(int), 5, f1);
    fwrite(numbers2, sizeof(int), 6, f2);


    fclose(f1);
    fclose(f2);

    /*f1 = fopen("bin/archivo1", "rb");
    f2 = fopen("bin/archivo2", "rb");

    cout << "Numeros en f1:" << endl;
    leerEnteros(f1);

    cout << "Numeros en f2:" << endl;
    leerEnteros(f2);

    fclose(f1);
    fclose(f2);*/
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

void ejercicio3() {
    cout << "********************* Ejercicio 3 *********************\n" << endl;

    FILE *f1, *f2, *f3;
    int elem, num1, num2;

    populateFiles(f1, f2);

    if (
        (f1 = fopen("bin/archivo1", "rb")) != NULL &&
        (f2 = fopen("bin/archivo2", "rb")) != NULL &&
        (f3 = fopen("bin/archivo3", "wb+")) != NULL
    ) {
        while (
            fread(&num1, sizeof(int), 1, f1) &&
            fread(&num2, sizeof(int), 1, f2)
        ) {
            cout << "contenido archivo 1: " << num1 << endl;
            cout << "contenido archivo 2: " << num2 << endl;

            fwrite(&num1, sizeof(int), 1, f3);
            fwrite(&num2, sizeof(int), 1, f3);
        }

        fclose(f1);
        fclose(f2);

        cout << "\nContenido de archivo3: ";

        fseek(f3, 0, SEEK_SET);

        while(fread(&elem, sizeof(int), 1, f3)) {
            cout << elem << ", ";
        }
    } else {
        cout << "No se pudo abrir ninguno de los archivos";
    }
}

void ejercicio4() {
    cout << "********************* Ejercicio 4 *********************\n" << endl;

    FILE *f1, *f2, *f3;
    int elem1, elem2/*, lastRead = 0*/;

    populateFiles2(f1,f2);

    f1 = fopen("bin/archivo1", "rb");
    f2 = fopen("bin/archivo2", "rb");
    f3 = fopen("bin/archivo3", "wb");

    if (f1 && f2 && f3) {
        while(fread(&elem1, sizeof(int), 1, f1) && fread(&elem2, sizeof(int), 1, f2)) {
            //cout << elem1 << " < " << elem2 << " -> " << (elem1 < elem2) << endl;

            if (elem1 < elem2) {
                fwrite(&elem1, sizeof(int), 1, f3);
                fseek(f2, -sizeof(int), SEEK_CUR);  //Lo pongo una posición atrás
                //lastRead = 1;
                cout << "se escribió " << elem1 << endl;
            } else {
                fwrite(&elem2, sizeof(int), 1, f3);
                fseek(f1, -sizeof(int), SEEK_CUR);  //Lo pongo una posición atrás
                //lastRead = 2;
                cout << "se escribió " << elem2 << endl;
            }
        }

        cout << "Listo elem1=" << elem1 << " y elem2=" << elem2 << endl;
        cout << "feof de f1=" << feof(f1) << " y feof de f2=" << feof(f2) << endl;
        cout << "cursor de f1 = " << ftell(f1) << ". Cursor de f2 = " << ftell(f2) << endl;

        //if (lastRead == 1) fseek(f2, -sizeof(int), SEEK_CUR);
        //else if (lastRead == 2) fseek(f1, -sizeof(int), SEEK_CUR);

        while(!feof(f1) && fread(&elem1, sizeof(int), 1, f1)) {
            fwrite(&elem1, sizeof(int), 1, f3);
            cout << "1) Se escribio " << elem1 << endl;
        }

        while(!feof(f2) && fread(&elem2, sizeof(int), 1, f2)) {
            cout << "2) Se leyo " << elem2 << ". Cursor en " << ftell(f2) << endl;
            fwrite(&elem2, sizeof(int), 1, f3);
            cout << "2) Se escribio " << elem2 << endl;
            cout << "2) Cursor en " << ftell(f2) << endl;
        }

        fclose(f1);
        fclose(f2);
        fclose(f3);
    } else {
        cout << "No se pudieron abrir";
    }

    f3 = fopen("bin/archivo3", "rb");
    leerEnteros(f3);
    fclose(f3);
}

void ejercicio5() {
    FILE *f1, *f2, *f3;
    int elem1, elem2;

    populateFiles2(f1,f2);

    f1 = fopen("bin/archivo1", "rb");
    f2 = fopen("bin/archivo2", "rb");
    f3 = fopen("bin/archivo3", "wb");

    if (f1 && f2 && f3) {
        while(fread(&elem1, sizeof(int), 1, f1) && fread(&elem2, sizeof(int), 1, f2)) {
            cout << elem1 << " < " << elem2 << " -> " << (elem1 < elem2) << endl;

            if (elem1 > elem2) {
                fwrite(&elem1, sizeof(int), 1, f3);
                fseek(f2, -sizeof(int), SEEK_CUR);  //Lo pongo una posición atrás
            } else {
                fwrite(&elem2, sizeof(int), 1, f3);
                fseek(f1, -sizeof(int), SEEK_CUR);  //Lo pongo una posición atrás
            }
        }

        cout << "Listo" << endl;

        while(!feof(f1)) {
            fwrite(&elem1, sizeof(int), 1, f3);
            fread(&elem1, sizeof(int), 1, f1);
        }

        while(!feof(f2)) {
            fwrite(&elem2, sizeof(int), 1, f3);
            fread(&elem2, sizeof(int), 1, f2);
        }

        fclose(f1);
        fclose(f2);
        fclose(f3);
    } else {
        cout << "No se pudieron abrir";
    }

    f3 = fopen("bin/archivo3", "rb");
    leerEnteros(f3);
    fclose(f3);
}

int main() {
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    ejercicio4();


    return 0;
}
