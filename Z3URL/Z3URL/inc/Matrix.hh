#pragma once

#include "Size.hh"
#include <iostream>
#include <vector>

/*
	Klasa zawiera 2D array zrobiona z std::vector
	w ten sposob mozna ja dynamicznie zwiekszac
	i nie potrzebny jest znany rozmiar w trakcie deklaracji.
	Wszystkie metody klasy sluza do obslugi tej macierzy.
 */
class Matrix
{
private:
	std::vector<std::vector<double>> matrix;
public:
	Matrix();
	Matrix(std::vector<std::vector<double>>& m);
	~Matrix();
	int size() const;
	void PrintMatrix() const;
	void Transposition();
	std::vector<std::vector<double>>& GetMatrix();
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(const double other) const;
	std::vector<double> operator[](const int index) const;
	std::vector<double>& operator[](const int index);
	//Matrix operator!();
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& stream, Matrix& matrix);
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

/*Pobiera dane z klawiatury i wrzuca je do wektora, ktory potem jest
wrzucony do macierzy*/
std::istream& operator>>(std::istream& stream, Matrix& matrix);
//Wypisuje macierz w for loop, nic ciekawego
std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);