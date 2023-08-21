#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		~ScalarConverter();

		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
};

#endif

