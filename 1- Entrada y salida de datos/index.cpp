#include <iostream>

using namespace std;

void ejercicio1() {
  int a = 5, b = 2;
  
  int suma      = a+b;
  int resta     = a-b;
  int producto  = a*b;

  cout << "la suma es "     << suma     << endl;
  cout << "la resta es "    << resta    << endl;
  cout << "el producto es " << producto << endl;
}

void ejercicio2() {
  int day   = 13;
  int month = 11;
  int year  = 2000;

  int date = (year * 10000) + (month * 100) + day;
  
  cout << date << endl;
}

void ejercicio3() {
  int date  = 20001113;

  int year  = date/10000;
  int rest  = date%10000;

  int month = rest/100;
  int day   = rest%100;

  cout << "year: "  << year   << endl;
  cout << "month: " << month  << endl;
  cout << "day: "   << day    << endl;
}

void ejercicio4() {
  float num;

  cout  << "ingresar num: ";
  cin   >> num;

  cout  << "\nquinta parte: "  << num/5      << endl;
  cout  << "resto: "           << int(num)%5 << endl;
  cout  << "septima parte: "   << (num/5)/7  << endl;
}

int main() {
  
  // ejercicio1();
  // ejercicio2();
  // ejercicio3();
  // ejercicio4();

  return 0;
}