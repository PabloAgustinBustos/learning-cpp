#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct Alumno {
    int legajo;
    char nombre[50];
    char apellido[50];
    char DNI[10];
    int codigoCarrera;
};

struct Materia {
    char nombre[50];
    char fechaAprobacion[11];
    int nota;
    int legajoAlumno;
};

struct NodoMateriaAprobada {
    Materia materia;
    NodoMateriaAprobada *next = NULL;
};

struct NodoAlumno {
    Alumno alumno;

    NodoAlumno *next = NULL;
    NodoAlumno *prev = NULL;

    // Sublista de materias aprobadas
    NodoMateriaAprobada *materiasAproadas = NULL;
};

void printMateriasNombre(NodoMateriaAprobada* head) {
    if (!head) {
        cout << "Ninguna aprobada" << endl;
        return;
    }

    NodoMateriaAprobada *current = head;

    do {
        cout << current->materia.nombre << "(" << current->materia.nota << ")";

        if (current->next) cout << ", ";
        else cout << "\n";

        current = current->next;
    } while (current);
}

void logNode(NodoAlumno *node) {
    if (!node) {
        cout << "NULL" << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << "   alumno: {" << endl;
    cout << "       legajo: " << node->alumno.legajo << endl;
    cout << "       nombre: " << node->alumno.nombre << endl;
    cout << "       apellido: " << node->alumno.apellido << endl;
    cout << "       DNI: " << node->alumno.DNI << endl;
    cout << "       codigoCarrera: " << node->alumno.codigoCarrera << endl;
    cout << "       materiasAprobadas: ";
    printMateriasNombre(node->materiasAproadas);
    cout << "   }," << endl;
    cout << "   next: " << node->next << endl;
    cout << "   prev: " << node->prev << endl;
    cout << "}" << endl;
}
void printList(NodoAlumno *head) {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }

    NodoAlumno *current = head;

    do {
        logNode(current);
        cout << "\n";

        current = current->next;
    } while (current);
}

void logNodoMateria(NodoMateriaAprobada* node) {
    if (!node) {
        cout << "NULL" << endl;
        return;
    }

    cout << node << " {" << endl;
    cout << "   materia: {" << endl;
    cout << "       nombre: " << node->materia.nombre << endl;
    cout << "       fechaAprobacion: " << node->materia.fechaAprobacion << endl;
    cout << "       nota: " << node->materia.nota << endl;
    cout << "       legajoAlumno: " << node->materia.legajoAlumno << endl;
    cout << "   }," << endl;
    cout << "   next: " << node->next << endl;
    cout << "}" << endl;
}
void printListMaterias(NodoMateriaAprobada* head) {
    if (!head) {
        cout << "Lista vacia" << endl;
        return;
    }

    NodoMateriaAprobada *current = head;

    do {
        logNodoMateria(current);
        cout << "\n";

        current = current->next;
    } while (current);
}

void addLast(NodoAlumno *&head, Alumno newAlumno) {
    if (!head) {
        head = new NodoAlumno();
        head->alumno = newAlumno;

        return;
    }

    NodoAlumno *last = head;

    while (last->next) {
        last = last->next;
    }

    NodoAlumno *newNodoAlumno = new NodoAlumno();
    newNodoAlumno->alumno = newAlumno;

    last->next = newNodoAlumno;
    newNodoAlumno->prev = last;
}
void addLastMateria(NodoMateriaAprobada *&head, Materia newMateria) {
    if (!head) {
        head = new NodoMateriaAprobada();
        head->materia = newMateria;

        cout << "se agregó primer elemento en direccion " << head << " la materia " << newMateria.nombre << " del alumno " << newMateria.legajoAlumno << endl;
        return;
    }

    cout << "Hay un head " << head << endl;

    NodoMateriaAprobada *last = head;

    while (last->next) {
        last = last->next;
    }

    NodoMateriaAprobada *newNodoMateriaAprobada = new NodoMateriaAprobada();
    newNodoMateriaAprobada->materia = newMateria;

    last->next = newNodoMateriaAprobada;
}

void deleteNode(NodoAlumno *&node) {
    if (!node) return;

    NodoAlumno *next = node->next;
    NodoAlumno *prev = node->prev;

    if(prev) prev->next = next;
    if(next) next->prev = prev;

    delete node;
    node = NULL;
}
void deleteLastMateria(NodoMateriaAprobada *&head) {
    if (!head) return;

    NodoMateriaAprobada *last = head;
    NodoMateriaAprobada *beforeLast;

    while (last->next) {
        beforeLast = last;
        last = last->next;
    }

    if (last == head) {
        delete head;
        head = NULL;
    } else {
        beforeLast->next = NULL;

        delete last;
        last = NULL;
    }
}
void deleteLast(NodoAlumno *&head) {
    if (!head) return;

    NodoAlumno *last = head;
    NodoAlumno *beforeLast;

    while (last->next) {
        beforeLast = last;
        last = last->next;
    }

    if (last == head) {
        deleteLastMateria(head->materiasAproadas);

        delete head;
        head = NULL;
    } else {
        beforeLast->next = NULL;

        deleteLastMateria(last->materiasAproadas);

        delete last;
        last = NULL;
    }
}


double getAverage(NodoMateriaAprobada* head) {
    if (!head) return 0;

    double sum= 0, average = 0;
    int amount = 0;

    NodoMateriaAprobada* current = head;

    do {
        sum += current->materia.nota;
        amount++;

        current = current->next;
    } while (current);

    average = sum/amount;

    return average;
}

NodoAlumno* getAlumno(NodoAlumno* head, int legajo) {
    NodoAlumno* current = head;

    while (current && current->alumno.legajo != legajo) {
        current = current->next;
    }

    return current;
}

void guardarMaterias(NodoMateriaAprobada *head) {
    FILE *f;

    if((f = fopen("db/materiasAprobadas.dat", "wb")) && head) {
            NodoMateriaAprobada *current = head;

            do {
                Materia materia = current->materia;
                cout << "Voy a guardar la materia " << materia.nombre << endl;

                int guardado = fwrite(&materia, sizeof(Materia), 1, f);

                if (guardado) cout << "Materia guardada.\n" << endl;
                else cout << "No se pudo guardar.\n" << endl;

                current = current->next;
            } while (current);


        fclose(f);
    } else {
        cout << "Error al crear archivo." << endl;
    }
}

void guardarAlumno(Alumno alumno) {
    FILE *f;

    if(f = fopen("db/alumnos.dat", "ab")) {
        cout << "Voy a guardar la info de " << alumno.nombre << endl;

        int guardado = fwrite(&alumno, sizeof(Alumno), 1, f);

        if (guardado) cout << "Alumno guardado.\n" << endl;
        else cout << "No se pudo guardar.\n" << endl;

        fclose(f);
    } else {
        cout << "Error al crear archivo." << endl;
    }
}
void guardarAlumnos(NodoAlumno *head) {
    FILE *f;

    if((f = fopen("db/alumnos.dat", "wb")) && head) {
            NodoAlumno *current = head;

            do {
                Alumno alumno = current->alumno;
                cout << "Voy a guardar la info de " << alumno.nombre << endl;

                int guardado = fwrite(&alumno, sizeof(Alumno), 1, f);

                if (guardado) cout << "Alumno guardado.\n" << endl;
                else cout << "No se pudo guardar.\n" << endl;

                guardarMaterias(current->materiasAproadas);

                current = current->next;
            } while (current);


        fclose(f);
    } else {
        cout << "Error al crear archivo." << endl;
    }
}

void deleteAlumnos(NodoAlumno* &head) {
    if(!head) return;

    while(head) {


        deleteLast(head);

    }
}

void populateFile3() {
    NodoAlumno *alumnosAGuardar = NULL;
    Alumno a1, a2, a3;

    a1.legajo = 1;
    strcpy(a1.nombre, "Pablo");
    strcpy(a1.apellido, "Bustos");
    strcpy(a1.DNI, "1111111111");
    a1.codigoCarrera = 1;

    a2.legajo = 2;
    strcpy(a2.nombre, "Juan");
    strcpy(a2.apellido, "Linietzki");
    strcpy(a2.DNI, "2222222222");
    a2.codigoCarrera = 1;

    a3.legajo = 3;
    strcpy(a3.nombre, "Fede");
    strcpy(a3.apellido, "Ramirez");
    strcpy(a3.DNI, "3333333333");
    a3.codigoCarrera = 2;

    addLast(alumnosAGuardar, a1);
    addLast(alumnosAGuardar, a2);
    addLast(alumnosAGuardar, a3);

    Materia m1, m2, m3;

    strcpy(m1.nombre, "Algoritmos");
    strcpy(m1.fechaAprobacion, "2024/10/25");
    m1.nota = 9;
    m1.legajoAlumno = 1;

    strcpy(m2.nombre, "Algoritmos");
    strcpy(m2.fechaAprobacion, "2024/10/25");
    m2.nota = 10;
    m2.legajoAlumno = 2;

    strcpy(m3.nombre, "Algebra");
    strcpy(m3.fechaAprobacion, "2024/11/20");
    m3.nota = 9;
    m3.legajoAlumno = 3;

    addLastMateria(alumnosAGuardar->materiasAproadas, m1);
    addLastMateria(alumnosAGuardar->next->materiasAproadas, m2);
    addLastMateria(alumnosAGuardar->next->next->materiasAproadas, m3);

    cout << "memoria lista de materias alumno 1: " << alumnosAGuardar->materiasAproadas << endl;
    cout << "memoria lista de materias alumno 2: " << alumnosAGuardar->next->materiasAproadas << endl;
    cout << "memoria lista de materias alumno 3: " << alumnosAGuardar->next->next->materiasAproadas << endl;

    guardarAlumnos(alumnosAGuardar);
}

void leerAlumnos(NodoAlumno *&alumnos) {
    FILE *f;
    NodoAlumno* nodoAlumno = NULL;
    Alumno alumno;
    Materia materia;


    if(f = fopen("db/alumnos.dat", "rb")) {
        while(fread(&alumno, sizeof(Alumno), 1, f)) {
            addLast(alumnos, alumno);
        }

        fclose(f);
    } else {
        cout << "Error al leer archivo." << endl;
    }

    if(f = fopen("db/materiasAprobadas.dat", "rb")) {
        while(fread(&materia, sizeof(Materia), 1, f)) {
            nodoAlumno = getAlumno(alumnos, materia.legajoAlumno);

            //cout << nodoAlumno->alumno.nombre << " aprobo " << materia.nombre << " con " << materia.nota << endl;

            if(nodoAlumno) addLastMateria(nodoAlumno->materiasAproadas, materia);
        }
    } else {
        cout << "Error al leer archivo." << endl;
    }
}

Alumno ingresarDatos() {
    Alumno alumno;

    cout << "Ingresar legajo: ";
    cin >> alumno.legajo;

    cout << "Ingresar nombre: ";
    cin >> alumno.nombre;

    cout << "Ingresar apellido: ";
    cin >> alumno.apellido;

    cout << "Ingresar DNI: ";
    cin >> alumno.DNI;

    cout << "Ingresar codigo de carrera: ";
    cin >> alumno.codigoCarrera;

    cout << "\n";

    return alumno;
}
Materia ingresarDatosMateria() {
    Materia materia;

    cout << "Ingresar nombre: ";
    cin >> materia.nombre;

    cout << "Ingresar fecha de aprobacion: ";
    cin >> materia.fechaAprobacion;

    cout << "Ingresar nota: ";
    cin >> materia.nota;

    cout << "\n";

    return materia;
}

int ingresarLegajo() {
    int legajo;

    cout << "Ingresar legajo de alumno: ";
    cin >> legajo;

    return legajo;
}

void renderMenu() {
    /*cout << "1. Agregar alumno a la lista" << endl;
    cout << "2. Eliminar alumno de la lista" << endl;
    cout << "3. Revisar alumnos" << endl;
    cout << "4. Guardar lista " << endl;
    cout << "5. Ver materias aprobadas de un alumno " << endl;
    cout << "6. Salir\n" << endl;*/

    cout << "1. Ver datos de un alumno" << endl;
    cout << "2. Ver materias aprobadas de un alumno" << endl;
    cout << "3. Calcular promedio de un alumno" << endl;
    cout << "4. Agregar alumno" << endl;
    cout << "5. Agregar materia aprobada" << endl;
    cout << "6. Guardar todo y salir\n" << endl;
}

int main() {
    NodoAlumno *alumnos = NULL;
    int op = 0;

    populateFile3();

    leerAlumnos(alumnos);

    do {
        renderMenu();

        cout << "op: ";
        cin >> op;

        system("cls");

        switch(op) {
            case 1: {
                int legajo = ingresarLegajo();
                NodoAlumno *alumno = getAlumno(alumnos, legajo);

                if (!alumno) {
                    cout << "No existe alumno con legajo " << legajo << "\n" << endl;
                } else {
                    logNode(alumno);
                }

                break;
            }

            case 2: {
                int legajo = ingresarLegajo();
                NodoAlumno *alumno = getAlumno(alumnos, legajo);

                system("cls");

                if (!alumno) {
                    cout << "No existe alumno con legajo " << legajo << "\n" << endl;
                    break;
                }

                printListMaterias(alumno->materiasAproadas);

                break;
            }

            case 3: {
                int legajo = ingresarLegajo();
                NodoAlumno *alumno = getAlumno(alumnos, legajo);

                double average = getAverage(alumno->materiasAproadas);

                cout << "Promedio de " << alumno->alumno.nombre << ": " << average << "\n" << endl;

                break;
            }
            case 4: {
                Alumno alumno = ingresarDatos();
                addLast(alumnos, alumno);
                break;
            }

            case 5: {
                int legajo = ingresarLegajo();
                NodoAlumno *alumno = getAlumno(alumnos, legajo);

                system("cls");

                if (!alumno) {
                    cout << "No existe alumno con legajo " << legajo << "\n" << endl;
                    break;
                }

                Materia newMateria = ingresarDatosMateria();

                newMateria.legajoAlumno = legajo;

                addLastMateria(alumno->materiasAproadas, newMateria);

                break;
            }

            case 6:
                guardarAlumnos(alumnos);
                deleteAlumnos(alumnos);
                break;

            default:
                cout << "Opcion incorrecta\n" << endl;
        }
    } while (op != 6);

    cout << "Programa finalizado" << endl;
    //Alumno a = ingresarDatos();

    //populateFile();

    //leerAlumnos(alumnos);

    //printList(alumnos);


    return 0;
}
