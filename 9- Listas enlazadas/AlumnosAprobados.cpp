#include <iostream>
#include <cstring>

using namespace std;

struct Alumno {
    int legajo;
    char nombre[50];
    int fechaNac;
};

struct MateriaAprobada {
    int codigo;
    int legajoAlumno;
    int nota;
    int fechaDeFirma;
};

struct NodoMateriaAprobada {
    MateriaAprobada materia;
    NodoMateriaAprobada *next = NULL;
};

struct NodoAlumno {
    Alumno alumno;

    NodoAlumno *next = NULL;
    NodoAlumno *prev = NULL;

    // Sublista de materias aprobadas
    NodoMateriaAprobada *materiasAproadas = NULL;
};

void logNode(NodoAlumno *node) {
    if (!node) {
        cout << "NULL" << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << " alumno: {" << endl;
    cout << "   legajo: " << node->alumno.legajo << endl;
    cout << "   nombre: " << node->alumno.nombre << endl;
    cout << "   fechaNac: " << node->alumno.fechaNac << endl;
    cout << " }," << endl;
    cout << " next: " << node->next << endl;
    cout << "}" << endl;
}
void printList(NodoAlumno *head) {
    if (!head) {
        cout << "NULL" << endl;
        return;
    }

    NodoAlumno *current = head;

    do {
        logNode(current);

        current = current->next;
    } while (current);
}

void addLast(NodoAlumno *&head, Alumno alumno) {
    if (!head) {
        head = new NodoAlumno();
        head->alumno = alumno;

        return;
    }

    NodoAlumno *last = head;

    while (last->next) {
        last = last->next;
    }

    last->next = new NodoAlumno();
    last = last->next;
    last->alumno = alumno;
}

void guardarAlumno(Alumno alumno) {
    FILE *f;

    if((f = fopen("db/alumnos.dat", "ab")) != NULL) {
        cout << "Voy a guardar la info de " << alumno.nombre << endl;

        int guardado = fwrite(&alumno, sizeof(Alumno), 1, f);

        if (guardado) cout << "Alumno guardado.\n" << endl;
        else cout << "No se pudo guardar.\n" << endl;

        fclose(f);
    } else {
        cout << "Error al crear archivo." << endl;
    }
}

void leerAlumnos(NodoAlumno *&alumnos) {
    FILE *f;
    Alumno alumno;

    if((f = fopen("db/alumnos.dat", "rb")) != NULL) {
        while(fread(&alumno, sizeof(Alumno), 1, f)) {
            addLast(alumnos, alumno);
        }

        fclose(f);
    } else {
        cout << "Error al crear archivo." << endl;
    }
}

int main() {
    NodoAlumno *alumnos = NULL;

    /*Alumno a1, a2;

    a1.legajo = 1;
    strcpy(a1.nombre, "Pablo");
    a1.fechaNac = 20001113;

    a2.legajo = 2;
    strcpy(a2.nombre, "Juan");
    a2.fechaNac = 20001113;*/


    //guardarAlumno(a1);
    //guardarAlumno(a2);

    leerAlumnos(alumnos);

    printList(alumnos);
    /*cout << alumnos->alumno.legajo << endl;
    cout << alumnos->alumno.nombre << endl;
    cout << alumnos->alumno.fechaNac << endl;

    cout << "\n";

    cout << alumnos->next->alumno.legajo << endl;
    cout << alumnos->next->alumno.nombre << endl;
    cout << alumnos->next->alumno.fechaNac << endl;*/


    return 0;
}
