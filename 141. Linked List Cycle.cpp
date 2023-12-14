#include <cerrno>
#include <cfenv>
#include <cmath>
#include <iostream>
// Turn off the warning of Visual C++
#pragma warning(disable : 4996)

int main()
{
	double number = 42.0;
	double squareRoot = std::sqrt(number);

	// error handling from https://en.cppreference.com/w/cpp/numeric/math/sqrt
	errno = 0;
	std::feclearexcept(FE_ALL_EXCEPT);

	std::cout << squareRoot << std::endl;
	if (errno == EDOM)
		std::cout << "    errno = EDOM " << std::strerror(errno) << '\n';
	if (std::fetestexcept(FE_INVALID))
		std::cout << "    FE_INVALID raised\n";
	return 0;
}