#pragma once

#include <iostream>
#include <vector>
#include "Matrix.hh"
#include "Vector.hh"

/*
	Ta klasa zawiera funkcje sluzace do rozwiazywania rownan
	jak i macierz rownan orac wektor wynikow.
 */
class SystemOfLinearEquations
{
private:
	Matrix Mmatrix;
	Vector result;
public:
	SystemOfLinearEquations();
	inline SystemOfLinearEquations(Matrix mat) : Mmatrix{ mat } {};
	void MatrixInput(Matrix mat);
	void Gauss();//std::vector < std::vector<double>> matrix);
	Vector Result() const; //wyswietla wynik dzialania
	//Teraz wyswietla jak w rozszerzeniu
	friend std::ostream &operator<<(std::ostream &stream, const SystemOfLinearEquations &system);
	//Pobiera macierz rownan od uzytkownika
	friend std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system);
};
