#include "./Rational.hpp"

//-----AUXILIARES----------------------------------------
int mcd(const int num1, const int num2) {
	int mcd = 0;
	int a = max(num1, num2);
	int b = min(num1, num2);
	
	do {
		mcd = b;
		b = a % b;
		a = mcd;
	} while (b != 0);

	return mcd;
}

int mcm(const int num1, const int num2) {
	int a = max(num1, num2);
	int b = min(num1, num2);
	return (a / mcd(a,b)) * b;
}

Rational& simplificar(Rational& R) {
	try {
		if (R.getDen() != 0) {
			if (R.getNum() != 0) {
				const int MCD = mcd(abs(R.getNum()), abs(R.getDen()));
				R.setNum(R.getNum() / MCD);
				R.setDen(R.getDen() / MCD);
			} else {
				R.setNum(0);
				R.setDen(1);
			}
		} else {
			throw 0;
		}
	} catch (int x) {
		cerr << "ERROR : El denominador no puede ser '0'.\n";
	}
	return R;
}

//-----CONSTRUCTORES-------------------------------------
Rational::Rational() {
	this->numerador   = 0;
	this->denominador = 1;
}

Rational::Rational(const int numerador) {
	this->numerador   = numerador;
	this->denominador = 1;
}

Rational::Rational(const int numerador, const int denominador) {
	try {
		if (numerador != 0 && denominador != 0) {
			int MCD = mcd(abs(numerador), abs(denominador));

			if ((numerador < 0) && (denominador > 0) || (numerador > 0) && (denominador < 0)) {
				this->numerador   = abs(numerador)   / MCD * -1;
				this->denominador = abs(denominador) / MCD;
			} else {
				this->numerador   = abs(numerador)   / MCD;
				this->denominador = abs(denominador) / MCD;
			}
		} else if (numerador == 0 && denominador != 0) {
			this->numerador   = 0;
			this->denominador = 1;
			throw 0;
		} else {
			throw 1;
		}
	} catch (int x) {
		switch (x) {
			case 0: cerr << "Warning : Numerador == 0.\n";  break;
			case 1: cerr << "ERROR : El denominador no puede ser '0'.\n";
					cout << "Made with ❤️  by Hec7or. ©\n";
					exit(0);
					break;
		}
	}
}

//-----DESTRUCTOR----------------------------------------
Rational::~Rational() {}

//-----GATTERS_&_SETTERS---------------------------------
int Rational::getNum() const {
	return this->numerador;
}

int Rational::getDen() const {
	return this->denominador;
}

void Rational::setNum(const int numerador) {
	try {
		if (denominador != 0) {
			this->numerador = numerador;
		} else {
			throw 0;
		}
	} catch(int x) {
		cerr << "Warning : Numerador == 0.\n";
	}
}

void Rational::setDen(const int denominador) {
	try {
		if (denominador != 0) {
			this->denominador = denominador;
		} else {
			throw 0;
		}
	} catch(int x) {
		cerr << "ERROR : El denominador no puede ser '0'.\n";
	}
}

//-----REPRESENTACION_GRAFICA----------------------------
string Rational::print(Rational R) {
	return to_string(R.getNum()) + "/" + to_string(R.getDen());
}

ostream& operator<<(ostream& f, const Rational& R) {
	(R.getDen() == 1) ? (f << to_string(R.getNum())) : f << Rational::print(R);
	return f;
}

istream& operator>>(istream& f, Rational& R) {
	string buffer;
	f >> buffer;

	smatch var;
	regex regExp_Integer("([0-9]+)");
	regex regExp_Racional("([0-9]+)/([0-9]+)");

	try {
		if (regex_match (buffer, var, regExp_Integer)) {
			R.setNum(stoi(var[1].str()));
			R.setDen(1);
		} else if (regex_match(buffer, var, regExp_Racional)) {
			R.setNum(stoi(var[1]));
			R.setDen(stoi(var[2]));
		} else {
			throw 0;
		}
	} catch(int x) {
		cerr << "ERROR : El denominador no puede ser '0'.\n";
		cout << "Made with ❤️  by Hec7or. ©\n";
		exit(0);
	}
	

	return f;
}

//-----ARITMETICA_RACIONAL-------------------------------

//-----OPERADORES_DE_ORDEN-------------------------------

// Devuelve 'TRUE' si (int) == (rational)
// Devuelve 'FALSE' caso contrario
bool operator==(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	return ( (op1.getNum() == op2.getNum()) && (op1.getDen() == op2.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) == (int)
// Devuelve 'FALSE' caso contrario
bool operator==(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	return ( (op1.getNum() == op2.getNum()) && (op1.getDen() == op2.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) == (rational)
// Devuelve 'FALSE' caso contrario
bool operator==(const Rational& op1, const Rational& op2) {
	return ( (op1.getNum() == op2.getNum()) && (op1.getDen() == op2.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (int) < (rational)
// Devuelve 'FALSE' caso contrario
bool operator<(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) < (int)
// Devuelve 'FALSE' caso contrario
bool operator<(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) < (rational)
// Devuelve 'FALSE' caso contrario
bool operator<(const Rational& op1, const Rational& op2) {
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (int) <= (rational)
// Devuelve 'FALSE' caso contrario
bool operator<=(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) <= (int)
// Devuelve 'FALSE' caso contrario
bool operator<=(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) <= (rational)
// Devuelve 'FALSE' caso contrario
bool operator<=(const Rational& op1, const Rational& op2) {
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) < (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (int) > (rational)
// Devuelve 'FALSE' caso contrario
bool operator>(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) > (int)
// Devuelve 'FALSE' caso contrario
bool operator>(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) > (rational)
// Devuelve 'FALSE' caso contrario
bool operator>(const Rational& op1, const Rational& op2) {
	if (op1 == op2) return false;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (int) >= (rational)
// Devuelve 'FALSE' caso contrario
bool operator>=(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) >= (int)
// Devuelve 'FALSE' caso contrario
bool operator>=(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

// Devuelve 'TRUE' si (rational) >= (rational)
// Devuelve 'FALSE' caso contrario
bool operator>=(const Rational& op1, const Rational& op2) {
	if (op1 == op2) return true;
	return ( (op1.getNum() * op2.getDen()) > (op2.getNum() * op1.getDen()) ) ? true : false;
}

//-----OPERADORES_ARITMETICOS----------------------------

// Asigna los valores del entero <I> a <this>
Rational& Rational::operator=(const int num) {
	this->numerador   = num;
	this->denominador = 1;
	return simplificar(*this);
}

// Asigna los valores del racional <R> a <this>
Rational& Rational::operator=(const Rational& R) {
	this->numerador   = R.getNum();
	this->denominador = R.getDen();
	return simplificar(*this);
}

// Devuelve un racional resultante de sumar <int> + <racional> 
// El racional devuelto esta simplificado
Rational operator+(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen() + op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de sumar <racional> + <int>
// El racional devuelto esta simplificado
Rational operator+(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen() + op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de sumar <racional> + <racional>
// El racional devuelto esta simplificado
Rational operator+(const Rational& op1, const Rational& op2) {
	Rational R = Rational(op1.getNum() * op2.getDen() + op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de restar <int> - <racional> 
// El racional devuelto esta simplificado
Rational operator-(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen() - op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de restar <racional> - <int>
// El racional devuelto esta simplificado
Rational operator-(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen() - op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de restar <racional> - <racional>
// El racional devuelto esta simplificado
Rational operator-(const Rational& op1, const Rational& op2) {
	Rational R = Rational(op1.getNum() * op2.getDen() - op2.getNum() * op1.getDen(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de multiplicar <int> * <racional> 
// El racional devuelto esta simplificado
Rational operator*(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getNum(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de multiplicar <racional> * <int>
// El racional devuelto esta simplificado
Rational operator*(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getNum(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de multiplicar <racional> * <racional>
// El racional devuelto esta simplificado
Rational operator*(const Rational& op1, const Rational& op2) {
	Rational R = Rational(op1.getNum() * op2.getNum(), op1.getDen() * op2.getDen());
	return simplificar(R);
}

// Devuelve un racional resultante de dividir <int> / <racional> 
// El racional devuelto esta simplificado
Rational operator/(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	return simplificar(R);
}

// Devuelve un racional resultante de dividir <racional> / <int>
// El racional devuelto esta simplificado
Rational operator/(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	return simplificar(R);
}

// Devuelve un racional resultante de dividir <racional> / <racional>
// El racional devuelto esta simplificado
Rational operator/(const Rational& op1, const Rational& op2) {
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	return simplificar(R);
}

// Devuelve un entero resultante de hacer el módulo <int> % <racional> 
int operator%(const int num, const Rational& op2) {
	Rational op1 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	int mod = R.getNum() % R.getDen();
	return mod;
}

// Devuelve un entero resultante de hacer el módulo <racional> % <int> 
int operator%(const Rational& op1, const int num) {
	Rational op2 = Rational(num);
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	int mod = R.getNum() % R.getDen();
	return mod;
}

// Devuelve un entero resultante de hacer el módulo <racional> % <racional> 
int operator%(const Rational& op1, const Rational& op2) {
	Rational R   = Rational(op1.getNum() * op2.getDen(), op1.getDen() * op2.getNum());
	int mod = R.getNum() % R.getDen();
	return mod;
}

// Devuelve el inverso de un racional
Rational Rational::inverso() {
	try {
		if (this->getNum() != 0) {
			int AUX = getNum();
			this->setNum(this->getDen());
			this->setDen(AUX);
		} else {
			throw 0;
		}
	} catch(int x) {
		cerr << "ERROR : El denominador no puede ser '0'.\n";
		cout << "Made with ❤️  by Hec7or. ©\n";
		exit(0);
	}
	return *this;
}
