# pragma once

# include <iostream>
# include <string>
# include <regex>
# include <exception>
# include <algorithm>
# include <stdlib.h>

using namespace std;

class Rational {
	private:
		//--------------------------------------------------Atributos
		int numerador, denominador;

		//--------------------------------------------------Auxiliares
		friend int mcd(const int num1, const int num2);
		friend int mcm(const int num1, const int num2);
		friend Rational& simplificar(Rational& R);

	public:
		//--------------------------------------------------Constructores
		Rational();
		Rational(const int numerador);
		Rational(const int numerador, const int denominador);

		//--------------------------------------------------Destructor
		~Rational();

		//--------------------------------------------------Getters & Setters
		int getNum() const;
		int getDen() const;
		void setNum(const int numerador);
		void setDen(const int denominador);

		//--------------------------------------------------Mostrar Racional
		static string print(Rational R);

		//--------------------------------------------------Flujos entrada & salida
		friend ostream& operator<<(ostream& f, const Rational& R);
		friend istream& operator>>(istream& f, Rational& R);

		//--------------------------------------------------Aritmetica racional
		//--------------------------------------------------Operadores de equivalencia
		friend bool operator==(const int num, const Rational& op2);
		friend bool operator==(const Rational& op1, const int num);
		friend bool operator==(const Rational& op1, const Rational& op2);

		//--------------------------------------------------Operadores de orden
		friend bool operator<(const int num, const Rational& op2);
		friend bool operator<(const Rational& op1, const int num);
		friend bool operator<(const Rational& op1, const Rational& op2);

		friend bool operator<=(const int num, const Rational& op2);
		friend bool operator<=(const Rational& op1, const int num);
		friend bool operator<=(const Rational& op1, const Rational& op2);

		friend bool operator>(const int num, const Rational& op2);
		friend bool operator>(const Rational& op1, const int num);
		friend bool operator>(const Rational& op1, const Rational& op2);

		friend bool operator>=(const int num, const Rational& op2);
		friend bool operator>=(const Rational& op1, const int num);
		friend bool operator>=(const Rational& op1, const Rational& op2);

		//--------------------------------------------------Operaciones racionales
		Rational& operator=(const int num);
		Rational& operator=(const Rational& R);

		friend Rational operator+(const int num, const Rational& op2);
		friend Rational operator+(const Rational& op1, const int num);
		friend Rational operator+(const Rational& op1, const Rational& op2);

		friend Rational operator-(const int num, const Rational& op2);
		friend Rational operator-(const Rational& op1, const int num);
		friend Rational operator-(const Rational& op1, const Rational& op2);

		friend Rational operator*(const int num, const Rational& op2);
		friend Rational operator*(const Rational& op1, const int num);
		friend Rational operator*(const Rational& op1, const Rational& op2);

		friend Rational operator/(const int num, const Rational& op2);
		friend Rational operator/(const Rational& op1, const int num);
		friend Rational operator/(const Rational& op1, const Rational& op2);

		friend int operator%(const int num, const Rational& op2);
		friend int operator%(const Rational& op1, const int num);
		friend int operator%(const Rational& op1, const Rational& op2);

		Rational inverso();
};
