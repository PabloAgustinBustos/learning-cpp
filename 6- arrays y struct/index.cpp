#include <iostream>

using namespace std;

struct Alumno {
  char legajo[10];
  unsigned fecha_nacimiento;
  char nombre[100];
  char apellido[100];
};

void cargarAlumno (Alumno &alumno) {
  cout << "Legajo: ";
  cin >> alumno.legajo;

  cout << "nombre: ";
  cin >> alumno.nombre;

  cout << "apellido: ";
  cin >> alumno.apellido;

  cout << "fechaNac: ";
  cin >> alumno.fecha_nacimiento;

  return;
}

void mostrarAlumno (Alumno alumno) {
  cout << "Legajo: " << alumno.legajo;

  cout << "nombre: " << alumno.nombre;

  cout << "apellido: " << alumno.apellido;

  cout << "fechaNac: " << alumno.fecha_nacimiento;

  return;
}

int main() {
  Alumno alumno;
  Alumno alumnos[5];

  cargarAlumno(alumno);
  mostrarAlumno(alumno);
  return 0;
}