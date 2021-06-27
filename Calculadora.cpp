#include <iostream>
#include <string>
#include <stdlib.h>
#include "Rational.hpp"

using namespace std;

const int MAX_OPCIONES = 6;
const int MAX_INTENTOS = 5;

// Muestra un menu con las diferentes opciones disponibles de la calculadora.
void menu_calculos(int& opcion);

// Pide los datos de tipo racional al usuario.
void pedir_operandos(Rational& R1, Rational& R2);

// Espera a que el usuario decida seguir con el programa.
void pause();

int main() {
	int opcion;
	int errores = 0;
	char operacion;

	do {
		menu_calculos(opcion);

		if (opcion < 0 || opcion > MAX_OPCIONES) {
			errores++;
			cout << "Intentos restantes: " + to_string(MAX_INTENTOS - errores) + "\n";
			pause();
		} else {
			if (opcion == 0) {
				cout << "Made with ❤️  by Hec7or. ©\n";
				break;
			} else {
				Rational R  = Rational();
				Rational R1 = Rational();
				Rational R2 = Rational();
				if (opcion != 5 && opcion != 6) {
					pedir_operandos(R1, R2);
				} else if (opcion == 5) {
					cout << "? ";
					cin >> R1;
				} else {
					cout << "? ";
					cin >> R1 >> operacion >> R2;
				}

				if (opcion == 1 || operacion == '+') {
					R = R1 + R2;
					cout << "= " << R << endl;
				} else if (opcion == 2 || operacion == '-') {
					R = R1 - R2;
					cout << "= " << R << endl;
				} else if (opcion == 3 || operacion == '*') {
					R = R1 * R2;
					cout << "= " << R << endl;
				} else if (opcion == 4 || operacion == '/') {
					R = R1 / R2;
					cout << "= " << R << " : ";
					R = R1 % R2;
					cout << R << endl;
				} else if (opcion == 5) {
					R = R1.inverso();
					cout << "= " << R << endl;
				}
				pause();
			}
		}
	} while ((0 < opcion) && (opcion < MAX_OPCIONES) || (errores <= MAX_INTENTOS));

	return 0;
}

void menu_calculos(int& opcion) {
	cout << "\n__MENU_CALCULADORA__" << endl;
	cout << "1. Suma" << endl;
	cout << "2. Resta" << endl;
	cout << "3. Multiplicacion" << endl;
	cout << "4. Division" << endl;
	cout << "5. Inverso" << endl;
	cout << "6. Introducir operacion manualmente" << endl;
	cout << "0. __SALIR__" << endl;
	
	cout << "\nOpcion: ";
	cin >> opcion;
	system ("clear");
}

void pedir_operandos(Rational& R1, Rational& R2) {
	cout << "Operando A: ";
	cin >> R1;
	cout << "\nOperando B: ";
	cin >> R2;
	system ("clear");
}

void pause() {
	char pause;
	cout << "Pulsa una 'letra' + 'enter' para continuar...\n";
	cin >> pause;
	system("clear");
}
