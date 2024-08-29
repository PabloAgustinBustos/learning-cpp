#include <iostream>

using namespace std;

void ejercicio5() {
  int num1, num2;

  cout  << "num1: ";
  cin   >> num1;

  cout  << "num2: ";
  cin   >> num2;

  if (num1 > num2) cout << "\n" << num1 << " > " << num2 << endl;
  else if (num2 > num1) cout << "\n" << num2 << " > " << num1 << endl;
  else cout << "\nSon iguales xd" << endl;
}

void ejercicio6() {
  int date1, date2;

  cout  << "date1 en formato AAAAMMDD: ";
  cin   >> date1;

  cout  << "date2 en formato AAAAMMDD: ";
  cin   >> date2;

  if (date1 > date2) cout << "\nfecha más reciente: " << date1 << endl;
  else cout << "\nfecha más reciente: " << date2 << endl;
}

void ejercicio7() {
  int l1, l2, l3;

  cout  << "l1: ";
  cin   >> l1;

  cout  << "l2: ";
  cin   >> l2;

  cout  << "l3: ";
  cin   >> l3;

  bool cond1 = (l1+l2) > l3;
  bool cond2 = (l1+l3) > l2;
  bool cond3 = (l2+l3) > l1;

  if (cond1 && cond2 && cond3) cout << "Forman triangulo" << endl;
  else cout << "No forman triangulo" << endl;
}

void ejercicio8() {
  int l1, l2, l3;

  cout  << "l1: ";
  cin   >> l1;

  cout  << "l2: ";
  cin   >> l2;

  cout  << "l3: ";
  cin   >> l3;

  bool isEquilatero = (l1 == l2) && (l1 == l3);
  bool isIsosceles  = ((l1 == l2) && (l1 != l3)) || ((l1 == l3) && (l1 != l2)) || ((l2 == l3) && (l1 != l2));
  bool isEscaleno   = (l1 != l2) && (l1 != l3) && (l2 != l3);

  if (isEquilatero) cout << "es equilatero" << endl;
  if (isIsosceles)  cout << "es isosceles"  << endl;
  if (isEscaleno)   cout << "es escaleno"   << endl;
}

void ejercicio9() {
  int year, month;

  cout  << "ingresar año: ";
  cin   >> year;

  cout  << "ingresar mes: ";
  cin   >> month;

  bool isBisiesto = (((year%4 == 0) && (year%100 != 0))) || (year % 400 == 0);

  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      cout << "Tiene 31 dias" << endl;
      
      break;
    
    case 2:
      if (isBisiesto) cout << "Tiene 29 dias" << endl;
      else cout << "Tiene 28 dias" << endl;
      
      break;
    
    case 4:
    case 6:
    case 9:
    case 11:
      cout << "Tiene 30 dias" << endl;
      break;

    default: cout << "Mes incorrecto" << endl;
  }
}

void ejercicio10() {
  int age;

  cout << "edad: ";
  cin >> age;

  if (age <= 12) cout << "menor" << endl;
  if (12 < age && age < 19) cout << "cadete" << endl;
  if (18 < age && age < 27) cout << "juvenil" << endl;
  if (age > 26) cout << "mayor" << endl;
}

int main() {
  // ejercicio5();
  // ejercicio6();
  // ejercicio7();
  // ejercicio8();
  // ejercicio9();
  // ejercicio10();

  return 0;
}