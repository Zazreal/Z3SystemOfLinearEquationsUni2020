#pragma once

#include "Size.hh"
#include <iostream>
#include <vector>
/*
	Klasa Vector zawiera std::vector
	dzieki czemu nie potrzebny jest znany rozmiar.
	Wszystkie metody klasy sluza do jego obslugi.
 */
class Vector
{
private:
	std::vector<double> vector;
public:
	Vector();
	Vector(std::vector<double>& vec);
	~Vector();
	void SetVector(std::vector<double>& vector);
	friend std::istream & operator>>(std::istream& stream, Vector& vec);
	friend std::ostream &operator<<(std::ostream& stream, const Vector& vec);
	Vector operator=(const std::vector<double>& other);
	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator-();
	Vector operator*(const Vector& other) const;
	Vector operator*(const double multiplier) const;
	Vector operator/(const double divider) const;
	double operator[](const int index) const;
	double& operator[](const int index);

};

//Pobiera double az uzytkownik napisze stop
std::istream &operator>>(std::istream& stream, Vector& vec);

//wypisuje Vector.vector na std::cout
std::ostream &operator<<(std::ostream& stream, const Vector& vec);
