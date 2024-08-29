#include <iostream>

using namespace std;

void digitAmount() {
  int number;
  
  cout << "number: ";
  cin >> number;

  if (number == 0) {
    cout << "cero" << endl;
  } else {
    int counter = 0;

    while (number != 0) {
      number /= 10;
      counter++;
    }

    cout << "cantidad de dígitos: " << counter << endl;
  }
}

void reverseNumber() {
  int number, reversedNumber = 0;
  
  cout << "number: ";
  cin >> number;

  while (number != 0) {
    reversedNumber *= 10;

    int lastDigit = number % 10;
    reversedNumber += lastDigit;
    
    number /= 10;
  }

  cout << reversedNumber << endl;
}

void PINValidator() {
  int userPIN = 3659, PIN, errorCounter = 0;
  
  do {
    cout << "Enter PIN: ";
    cin >> PIN;

    if (PIN != userPIN) errorCounter++;
  } while (userPIN != PIN);

  cout << "Tuviste " << errorCounter << " intentos" << endl;
}

void ejercicio12() {
  int sum = 0;

  for (int i = 1; i <= 100; i++) {
    cout << i << " ";
    sum += i;
  }

  cout << "\nsumatoria: " << sum << endl;
}

void ejercicio13() {
  int n, m, product = 0;

  cout << "n: ";
  cin >> n;

  cout << "m: ";
  cin >> m;

  for (int i = 0; i < m; i++) {
    product += n;
  }

  cout << n << "*" << m << " = " << product << endl;
}

void ejercicio15() {
  int valorMultaL = 0, 
      valorMultaM = 0, 
      valorMultaG = 0, 
      valorMulta;

  int cantidadMultaL = 0,
      cantidadMultaM = 0,
      cantidadMultaG = 0;

  int tipoInfraccion, cantidadInfraccionesGraves = 0;

  char gravedad;

  for (int i = 0; i < 4; i++) {
    cout << "-----infracción " << (i+1) << "-----" << endl;

    do {
      cout << "tipo de infracción: ";
      cin >> tipoInfraccion;
    } while (tipoInfraccion < 1 || tipoInfraccion > 4);

    do {
      cout << "gravedad: ";
      cin >> gravedad;
    } while(gravedad != 'L' && gravedad != 'M' && gravedad != 'G');

    if ((tipoInfraccion == 3 || tipoInfraccion == 4) && gravedad == 'G') cantidadInfraccionesGraves++;
    
    cout << "multa: ";
    cin >> valorMulta;

    switch (gravedad) {
      case 'L': 
        valorMultaL += valorMulta;
        cantidadMultaL++;
        break;
      
      case 'M': 
        valorMultaM += valorMulta;
        cantidadMultaM++;
        break;
      
      case 'G': 
        valorMultaG += valorMulta;
        cantidadMultaG++;
        break;
      
      default: cout << "gravedad inválida" << endl;
    }

    cout << "" << endl;
  }

  cout << "-------resumen--------" << endl;
  cout << "Infracciones L (x" << cantidadMultaL << ")\t$" << valorMultaL << endl;
  cout << "Infracciones M (x" << cantidadMultaM << ")\t$" << valorMultaM << endl;
  cout << "Infracciones G (x" << cantidadMultaG << ")\t$" << valorMultaG << endl;
  cout << "" << endl;
  cout << "Total: \t\t\t$" << (valorMultaL + valorMultaM + valorMultaG) << endl;

  if (cantidadInfraccionesGraves > 3) {
    cout << "CLAUSURAR FÁBRICA" << endl;
  }
}

void ejercicio16() {
  int counter = 0, value=0;

  do {
    cout << "value: ";
    cin >> value;

    counter++;
  } while (value >= 0);

  // for (int i = 0; value >= 0; i++) {
  //   cout << "value: ";
  //   cin >> value;

  //   counter++;
  // }

  cout << "input amount: " << counter << endl;
}

void ejercicio18() {
  int num;

  cout << "num: ";
  cin >> num;

  for (int i = 1; i <= num; i++) {
    if ((i%3 == 0) && (i%5 != 0)) cout << i << endl;
  }
}

int main() {
  // digitAmount();
  // reverseNumber();
  // PINValidator();
  
  // ejercicio12();
  // ejercicio13();
  // ejercicio15();
  // ejercicio16();
  ejercicio18();

  return 0;
}