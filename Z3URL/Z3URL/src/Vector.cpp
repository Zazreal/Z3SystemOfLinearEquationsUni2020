#include "..\inc\Vector.hh"
#include <string>

std::istream & operator>>(std::istream& stream, Vector& vec)
{	//Ta funkcja wypelnia wektor liczbami podanymi od uzytkownika
	std::string temp;
	std::cout << "Inputing Vector, write \"stop\" to end input. " << std::endl;
	while (true)
	{
		stream >> temp;
		if ("stop" == temp) break;
		try {
			vec.vector.emplace_back(stod(temp));
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "Vector input ended" << std::endl;
	return stream;
}

std::ostream & operator<<(std::ostream& stream, const Vector& vec)
{
	for (int i = 0; i < vec.vector.size();i++) {
		std::cout << "| x" << i+1 << " | " << vec.vector[i] << " |" << std::endl;
	}
	return stream;
}

Vector::Vector()
{
	this->vector.emplace_back(0);
}

Vector::Vector(std::vector<double>& vec) : vector{vec}
{
}

Vector::~Vector()
{
}

void Vector::SetVector(std::vector<double>& vector)
{
	this->vector = vector;
}

Vector Vector::operator=(const std::vector<double>& other)
{
	this->vector = other;
	return *this;
}

Vector Vector::operator+(const Vector& other) const
{
	//std::transform(this->vector.begin(), this->vector.end(), other.vector.begin(), this->vector.begin(), std::plus<int>());
	std::vector<double> vec;
	if (this->vector.size() == other.vector.size()) {
		for (int i = 0; i < this->vector.size(); ++i)
		{
			vec.emplace_back(this->vector[i] + other.vector[i]);
		}
	}
	else std::cerr << "You Cant add vectors of diffrent sizes" << std::endl;
	return Vector(vec);
}

Vector Vector::operator-(const Vector& other) const
{
	std::vector<double> vec;
	if (this->vector.size() == other.vector.size()) {
		for (int i = 0; i < this->vector.size(); ++i)
		{
			vec.emplace_back(this->vector[i] - other.vector[i]);
		}
	}
	else std::cerr << "You Cant subtract vectors of diffrent sizes" << std::endl;
	return Vector(vec);
}

Vector Vector::operator-()
{
	for (double element : this->vector)
		element *= (-1);
	return Vector(this->vector);
}

Vector Vector::operator*(const Vector& other) const
{
	std::vector<double> vec;
	if (this->vector.size() == other.vector.size()) {
		for (int i = 0; i < this->vector.size(); ++i)
		{
			vec.emplace_back(this->vector[i] * other.vector[i]);
		}
	}
	return Vector(vec);
}

Vector Vector::operator*(const double multiplier) const
{
	std::vector<double> vec;
	for (double element : this->vector)
		vec.emplace_back(element * multiplier);
	return Vector(vec);
}

Vector Vector::operator/(const double divider) const
{
	std::vector<double> vec;
	for (double element : this->vector)
		vec.emplace_back(element / divider);
	return Vector(vec);
}

double Vector::operator[](const int index) const
{
	try {
		return (this->vector).at(index);
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		return (this->vector).at(0);
	}
}

double& Vector::operator[](const int index)
{
	try {
		return (this->vector).at(index);
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		return (this->vector).at(0);
	}
}
