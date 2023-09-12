#include "..\inc\Matrix.hh"
#include <string>
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Matrix, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<std::vector<double>>& m): matrix{m}
{
}

Matrix::~Matrix()
{
}

int Matrix::size() const
{
	return this->matrix.size();
}

void Matrix::PrintMatrix() const
{
	for (std::vector<double> vector : matrix)
	{
		for (double element : vector) {
			std::cout << " | " << element;
		}
		std::cout << " | " << std::endl;
	}
}

void Matrix::Transposition()
{
}

std::vector<std::vector<double>>& Matrix::GetMatrix()
{
	return this->matrix;
}

Matrix Matrix::operator*(const Matrix & other) const
{
	//Probowalem zrobic algorytm Strassena, ale mi nie wychodzilo
	//wiec postanowilem zrobic zwyklym sposobem
	const int msr1 = this->matrix.size();
	const int msc2 = other.matrix[0].size();
	const int msc1 = this->matrix[0].size();
	//Szczerze mowiac, lepiej sie czuje z std::vector niz zwyklymi 2D array
	std::vector<double> vec(0,msr1);
	std::vector < std::vector<double> > temp(msc2,vec);
	if (msr1 == msc2)
	{
		for (int i = 0; i < msr1; ++i)
		{
			for(int j = 0; j< msc2;++j)
			{
				for (int k = 0; k < msc1; ++k)
				{
					temp[i][j] += (*this)[i][k] * other[k][j];
				}
			}
		}
	}
	else std::cerr << "Wrong Matrix sizes" << std::endl;
	return Matrix(temp);
}

Matrix Matrix::operator*(const double other) const
{
	std::vector<double> vec;
	std::vector < std::vector<double> > temp;
	for (auto vec : this->matrix)
	{
		for (double el : vec)
		{
			vec.emplace_back(el*other);
		}
		temp.emplace_back(vec);
		vec.clear();
	}
	return Matrix(temp);
}

std::vector<double> Matrix::operator[](const int index) const
{
	try {
		return (this->matrix).at(index);
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		return (this->matrix).at(0);
	}
}

std::vector<double>& Matrix::operator[](const int index)
{
	try {
		return (this->matrix).at(index);
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		return (this->matrix).at(0);
	}
}

std::istream & operator>>(std::istream& stream, Matrix& matrix)
{	//funkcja przetestowana, dziala bez zarzutow
	std::vector<double> temp(0); //tymczasowy wektor do ulatwienia pracy
	std::string element; // potrzebne do pobrania danych
	int vecsize = 0;
	bool pass = 0;
	std::cout << "Starting input, enter \"=\" to input last element in row, enter \"stop\" to stop" << std::endl;
	while (true) {	//potrzeba 2 loopy rzeby wypelnic 2D tablice (tutaj vectory)
		while (true)
		{
			std::cout << "Input element: ";
			stream >> element;
			if ("stop" == element) break;
			if ("=" == element) {	// = sluzy za loop breaker
				std::cout << "Input last element: ";
				stream >> element;
				try {//stod moze wyrzucic exception kiedy jego argument nie jest przerabialny na double
					temp.emplace_back(stod(element));
				}//wiec trzeba go zlapac
				catch (std::invalid_argument& e) { std::cout << std::endl << e.what() << std::endl; }
				std::cout << std::endl;
				break;
			}
			try{
			temp.emplace_back(stod(element));
			}
			catch (std::invalid_argument& e) { std::cerr << std::endl << e.what() << std::endl; }
			std::cout << std::endl;
		}
		if (pass == false) { //ten caly kawalek odpowiada za sprawdzanie rozmiaru macierzy
			vecsize = temp.size(); pass = true;
		}
		if (temp.size() != vecsize) 
		{
			if ("stop" == element) break;
			std::cerr << "Wrong vector size, try again" << std::endl;
			temp.clear();
			continue;
		} //tu sie konczy sprawdzanie rozmiaru
		matrix.matrix.emplace_back(temp); //wrzucam vektor do macierzy
		temp.clear(); //czyszcze wektor do pozniejszego uzytku
		if ("stop" == element) break;
	}
	if (matrix.size() != matrix[0].size() - 1) //sprawdza czy macierz jest kwadratowa
	{
		std::cerr << "Matrix isnt a square matrix, erasing..." << std::endl;
		matrix.matrix.clear();
	}
	return stream;
}

std::ostream & operator<<(std::ostream& stream, const Matrix& matrix)
{
	for (std::vector<double> vector : matrix.matrix)
	{
		stream << " |";
		for (double element : vector) {
			stream << " " << element;
		}
		stream << " | " << std::endl;;
	}
	return stream;
}
