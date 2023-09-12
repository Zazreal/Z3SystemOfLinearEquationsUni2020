#include <iostream>
#include "..\inc\Vector.hh"
#include "..\inc\Matrix.hh"
#include "..\inc\SystemOfLinearEquations.hh"


int main()
{
  char getchar;

  std::cout << std::endl
	  << " Program start " << std::endl
	  << std::endl;
  Matrix test;
  std::cin >> test;
  std::cout << test << std::endl;
  SystemOfLinearEquations SOLE(test);
  SOLE.Gauss();
  std::cout << SOLE;
  std::cout << SOLE.Result();
  std::cin >> getchar;
}
